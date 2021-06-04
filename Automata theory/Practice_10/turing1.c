#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define STATE engine->state
#define SYMBOL engine->number[engine->number_it]

enum TuringState {
    STATE_Q_T, //terminal
    STATE_Q_1, STATE_Q_2
};

struct Turing {
    enum TuringState state;
    char* number;
    int number_it;
};

void Turing_init(struct Turing* engine, char* number, int number_it) {
    STATE = STATE_Q_1;
    engine->number = number;
    engine->number_it = number_it;
}

bool Turing_do(struct Turing* engine) {
    bool answer_state = true;
    switch (STATE) {
        case STATE_Q_T: {
            answer_state = false;
            break;
        }
        case STATE_Q_1: {
            if (SYMBOL >= '0' && SYMBOL <= '8') {
                SYMBOL += 1;
                STATE = STATE_Q_T;
            }
            else if (SYMBOL == '9') {
                SYMBOL -= 9;
                engine->number_it--;
                STATE = STATE_Q_2;
            }
            break;
        }
        case STATE_Q_2: {
            if (SYMBOL >= '0' && SYMBOL <= '8') {
                SYMBOL += 1;
                STATE = STATE_Q_T;
            }
            else if (SYMBOL == '9') {
                SYMBOL -= 9;
                engine->number_it--;
                STATE = STATE_Q_2;
            }
            else if (SYMBOL == '_') {
                SYMBOL = 49;
                STATE = STATE_Q_T;
            }
            break;
        }
    }
    return answer_state;
}

int main() {
    char next_digit;
    int size = 1;

    char* number = malloc(sizeof(char));
    printf("The number is equal to n = ");
    number[0] = '_';
    while ((next_digit = (char)getchar()) != '\n') {
        //Reallocates the given area of memory
        number = realloc(number, sizeof(char) + (++size * sizeof(char))); 
        number[size - 1] = next_digit;
    }

    int rank = size - 1;
    while (number[rank] == '_') rank--;

    struct Turing subtraction_machine;
    Turing_init(&subtraction_machine, number, rank);
    while(Turing_do(&subtraction_machine) == true);
    
    printf("n + 1 = ");
    if(subtraction_machine.number[0] != '_') 
      for (int j = 0; j < size; j++) printf("%c", subtraction_machine.number[j]);
    else 
      for (int j = 1; j < size; j++) printf("%c", subtraction_machine.number[j]);
    return 0;
}