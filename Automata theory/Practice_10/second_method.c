#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>

#define MAX_SIZE 255

#define NUMBER engine->text[engine->text_it] >= 48 && engine->text[engine->text_it] <= 57
#define SYMBOL (ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) || ((ch >= 97 && ch <= 122)) //0-9 a-f A-F
//#define ch engine->text[engine->text_it]

enum RegexpState {
    STATE_BEGIN, 
    
    STATE_1, STATE_2, STATE_3, STATE_4,
    STATE_5, STATE_6, STATE_7, STATE_8, STATE_9,
    STATE_10, STATE_11, STATE_12, STATE_13, STATE_14,
    STATE_15, STATE_16, STATE_17, STATE_18, STATE_19,
    STATE_20, STATE_21, STATE_22, STATE_23, STATE_24,
    STATE_25, STATE_26, STATE_27, STATE_28, STATE_29,
    STATE_30, STATE_31, STATE_32, STATE_33, STATE_34,
    
    STATE_END, STATE_ERROR
};

// хранение состояний, индекс текущего символа, массив обработки
struct Regexp {
    enum RegexpState state;
    char *text; //массив обрабботки
    size_t text_len; 
    
    int answer_state;
    int counter;
    int text_it; 
};

// инициализация
static void regexp_init(struct Regexp *regexp, char *text) {
    memset(regexp, 0, sizeof(struct Regexp)); // очистка 
    regexp->state = STATE_BEGIN;
    
    regexp->text = strdup(text); // выделение памяти для строки
    regexp->text_len = strlen(text);
    regexp->answer_state = 0;
    regexp->counter = 0;
}

// освобождение памяяти
static void regexp_destroy(struct Regexp *regexp) {
    if (0 != regexp) {
        if (0 != regexp->text) {
            free(regexp->text);
        }
        regexp->text = 0;
        regexp->text_len = 0;
        regexp->text_it = 0;
    }
}

