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
    
    int a = 123456;
    printBits(a);

    int key = 9678546;

    int a_incr = a ^ key;

    printBits(a_incr);

    int decrypt = a_incr ^ key;
    printBits(decrypt);
}