#include <iostream>
#include <pthread.h>

using namespace std;

unsigned long inside;
unsigned long total;

struct thread_t{
    int threadid;
    float cost;
};

void* throw_darts(void* dummy){
    thread_t* args = (thread_t*)dummy;

    unsigned local_inside = 0;
    unsigned long local_total = 0;

    for(int i = 0; i < 100000; i++){
        float x = rand() / (float)RAND_MAX * 2.0 - 1.0;
        //cout << x << endl;
        float y = rand() / (float)RAND_MAX * 2.0 - 1.0;
        //cout << y << endl;

        if( x*x + y*y <= 1.0){
            local_inside++;
        }
        local_total++;
    }
    // Update global

    return NULL;
}

int main(){
    srand(time(0));
    inside = 0;
    total = 0;

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
        pthread_create(&(thread_info[i]), &attr, throw_darts, &(args[i]));
        //pthread_join(thread_info[i], NULL); - DONT DO THIS - SINGLE THREADED
    }
        

    // ALL 11 threads are running (10 plus this main thread)

    for(int i = 0; i < 10; i++){
        pthread_join(thread_info[i], NULL);
    } 
   

    cout << "Inside: " << inside << endl;
    cout << "Total:" << total << endl;
    cout << "pi extimate: " << 4.0 * inside / total << endl;

    return 0;
}