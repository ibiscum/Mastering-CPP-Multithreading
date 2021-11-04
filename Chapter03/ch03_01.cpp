#include <pthread.h> 
#include <cstdlib>
#include <iostream>
  
#define NUM_THREADS 5

static pthread_mutex_t func_mutex = PTHREAD_MUTEX_INITIALIZER;
 
void func()
{
	pthread_mutex_lock(&func_mutex);
 
    std::cout << "in func()" << std::endl;
 
    pthread_mutex_unlock(&func_mutex); 
} 

void* worker(void* arg)
{
    int value = *((int*) arg); 
  
    std::cout << "in worker()" << std::endl;
  
    return 0; 
} 

int main(int argc, char** argv) { 
    pthread_t threads[NUM_THREADS]; 
    int thread_args[NUM_THREADS]; 
    int result_code; 
    
    for (unsigned int i = 0; i < NUM_THREADS; ++i)
	{
        thread_args[i] = i; 
        result_code = pthread_create(&threads[i], 0, worker, (void*) &thread_args[i]);
		std::cout << "create: " << i << std::endl;
    }

	int j = 0;
	for (unsigned long thread : threads)
	{
        result_code = pthread_join(thread, 0);
		std::cout << "join: " << j++ << std::endl;
	}

    return 0;
}