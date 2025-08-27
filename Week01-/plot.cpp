
#include <iostream>

using namespace std;

void dostuff(unsigned a){
    cout << "I got " << a << endl;    
}

int main(){


    for(int i = 0; i < 1000; i++){
        cout << i << "\t" << i * i << endl;
    }

}