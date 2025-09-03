/*
    Class example code
    CSCI 230
    Fall 2025
    Sept 3, 2025
*/

#include <iostream>
using namespace std;

void loop1(int times){
    int counter = 0;
    for(int i = 0; i < times; i++){
        for(int j = 0; j < times; j++){
            for(int k = 0; k < times; k++){
                for(int l = 0; l < 10; l++){
                    cout  << counter << " ";
                    counter++;
                }
            }
        }
    }
    cout << endl << endl;
}

int main(){
    loop1(1); // Prints 1

    loop1(2); // Prints 4

    loop1(3); // Prints 9
    loop1(4); // Prints 16
    return 0;
} 