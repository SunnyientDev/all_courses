#ifndef C_FSM_FSM_WELDING_H
#define C_FSM_FSM_WELDING_H

#if defined(__cplusplus)
extern "C" {
#endif

enum InputSignal {
    WELDING_ON = 1, //вкл сварка
    WELDING_OFF = 0 //выкл сварка
};

enum AutomateState {
    AUTOMATE_OFF = 0,   //автомат выключен
    AUTOMATE_T_N,       //насыщение
    AUTOMATE_WELDING,   //сварка
    AUTOMATE_T_C,       //спад
    AUTOMATE_COMPLETE,  //завершение сварки
};

//блок для маленьких автоматов
struct Automate{
    enum AutomateState state;

    int time_tick;  //внутренний счётчик
    int time_n;     //время насыщения
    int time_c;     //время спада

    double value;   //значение параметра, задаем в SIT
};

enum AutomateParameter {
    AUTOMATE_I = 0,         //Ток сварки
    AUTOMATE_U,             //Напряжение дуги
    AUTOMATE_V,             //Скорость подачи проволоки
    AUTOMATE_COUNT
};

enum EngineState {
    ENGINE_WELDING_OFF = 0,
    ENGINE_WELDING_GAS_ON,
    ENGINE_WELDING_RUN_AUTOMATE,
    ENGINE_WELDING_RUNNING,
    ENGINE_WELDING_COMPLETE_AUTOMATE,
    ENGINE_WELDING_GAS_STABLE,
    ENGINE_WELDING_GAS_OFF,
    ENGINE_WELDING_COMPLETE
};

// информация об основной автомате
struct Engine {
    enum EngineState state;
    
    int time_tick;  //внутренний счётчик
    int time_n;     //время насыщения, газ
    int time_c;     //время спада, газ
    int time_g;     //время окончательной подачи газа

    struct Automate automate[3]; 
    double value; //расход газа
};

void engine_init(struct Engine *engine);
void engine_tick(struct Engine *engine, enum InputSignal signal);
void engine_reset(struct Engine *engine);

#if defined(__cplusplus)
}
#endif

#endif //C_FSM_FSM_WELDING_H