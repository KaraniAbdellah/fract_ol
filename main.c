#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>


/*
	phtread_t thread_id: each thread has an id in system
	
	void* function_thread(void *arg): each thread link with function
	
	create thread:
		pthread_create(&thread_id, NULL, &function_thread, args);
		thread_id: is a pointer to thread_id
		NULL: why????
		function_thread: function to be excute in thread
		args: argument pass to function_thread
		
	wait thread finich:
		pthread_join(thread_id, args);
		args: contain what function_thread return
	
	
*/

void *function_thread1(void *str) {
	while(true) {
		printf("%s\n", str);
		sleep(1);
	}
	return NULL;
}

void *function_thread2(void *unsed) {
	while(true) {
		printf("Hello Thread2\n");
		sleep(1);
	}
}


int main(void) {
    
    pthread_t thread_id1; pthread_t thread_id2;
	pthread_create(&thread_id1, NULL, &function_thread1, "hello thread1");
	pthread_create(&thread_id2, NULL, &function_thread2, NULL);
	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
	
	
	
	
    

    return 0;
}

/// read more: http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html







