import copy
import inspect
import os

INACCESSIBLE_DUE_TO_ITS_PROTECTION_LEVEL_EXCEPTION_MESSAGE = \
    '{class_name}.{class_method_name}() is inaccessible due to its protection level'

class ClassMemberTypes:
    GETTER = 'getter'
    SETTER = 'setter'
    DELETER = 'deleter'
    METHOD = 'method'
    STATIC_METHOD = 'staticmethod'
    CLASS_METHOD = 'classmethod'

class InaccessibleDueToItsProtectionLevelException(Exception):
    def __init__(self, message):
        self.message = message

def does_classes_contain_private_method(classes, method):
    for class_ in classes:
        if hasattr(class_, method.__name__):
            if getattr(class_, method.__name__).__name__ in 'private_wrapper':
                return True, class_

    return False, None

def find_decorated_method(function):
    if isinstance(function, property):
        return function

    if function.__class__.__name__ in (ClassMemberTypes.STATIC_METHOD, ClassMemberTypes.CLASS_METHOD):
        return find_decorated_method(function.__func__)

    if function.__closure__ is not None:
        return find_decorated_method(function.__closure__[0].cell_contents)

    return function

def get_method_class_by_frame(frame):
    latest_object = None

    for name, object_ in frame.f_globals.items():

        try:
            class_method = object_.__dict__.get(frame.f_code.co_name)

            if class_method is not None:
                method = find_decorated_method(function=class_method)

                if method.__code__ is frame.f_code:
                    latest_object = object_

        except (KeyError, AttributeError):
            pass

    return latest_object

def private(func):
    def private_wrapper(*args, **kwargs):
        instance, *arguments_without_instance = args
        instance_class = instance.__class__
        instance_class_parents = instance.__class__.__bases__

        method = find_decorated_method(function=func)

        does_class_contain_private_method, class_that_contains_private_method = \
            does_classes_contain_private_method(classes=instance_class_parents, method=method)

        if does_class_contain_private_method:
            raise InaccessibleDueToItsProtectionLevelException(
                INACCESSIBLE_DUE_TO_ITS_PROTECTION_LEVEL_EXCEPTION_MESSAGE.format(
                    class_name=class_that_contains_private_method.__name__, class_method_name=method.__name__,
                ),
            )

        method_caller_frame = inspect.currentframe().f_back
        method_caller_class = get_method_class_by_frame(frame=method_caller_frame)

        if instance_class is not method_caller_class:
            raise InaccessibleDueToItsProtectionLevelException(
                INACCESSIBLE_DUE_TO_ITS_PROTECTION_LEVEL_EXCEPTION_MESSAGE.format(
                    class_name=instance_class.__name__, class_method_name=method.__name__,
                ),
            )

        if func.__class__.__name__ == ClassMemberTypes.CLASS_METHOD:
            arguments = (instance_class, ) + tuple(arguments_without_instance)
            return func.__func__(*arguments, **kwargs)

        elif func.__class__.__name__ == ClassMemberTypes.STATIC_METHOD:
            return func.__func__(*arguments_without_instance, **kwargs)

        else:
            return func(*args, **kwargs)

    return private_wrapper


class Test:
    def test1(self):
        return "1"

    def test3(self):
        return test2()
        
    @private
    def test2(self):
        return "2"