#include <iostream>
#include <string>
#include <vector>

int main(){
    int current_number;
    int steps = 0, acc = 1000000; 
    float sum = 0;
    int a[6] = {1, 2, 3, 4, 5, 6};
    
    for(int j = 0; j < acc; j++){
        for(int i = 0; i < 6; i++){
            current_number = rand() % 6 + 1; steps += 1;
            while(current_number != a[i]){
                steps++;
                current_number = rand() % 6 + 1;
            }
        }
        sum += steps;
        steps = 0;
    }
    
    float result = sum/acc;
    std::cout << result;
}
