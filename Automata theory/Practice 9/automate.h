#ifndef PROJECT_3_AUTOMATE_H
#define PROJECT_3_AUTOMATE_H
#include <stdbool.h>

#if defined(__cplusplus)
extern  "C" {
#endif

// Всего 11 состояний: инициализация, ошибка и основные
enum PneumoState {
    PneumoState_Init = 0,
    PneumoState_1, PneumoState_2, PneumoState_3,
    PneumoState_4, PneumoState_5, PneumoState_6,
    PneumoState_7, PneumoState_8, PneumoState_9,
    PneumoState_FatalException // оповещаем, что есть ошибка, и завершаем работу
};

#define PNEUMO_CYLINDER_SIGNAL_UP   0 //сигнал верхнего положения
#define PNEUMO_CYLINDER_SIGNAL_DOWN 1 //сигнал нижнего положения

// Описание внешнего пневмоцилиндра
struct PneumoCylinder {
    int input_signal[2]; // 1е значение - концевой датчик крайнего положения в выдвинутом состоянии, 
                         // 2е - в задвинутом 
    int output_signal;   // подаем на цилиндр: 0 или 1 (1 - выдвигаем, 0 - задвигаем)
};

#define PNEUMO_CYLINDER_Y1 0
#define PNEUMO_CYLINDER_Y2 1

struct PneumoEngine {
    enum PneumoState state; // текущее состояние автомата
    int timeout;            // время, отсчитываемое в процессе установки стаб. состояния цилиндра
    int delay;              // задержка, ввремя перехода в след. состояние
    int timeouts[PneumoState_FatalException]; //системы в задании
    int delays[PneumoState_FatalException];
    struct PneumoCylinder cylinders[2]; //два пневмоцилиндра, в курсовой будет больше
};

void pneumo_engine_init(struct PneumoEngine *engine);       // инициаллизация автомата - выставление нач. значений
bool pneumo_engine_tick(struct PneumoEngine *engine);       // функция итерации - для симуляции работы. Если false, то что-то не так
void pneumo_engine_destroy(struct PneumoEngine *engine);    // останавливаем автомат

#if defined(__cplusplus)
}
#endif
#endif