#include <iostream>

using namespace std;

void printarray(int* s, unsigned len){
    cout << "Dereferenced s: " << *s << endl;
    cout << "Dereferenced s: " << *(s-1) << endl;
    cout << "Size of s: " << sizeof(s) << endl;
    for(int i = 0; i < 100; i++){
        cout << "  " << s[i] << endl;
    }
}

int main(){
    int a = 5;

    cout << "Size of int: " << sizeof(a) << endl;

    string b = "something else,something else,something else,something else,something else,something else";

    cout << "Size of string b: " << sizeof(b) << endl;
    cout << b << endl;

    int c[10] = {45656,4343,3434};
    cout << "Size of c: " << sizeof(c) << endl;
    printarray(c);
}