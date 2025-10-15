
#include <iostream>
#include <sys/time.h>

#define SIZE 10000

using namespace std;

int arr[SIZE];

void dostuff(int a){
    int temp = 0;
    for(int i = 0; i < a; i++){
        arr[i] = i*2;
    }   
}

void dostuff_div(int a){
    int temp = 0;
    for(int i = 0; i < a/2; i = i + 2){
        arr[i] = i*2;
        arr[i+1] = i*2 + 2;
    }    
}

int main(){

    struct timeval start, middle, stop;

    for(unsigned i = 0; i < SIZE; i = i + 2){
        gettimeofday(&start, NULL); // Get the time here

        dostuff(i);

        gettimeofday(&middle, NULL); // Get the time here

        dostuff_div(i);

        gettimeofday(&stop, NULL); // Get the time here

        //long elapsed = (stop.tv_sec - start.tv_sec) * 1000000 + (stop.tv_usec - start.tv_usec); // microseconds
        long add_elapsed = (middle.tv_sec - start.tv_sec) * 1000000 + (middle.tv_usec - start.tv_usec); // microseconds
        long div_elapsed = (stop.tv_sec - middle.tv_sec) * 1000000 + (stop.tv_usec - middle.tv_usec); // microseconds

        cout << i << "\t" << add_elapsed << "\t" << div_elapsed << endl;
    }

}