bool regexp_do(struct Regexp *engine, char ch) {
    switch (engine->state) {
        case STATE_BEGIN:
            if (ch == 'f') {
                engine->state = STATE_1;
                engine->answer_state = 0;
            } else if (SYMBOL && ch != 'f') {
                engine->state = STATE_11;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_1:
            if (ch == 'f') {
                engine->state = STATE_2;
                engine->answer_state = 0;
            } else if (SYMBOL && ch != 'f') {
                engine->state = STATE_12;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_2:
            if (ch == 'f') {
                engine->state = STATE_3;
                engine->answer_state = 0;
            } else if (SYMBOL && ch != 'f') {
                engine->state = STATE_13;
                engine->answer_state = 0;
            }else if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_3:
            if (ch == 'f') {
                engine->state = STATE_4;
                engine->answer_state = 0;
            } else if (SYMBOL && ch != 'f') {
                engine->state = STATE_14;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            }else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_4:
            if (ch == ':') {
                engine->state = STATE_5;
                engine->answer_state = 0;
            } else if (NUMBER) {
                engine->state = STATE_10;
                engine->answer_state = 0;
                engine->text_it--;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_5:
            if (ch == '0') {
                engine->state = STATE_6;
                engine->answer_state = 0;
            } else if (NUMBER) {
                engine->state = STATE_10;
                engine->answer_state = 0;
                engine->text_it--;
            } else if (ch == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_6:
            if (ch == '0') {
                engine->state = STATE_7;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_7:
            if (ch == '0') {
                engine->state = STATE_8;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_8:
            if (ch == '0') {
                engine->state = STATE_9;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_9:
            if (ch == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_10:
            if (ch == '2') {
                engine->state = STATE_24;
                engine->answer_state = 0;
            } else if (ch == '1') {
                engine->state = STATE_16;
                engine->answer_state = 0;
            } else if (ch == 48 || (ch >= 51 && ch <= 57)) {
                engine->state = STATE_19;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_11:
            if (SYMBOL) {
                engine->state = STATE_12;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_12:
            if (SYMBOL) {
                engine->state = STATE_13;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_13:
            if (SYMBOL) {
                engine->state = STATE_14;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_14:
            if (ch == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_15:
            if (SYMBOL && engine->counter < 3) {
                engine->state = STATE_11;
                engine->answer_state = 0;
            } else if (ch == ':') {
                engine->state = STATE_10;
                engine->counter = 0;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            engine->counter++;
            break;
        case STATE_16:
            if (NUMBER) {
                engine->state = STATE_17;
                engine->answer_state = 0;
            } else if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_17:
            if (NUMBER) {
                engine->state = STATE_18;
                engine->answer_state = 0;
            } else if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_18:
            if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_19:
            if (NUMBER) {
                engine->state = STATE_20;
                engine->answer_state = 0;
            } else if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_20:
            if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_21:
            if (engine->counter < 2) {
                engine->state = STATE_10;
                engine->answer_state = 0;
                engine->text_it--;
            } else {
                engine->state = STATE_28;
                engine->answer_state = 0;
                engine->text_it--;
            }
            engine->counter++;
            break;
        case STATE_22:
            if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_23:
            if (NUMBER) {
                engine->state = STATE_22;
                engine->answer_state = 0;
            } else if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_24:
            if (ch == '5') {
                engine->state = STATE_26;
                engine->answer_state = 0;
            } else if (ch >= 48 && ch <= 52) {
                engine->state = STATE_23;
                engine->answer_state = 0;
            } else if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else if (ch >= 54 && ch <= 57) {
                engine->state = STATE_25;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_25:
            if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_26:
            if (ch >= 48 && ch <= 53) {
                engine->state = STATE_27;
                engine->answer_state = 0;
            } else if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_27:
            if (ch == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_28:
            if (ch == '2') {
                engine->state = STATE_30;
                engine->answer_state = 1;
            } else if (ch == '1') {
                engine->state = STATE_32;
                engine->answer_state = 1;
            } else if (ch == 48 || (ch >= 51 && ch <= 57)) {
                engine->state = STATE_29;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_29:
            if (NUMBER) {
                engine->state = STATE_END;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_END;
                engine->answer_state = 1;
            }
            break;
        case STATE_END:
            engine->state = STATE_END;
            engine->answer_state = 1;
            break;
        case STATE_30:
            if (ch == '5') {
                engine->state = STATE_33;
                engine->answer_state = 1;
            } else if (ch >= 48 && ch <= 52) {
                engine->state = STATE_31;
                engine->answer_state = 1;
            } else if (ch >= 54 && ch <= 57) {
                engine->state = STATE_END;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_END;
                engine->answer_state = 1;
            }
            break;
        case STATE_31:
            if (NUMBER) {
                engine->state = STATE_END;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_END;
                engine->answer_state = 1;
            }
            break;
        case STATE_32:
            if (NUMBER) {
                engine->state = STATE_34;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_END;
                engine->answer_state = 1;
            }
            break;
        case STATE_33:
            if (ch >= 48 && ch <= 53) {
                engine->state = STATE_END;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_END;
                engine->answer_state = 1;
            }
            break;
        case STATE_34:
            if (NUMBER) {
                engine->state = STATE_END;
                engine->answer_state = 1;
            } else {
                engine->state = STATE_END;
                engine->answer_state = 1;
            }
            break;
        case STATE_ERROR:
          break;
    }   
    return 0;
}


// для тестов
static bool regexp_execute(struct Regexp *regexp) {
    bool running = true;
    bool result = false;
    while (running) {
        regexp_do(regexp, regexp->text[regexp->text_it]);
        regexp->text_it++;
        if (STATE_ERROR == regexp->state) {
            running = false;
        } else if (STATE_END == regexp->state) {
            result = true;
            running = false;
        } else if (regexp->text_it >= regexp->text_len) {
            running = false;
        }
    }
    return result;
}

struct {
    char *text;
    bool result;
} tests[] = {
        {"afea:aac::29.255.63.69",            true},
        {"aa:aa::9.9.6.9",                    true},
        {"ada:add:aab:ffff::9.9.63.49",       true},
        {"ffff:000d:d120:344f::05.02.32.32",  true},
        {"ffff:bca::05.02.32.32",             true},
        {"000f::2.02.1.0",                    true},
        {"fff::23.3.3.4",                     true},
        {"fff::23.3.3.4",                     true},
        {"aa:aa::9.9.6.9",                    true},
        {"aa:aa::9.9.63.9",                   true},
        {"afea:aac::29.253.63.69",            true},
        {"afea:aac::29.253.29.29",            true},
        {"fff::23.3.3.4",                     true},
        {"test",                              false},
};

int main() {
    struct Regexp engine = {STATE_BEGIN, 0, 0, 0};
    int i;
    bool result;

    for (i = 0; i < sizeof(tests) / sizeof(tests[0]); ++i) {
        regexp_init(&engine, tests[i].text);
        result = regexp_execute(&engine);
        fprintf(stdout, "%35s[%4s]: %s\n",
                engine.text, tests[i].result ? "GOOD" : "BAD", result == tests[i].result ? "PROCESSED SUCCESSFULLY" : "PROCESSED WRONG");
        fflush(stdout);
        regexp_destroy(&engine);
    }
    return EXIT_SUCCESS;
}