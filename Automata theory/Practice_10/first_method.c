#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>
#include <string.h>

#define MAX_SIZE 255

#define NUMBER engine->text[engine->text_it] >= 48 && engine->text[engine->text_it] <= 57
#define SYMBOL (NEXT_SYMBOL >= 48 && NEXT_SYMBOL <= 57) || (NEXT_SYMBOL >= 65 && NEXT_SYMBOL <= 90) || ((NEXT_SYMBOL >= 97 && NEXT_SYMBOL <= 122)) //0-9 a-f A-F
#define NEXT_SYMBOL engine->text[engine->text_it]

enum RegexpState {
    STATE_BEGIN, 
    
    STATE_1, STATE_2, STATE_3, STATE_4,
    STATE_5, STATE_6, STATE_7, STATE_8, STATE_9,
    STATE_10, STATE_11, STATE_12, STATE_13, STATE_14,
    STATE_15, STATE_16, STATE_17, STATE_18, STATE_19,
    STATE_20, STATE_21, STATE_22, STATE_23, STATE_24,
    STATE_25, STATE_26, STATE_27, STATE_28, STATE_29,
    STATE_30, STATE_31, STATE_32, STATE_33, STATE_34,
    
    STATE_END
};

struct Regexp {
    enum RegexpState state;
    char text[MAX_SIZE];
    
    int answer_state;
    int counter;
    int text_it;
};

static void regexp_init(struct Regexp *regexp) {
    memset(regexp, 0, sizeof(struct Regexp));
    regexp->state = STATE_BEGIN;
    
    regexp->text_it = 0;
    regexp->answer_state = 0;
    regexp->counter = 0;
}

bool regexp_do(struct Regexp *engine) {
    switch (engine->state) {
        case STATE_BEGIN:
            if (NEXT_SYMBOL == 'f') {
                engine->state = STATE_1;
                engine->answer_state = 0;
            } else if (SYMBOL && NEXT_SYMBOL != 'f') {
                engine->state = STATE_11;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_1:
            if (NEXT_SYMBOL == 'f') {
                engine->state = STATE_2;
                engine->answer_state = 0;
            } else if (SYMBOL && NEXT_SYMBOL != 'f') {
                engine->state = STATE_12;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_2:
            if (NEXT_SYMBOL == 'f') {
                engine->state = STATE_3;
                engine->answer_state = 0;
            } else if (SYMBOL && NEXT_SYMBOL != 'f') {
                engine->state = STATE_13;
                engine->answer_state = 0;
            }else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_3:
            if (NEXT_SYMBOL == 'f') {
                engine->state = STATE_4;
                engine->answer_state = 0;
            } else if (SYMBOL && NEXT_SYMBOL != 'f') {
                engine->state = STATE_14;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            }else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_4:
            if (NEXT_SYMBOL == ':') {
                engine->state = STATE_5;
                engine->answer_state = 0;
            } else if(NUMBER) { //exist
                engine->state = STATE_10;
                engine->answer_state = 0;
                engine->text_it--;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_5:
            if (NEXT_SYMBOL == '0') {
                engine->state = STATE_6;
                engine->answer_state = 0;
            } else if (NUMBER) {
                engine->state = STATE_10;
                engine->answer_state = 0;
                engine->text_it--;
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_6:
            if (NEXT_SYMBOL == '0') {
                engine->state = STATE_7;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_7:
            if (NEXT_SYMBOL == '0') {
                engine->state = STATE_8;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_8:
            if (NEXT_SYMBOL == '0') {
                engine->state = STATE_9;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_9:
            if (NEXT_SYMBOL == ':') {
                engine->state = STATE_10;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_10:
            if (NEXT_SYMBOL == '2') {
                engine->state = STATE_24;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == '1') {
                engine->state = STATE_16;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == 48 || (NEXT_SYMBOL >= 51 && NEXT_SYMBOL <= 57)) {
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
            } else if (NEXT_SYMBOL == ':') {
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
            } else if (NEXT_SYMBOL == ':') {
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
            } else if (NEXT_SYMBOL == ':') {
                engine->state = STATE_15;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_14:
            if (NEXT_SYMBOL == ':') {
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
            } else if (NEXT_SYMBOL == ':') {
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
            } else if (NEXT_SYMBOL == '.') {
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
            } else if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_18:
            if (NEXT_SYMBOL == '.') {
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
            } else if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_20:
            if (NEXT_SYMBOL == '.') {
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
            if (NEXT_SYMBOL == '.') {
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
            } else if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_24:
            if (NEXT_SYMBOL == '5') {
                engine->state = STATE_26;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL >= 48 && NEXT_SYMBOL <= 52) {
                engine->state = STATE_23;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL >= 54 && NEXT_SYMBOL <= 57) {
                engine->state = STATE_25;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_25:
            if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_26:
            if (NEXT_SYMBOL >= 48 && NEXT_SYMBOL <= 53) {
                engine->state = STATE_27;
                engine->answer_state = 0;
            } else if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_27:
            if (NEXT_SYMBOL == '.') {
                engine->state = STATE_21;
                engine->answer_state = 0;
            } else {
                engine->state = STATE_BEGIN;
                engine->answer_state = 0;
            }
            break;
        case STATE_28:
            if (NEXT_SYMBOL == '2') {
                engine->state = STATE_30;
                engine->answer_state = 1;
            } else if (NEXT_SYMBOL == '1') {
                engine->state = STATE_32;
                engine->answer_state = 1;
            } else if (NEXT_SYMBOL == 48 || (NEXT_SYMBOL >= 51 && NEXT_SYMBOL <= 57)) {
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
            if (NEXT_SYMBOL == '5') {
                engine->state = STATE_33;
                engine->answer_state = 1;
            } else if (NEXT_SYMBOL >= 48 && NEXT_SYMBOL <= 52) {
                engine->state = STATE_31;
                engine->answer_state = 1;
            } else if (NEXT_SYMBOL >= 54 && NEXT_SYMBOL <= 57) {
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
            if (NEXT_SYMBOL >= 48 && NEXT_SYMBOL <= 53) {
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
    }
    engine->text_it++;
    return false;
}

int main() {
    struct Regexp engine;
    regexp_init(&engine);
    
    printf("Enter string: ");
    scanf("%s", engine.text);
    
    //we adding the checking point with MAX_SIZE for solving problem with wrong string 
    // (not for our regexp)
    while(engine.answer_state != 1 && engine.text_it != MAX_SIZE ) regexp_do(&engine);
    
    if(engine.answer_state == 1) printf("This string is right");
      else printf("This string is wrong");
    return 0;
}