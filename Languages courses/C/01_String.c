#include <stdio.h>
#include <stdlib.h>

char *get_string(int *len) {
    *len = 0; 
    int capacity = 1; // емкость контейнера динамической строки
    char *s = (char*) malloc(sizeof(char));
    char c = getchar(); // символ для чтения данных

    while (c != '\n') {
        s[(*len)++] = c;

        if (*len >= capacity) {
            capacity *= 2; // увеличиваем ёмкость строки
            s = (char*) realloc(s, capacity * sizeof(char)); 
        }
        c = getchar();          
    }

    s[*len] = '\0'; 
    return s; 
}

int main() {
    int len; char *s = get_string(&len);

    printf("You've wrote: '%s', symbols: %d\n", s, len);
    free(s);
    return 0;
}
