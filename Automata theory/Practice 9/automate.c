#include "automate.h"
#include <stdio.h>
#include <limits.h>

#if defined(PNEUMO_SIMULATE) //если есть макроопределение
#define TIMEOUT_DELTA(timeout)  1
#define DELAY_DELTA(delay)      1
#else
#define TIMEOUT_DELTA(timeout)  ((timeout) * 1000)
#define DELAY_DELTA(delay)      ((delay) * 1000)
#endif

#if defined(PNEUMO_DEBUG) //если существует
static char *state_names[] = {
        "PneumoState_I", "PneumoState_1", "PneumoState_2", "PneumoState_3",
        "PneumoState_4", "PneumoState_5", "PneumoState_6", "PneumoState_7",
        "PneumoState_8", "PneumoState_9", "PneumoState_E",
};
#endif

//функция инициализации
void pneumo_engine_init(struct PneumoEngine *engine) {
    // проврека передачи указателя
    if (engine != 0) {
        // входные и выходные данные 1го пневмоцилиндра
        // изначально он задвинут
        engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;

        // входные и выходные данные 2го пневмоцилиндра
        // изначально он задвинут
        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] = 0;
        engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;

        //Начальное состояние
        engine->state = PneumoState_Init;
        
        //Счетчики задержек и таймаутов занулим
        engine->delay = 0;
        engine->timeout = 0;

        //Устанавливаем максимальное значение для int
        engine->timeouts[PneumoState_Init] = INT_MAX;
        engine->delays[PneumoState_Init] = INT_MAX;

        // Выставляем задержки и таймауты для всех состояний
        engine->timeouts[PneumoState_1] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_1] = DELAY_DELTA(10);

        engine->timeouts[PneumoState_2] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_2] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_3] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_3] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_4] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_4] = DELAY_DELTA(10);

        engine->timeouts[PneumoState_5] = TIMEOUT_DELTA(200);
        engine->delays[PneumoState_5] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_6] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_6] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_7] = TIMEOUT_DELTA(200);
        engine->delays[PneumoState_7] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_8] = TIMEOUT_DELTA(120);
        engine->delays[PneumoState_8] = DELAY_DELTA(60);

        engine->timeouts[PneumoState_9] = TIMEOUT_DELTA(200);
        engine->delays[PneumoState_9] = DELAY_DELTA(10);
    }
}

void pneumo_engine_destroy(struct PneumoEngine *engine) {
    if(engine != 0) {
        // Освобождаем ресурсы, если есть
    }
}

// Проверка условия: счетчик таймаутов превышает эталон для данного состояния
#define TIMEOUT_GE(engine) ( (engine)->timeout > (engine)->timeouts[(engine)->state] )
// Аналогично для задержек
#define DELAY_GE(engine) ( (engine)->delay > (engine)->delays[(engine)->state] )

bool pneumo_engine_tick(struct PneumoEngine *engine) {
    //Проврека ненулевого указателя на автомат
    bool ret = true;
    if (engine == 0)
        return false;

//Если отладка, то выводим все состояние автомата
#if defined(PNEUMO_DEBUG)
    fprintf(stdout, "State: %s, Y1(in): [%d, %d], Y2(in): [%d, %d], Y1(out): [%d], Y2(out): [%d]\n",
            state_names[engine->state],
            engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN],
            engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP],
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN],
            engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP],
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal,
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal
    );
    fflush(stdout);
#endif
    // Описываем переходы из состояние в состояние
    switch (engine->state) {
        //Инициализация и сброс счетчиков
        case PneumoState_Init: {
            engine->state = PneumoState_1;
            engine->delay = 0;
            engine->timeout = 0;
            break;
        }

        //Установка сигнала о том, что цилиндры нужно задвинуть (см. Задание)
        case PneumoState_1: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            
            //Если задвинуты, то сбрасываем счетчик таймаута и проверяем, что время задержки вышло
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN] &&
                engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;

                //Если вышло, то мы устанавливаем состояние 2 и сбрасываем счетчики
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_2;
                    engine->delay = 0;
                }
            
            //Переходим в шестое состояние (по заданию)
            } else if (TIMEOUT_GE(engine)) {
                    engine->state = PneumoState_6;
                    engine->delay = 0;
                    engine->timeout = 0;
                }
                break;
        }

        //Состояние 2: 1 цилиндр выдвигаем
        case PneumoState_2: {
            //Передаем выходной сигнал
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            //Сработал ли дачтик
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0; //сбрасываем счетчик
                //Проверяем задержку
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_3;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        case PneumoState_3: {
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_4;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        case PneumoState_4: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_5;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        case PneumoState_5: {
            engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_6;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        case PneumoState_6: {
           engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
           engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 1;
           if(engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP] &&
              engine->cylinders[PNEUMO_CYLINDER_Y2].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
               engine->timeout = 0;
               if (DELAY_GE(engine)) {
                   engine->state = PneumoState_7;
                   engine->delay = 0;
               }
           } else if(TIMEOUT_GE(engine)) {
               engine->state = PneumoState_FatalException;
               engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
               engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
               engine->delay = 0;
               engine->timeout = 0;
           }
            break;
        }

        case PneumoState_7: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_8;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        case PneumoState_8: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 1;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_UP]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_9;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        case PneumoState_9: {
            engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
            if (engine->cylinders[PNEUMO_CYLINDER_Y1].input_signal[PNEUMO_CYLINDER_SIGNAL_DOWN]) {
                engine->timeout = 0;
                if (DELAY_GE(engine)) {
                    engine->state = PneumoState_1;
                    engine->delay = 0;
                }
            } else if (TIMEOUT_GE(engine)) {
                engine->state = PneumoState_FatalException;
                engine->cylinders[PNEUMO_CYLINDER_Y1].output_signal = 0;
                engine->cylinders[PNEUMO_CYLINDER_Y2].output_signal = 0;
                engine->delay = 0;
                engine->timeout = 0;
            }
            break;
        }

        //Ошибочное состояние
        case PneumoState_FatalException: {
            //Выходное значение выставляем как false
            ret = false;
            break;
        }
    }

    //Инкрементируем счетчики
    engine->timeout++; 
    engine->delay++;
    return ret;
}