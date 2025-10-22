#include <iostream>
#include <pthread.h>
#include <cstdint>

#define THREADS 10

using namespace std;

unsigned long inside;
unsigned long total;
pthread_mutex_t lock;

struct thread_t{
    int threadid;
    float cost;
};


uint64_t lehmer64(__uint128_t &g_lehmer64_state) {
  g_lehmer64_state *= 0xda942042e4dd58b5;
  return g_lehmer64_state >> 64;
}

void* throw_darts(void* dummy){
    thread_t* args = (thread_t*)dummy;

    __uint128_t state = args->threadid + 1;
    //cout << args->threadid << endl;

    unsigned local_inside = 0;
    unsigned long local_total = 0;

    for(unsigned long i = 0; i < 1000000; i++){
        float x = lehmer64(state) / (float)0xffffffffffffffff * 2.0 - 1.0;
        //float x = rand() / (float)RAND_MAX * 2.0 - 1.0;
        //cout << x << endl;
        float y = lehmer64(state) / (float)0xffffffffffffffff * 2.0 - 1.0;
        //float y = rand() / (float)RAND_MAX * 2.0 - 1.0;
        //cout << y << endl;

        if( x*x + y*y <= 1.0){
            local_inside++;
        }
        local_total++;
    }
    // Update global
    pthread_mutex_lock(&lock);
    inside = inside + local_inside;
    total = total + local_total;
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main(){
    srand(time(0));
    inside = 0;
    total = 0;

    pthread_mutex_init(&lock, NULL);

    pthread_t thread_info[THREADS];

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    thread_t args[THREADS];
    for(int i = 0; i < THREADS; i++){
        args[i].threadid = i;
        args[i].cost = i * 2 + 0.99;
    }

    for(int i = 0; i < THREADS; i++){
        //pthread_create(&thread1, &attr, myprint, args + i);    
        pthread_create(&(thread_info[i]), &attr, throw_darts, &(args[i]));
        //pthread_join(thread_info[i], NULL); - DONT DO THIS - SINGLE THREADED
    }
        

    // ALL 11 threads are running (10 plus this main thread)

    for(int i = 0; i < THREADS; i++){
        pthread_join(thread_info[i], NULL);
    } 
   

    cout << "Inside: " << inside << endl;
    cout << "Total:" << total << endl;
    cout << "pi extimate: " << 4.0 * inside / total << endl;

    return 0;
}