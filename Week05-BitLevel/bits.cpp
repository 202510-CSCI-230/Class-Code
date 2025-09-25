#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

template <typename myType>
void printBits(myType a){
    char* data = (char*)malloc(sizeof(myType));
    memcpy(data, &a, sizeof(a));

    string ret = "";
    for(unsigned i = 0; i < sizeof(a); i++){
        ret = " " + ret;
        for(unsigned j = 0; j < 8; j++){
            if(data[i] & 1){
                ret = "1" + ret;
            }else{
                ret = "0" + ret;
            }
            data[i] = data[i] >> 1;
        }
    }
    cout << a << " is " << sizeof(myType) << " bytes -> " << ret << endl;
}

int main(){
    
    /*short int a = -5;
    printBits(a);

    a = a << 1;
    printBits(a);

    a = a >> 2;

    printBits(a);
    */
    int a = -12; // 10101010

    printBits(a);

     short b = a & 0xffff; // Bitwise and

    printBits(b);

    short c = b & 0x7fff;

    printBits(c);

    short d = c | 0x0f0f;

    printBits(d);

    short e = ^c;

    printBits(e);
}