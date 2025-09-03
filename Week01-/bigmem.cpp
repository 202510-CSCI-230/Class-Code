
#include <iostream>

#define SIZE 1000000000
using namespace std;

int main(){
    //int a[SIZE];
    int* a;
    a = (int*)malloc(sizeof(int) * SIZE);

    cout << "Size: " << SIZE * sizeof(int) / 1024 << " " <<endl;
    cout << "more here" << endl;

    for(unsigned i = 0; i < SIZE; i++){
        a[i] = 0;
    }

    cout << "there" << endl;

    free(a);

}