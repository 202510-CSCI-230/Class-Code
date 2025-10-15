#include <iostream>
#include <pthread.h>

using namespace std;

int count;
void* myprint(void* dummy){
    cout << "Hi this is a thread." << endl;
    for(int i = 0; i < 100000; i++){
        count++;
    }
    return NULL;
}

int main(){
    cout << "Hello world" << endl;
    count = 0;

    pthread_t thread1;
    pthread_t thread2;

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&thread1, &attr, myprint, NULL);    
    pthread_create(&thread2, &attr, myprint, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout << "Count: " << count << endl;

    return 0;
}