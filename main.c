#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* print_hello(void* data)
{
    printf("Hello, World!\n");
	(void)data;
    return NULL;
}

int main()
{
    pthread_t thread_id;

    if (pthread_create(&thread_id, NULL, &print_hello, NULL) != 0)
	{
        fprintf(stderr, "Failed to create thread\n");
        return 1;
    }

    pthread_join(thread_id, NULL);

    return 0;
}