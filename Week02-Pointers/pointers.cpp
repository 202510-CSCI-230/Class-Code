/*
    Class example code
    CSCI 230
    Fall 2025
    Sept 3, 2025
*/
#include <iostream>

using namespace std;

void fun(int* a){
    *a = 50;
}

int main(){
    int a = 5;
    int b = 6;

    int* c = &a;
    float* another;

    cout << "a: " << a << " b: " << b << " c: " << *c << endl;

    *c = 99;

    cout << "a: " << a << " b: " << b << " c: " << *c << endl;

    c = &b;
    *c = 101;
    cout << "a: " << a << " b: " << b << " c: " << *c << endl;

    fun(&a);

    cout << "a: " << a << " b: " << b << " c: " << *c << endl;
}