''' 
This code works as simulator.
Main values: brightness, time, date, temperature, humidity.
Users values: message.
'''
import datetime
from datetime import datetime
import random

################################## PLANT SETTINGS ##################################
plant_last_watering_day = "2021-01-12"
plant_watering_range_days = 7
plant_temperature = [20, 25]
plant_light_level = 800

plant_temp_limit = 5
plant_light_limit = 100

################################## SYSTEM SETTINGS ##################################
set_lamp = 0
set_pump = 0

################################## HELPER FUNCTIONS ##################################
def generate_value(value, coef, step, roundation):
    real_coef = random.uniform(coef - step, coef + step)
    current_value = value * real_coef
    return round(current_value, roundation)

def days_between(d1, d2):
    d1 = datetime.strptime(d1, "%Y-%m-%d")
    d2 = datetime.strptime(d2, "%Y-%m-%d")
    return abs((d2 - d1).days)

def switcher(current_state, new_state):
    exit_code = 1
    if current_state == 1 and new_state == 1:
        exit_code = 0
    if current_state == 0 and new_state == 0:
        exit_code = 0
    return exit_code

################################## BEGIN OF STATES ##################################
# 1. Все ок, растение все устраивает. День, светло
def state_normal_day(addition):
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    current_time = now.strftime("%H:%M:%S")

    current_temperature = generate_value(random.randrange(plant_temperature[0], plant_temperature[1], 5), 1.03, 0.007, 3)
    current_brightness = generate_value(900, 1.03, 0.003, 0) # dark - 0-150, light - 1100
    current_humidity = generate_value(25, 1.03, 0.003, 0) # 0 - 100%, 20 - dry
    set_lamp = 0 # lamp is off
    set_pump = 0 # pump is off

    return main(set_lamp, set_pump, current_temperature, current_humidity, current_brightness, addition)

# 2. Слишком темно, не хватает света.
def state_too_dark(addition):
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    current_time = now.strftime("%H:%M:%S")

    current_temperature = generate_value(random.randrange(plant_temperature[0], plant_temperature[1], 5), 1.03, 0.007, 3)
    current_brightness = generate_value(100, 1.03, 0.003, 0) # dark - 0, light - 1100
    current_humidity = generate_value(34, 1.03, 0.003, 0) # 0 - 100, 20 - dry
    set_lamp = 0 # lamp is off
    set_pump = 0 # pump is off

    return main(set_lamp, set_pump, current_temperature, current_humidity, current_brightness, addition)

# 3. Холодно, нужны действия от пользователя.
def state_too_cold(addition):
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    current_time = now.strftime("%H:%M:%S")

    current_temperature = generate_value(10, 1.03, 0.007, 3)
    current_brightness = generate_value(100, 1.03, 0.003, 0) # dark - 0, light - 1100
    current_humidity = generate_value(45, 1.03, 0.003, 0) # 0 - 100, 20 - dry
    set_lamp = 0 # lamp is off
    set_pump = 0 # pump is off

    return main(set_lamp, set_pump, current_temperature, current_humidity, current_brightness, addition)

################################## END OF STATES ##################################

def check_state(current_temperature, current_brightness, current_humidity):
    ans = 1
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    
    if current_brightness < (plant_light_level - plant_light_limit) or current_brightness > (plant_light_level + plant_light_limit):
        ans *= 0
    if days_between(plant_last_watering_day, current_date) >= plant_watering_range_days or current_humidity < 20:
        ans *= 0
    if current_temperature < (plant_temperature[0] - plant_temp_limit) or current_temperature > (plant_temperature[1] + plant_temp_limit):
        ans *= 0
    return ans

def main(lamp_state, pump_state, current_temperature, current_humidity, current_brightness, addition):
    phrase = ""
    now = datetime.now()
    current_date = now.strftime("%Y-%m-%d")
    current_time = now.strftime("%H:%M:%S")
    
    if(check_state(current_temperature, current_brightness, current_humidity) == 0):
        # temperature
        if current_temperature < plant_temperature[0]:
            print("It's too cold for your plant, replace it.")
        elif current_temperature > plant_temperature[1]:
            print("It's too hot for your plant, replace it.")

        # lighting
        if current_brightness < plant_light_level and lamp_state == 0:
            if switcher(lamp_state, 1) != 0:
                lamp_state = 1
                print("Admin: Lamp is working")
            else:
                print("Error: Lamp is not active")
        
        # watering
        if days_between(plant_last_watering_day, current_date) >= plant_watering_range_days or current_humidity < 20:
            if switcher(pump_state, 1) != 0:
                pump_state = 1
                print("Admin: Pump is working")
                #plant_last_watering_day = current_date
            else:
                print("Error: Pump is not active")
    else: 
        phrase = "Your plant is OK. Enjoy your day! =)"

    if(addition == True):
        print("Current values\n\nBrightness: {0}\nTime: {1}\nDate: {2}\nTemperature: {3}\nHumidity: {4}\n".format(current_brightness, current_time, current_date, current_temperature, current_humidity))
    return phrase

state_too_dark(True)