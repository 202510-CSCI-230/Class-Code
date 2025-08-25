
#include <iostream>

#define SIZE 1000000
using namespace std;

int main(){
    int a[SIZE];

    cout << "Size: " << SIZE * sizeof(int) / 1024 << " " <<endl;
    cout << "more here" << endl;

    for(unsigned i = 0; i < SIZE; i++){
        a[i] = 0;
    }

}