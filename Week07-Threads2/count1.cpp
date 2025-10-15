#include <iostream>
#include <pthread.h>

using namespace std;

int count;

struct thread_t{
    int threadid;
    float cost;
};

void* myprint(void* dummy){
    //thread_t* args = (thread_t*)dummy;

    cout << "This got sent: " << ((thread_t*)dummy)->threadid << endl;
    cout << "  cost: " << ((thread_t*)dummy)->cost << endl;
    //cout << "This got sent: " << args->threadid << endl;
    //cout << "  cost: " << args->cost << endl;
    for(int i = 0; i < 100000; i++){
        count++;
    }
    return NULL;
}

int main(){
    cout << "Hello world" << endl;
    count = 0;

    pthread_t thread_info[10];

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    thread_t args[10];
    for(int i = 0; i < 10; i++){
        args[i].threadid = i;
        args[i].cost = i * 2 + 0.99;
    }

    for(int i = 0; i < 10; i++){
        //pthread_create(&thread1, &attr, myprint, args + i);    
        pthread_create(&(thread_info[i]), &attr, myprint, &(args[i]));
        //pthread_join(thread_info[i], NULL); - DONT DO THIS - SINGLE THREADED
    }

    // ALL 11 threads are running (10 plus this main thread)
    
    for(int i = 0; i < 10; i++){
        pthread_join(thread_info[i], NULL);
    }
   

    cout << "Count: " << count << endl;

    return 0;
}