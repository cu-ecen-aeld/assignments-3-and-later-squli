#include "threading.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// Optional: use these functions to add debug or error prints to your application
#define DEBUG_LOG(msg,...)
//#define DEBUG_LOG(msg,...) printf("threading: " msg "\n" , ##__VA_ARGS__)
#define ERROR_LOG(msg,...) printf("threading ERROR: " msg "\n" , ##__VA_ARGS__)

void* threadfunc(void* thread_param)
{

    // TODO: wait, obtain mutex, wait, release mutex as described by thread_data structure
    // hint: use a cast like the one below to obtain thread arguments from your parameter
    //struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    
    struct thread_data* thread_func_args = (struct thread_data *) thread_param;
    pthread_mutex_t *mutex = thread_func_args->mutex;
    
    thread_func_args->thread_complete_success = true;
        
    printf("usleep, %d\n", 1000 * thread_func_args->wait_to_obtain_ms);
    usleep(1000 * thread_func_args->wait_to_obtain_ms);
    if (0 != pthread_mutex_lock(mutex)) {
        thread_func_args->thread_complete_success = false;
    }
    usleep(1000 * thread_func_args->wait_to_release_ms);
    printf("usleep, %d\n", 1000 * thread_func_args->wait_to_release_ms);
    if (0 != pthread_mutex_unlock(mutex)) {
        thread_func_args->thread_complete_success = false;    
    }
    
    return thread_param;
}


bool start_thread_obtaining_mutex(pthread_t *thread, pthread_mutex_t *mutex, int wait_to_obtain_ms, int wait_to_release_ms)
{
    /**
     * TODO: allocate memory for thread_data, setup mutex and wait arguments, pass thread_data to created thread
     * using threadfunc() as entry point.
     *
     * return true if successful.
     *
     * See implementation details in threading.h file comment block
     */    
    struct thread_data *p_thread_data = (struct thread_data*)malloc(sizeof(struct thread_data));;
    p_thread_data->wait_to_obtain_ms = wait_to_obtain_ms;
    p_thread_data->wait_to_release_ms = wait_to_release_ms;
    p_thread_data->mutex = mutex;
    
    /*if (pthread_mutex_init(mutex, NULL) != 0)
    {
        printf("\n mutex init failed\n");
        return false;
    }*/
       
    int err = pthread_create(thread, NULL, &threadfunc, p_thread_data);
    printf("pthread_create err=%d\n", err);
    if (err != 0)
    {
	printf("\n mutex init failed\n");
        return false;
    }
    
    //pthread_join(*thread, NULL);
     
    return true;
}

