#include <iostream>
#include <pthread.h>

using namespace std;

int count;
void* myprint(void* dummy){
    cout << "This got sent: " << *((int*)dummy) << endl;
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

    int args[10];
    for(int i = 0; i < 10; i++){
        args[i] = i + 100;
    }

    for(int i = 0; i < 10; i++){
        //pthread_create(&thread1, &attr, myprint, args + i);    
        pthread_create(&thread1, &attr, myprint, &(args[i]));
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    cout << "Count: " << count << endl;

    return 0;
}