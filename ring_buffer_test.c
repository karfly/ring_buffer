#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/errno.h>
#include "ring_buffer.h"

void int_printer(const void * x)
        {
        printf("%d\n", *(int *)x);
        }

int main()
        {
        ring_buffer_t * my_ring_buffer = NULL;

        int ret = 0;
        int tmp = 0, i = 0;
        double load = 0;

        ret = ring_buffer_construct(&my_ring_buffer, sizeof(int));
        printf("Construct: %d\n", ret);

//        ret = ring_buffer_destruct(my_ring_buffer);
//        printf("Destruct: %d\n", ret);

//        pthread_mutex_t lock1;
//        ret = pthread_mutex_init(&lock1, NULL);
//        ret = pthread_mutex_lock(&lock1);
//        printf("ret = %d\n", ret);

        for (i = 0; i < 128; i++)
                {
                ret = ring_buffer_put(my_ring_buffer, &i, &load);
                printf("put #%d, load = %lg, ret = %d\n", i, load, ret);
                }

        ring_buffer_print(my_ring_buffer, int_printer);

        for (i = 0; i < 128; i++)
                {
                ret = ring_buffer_get(my_ring_buffer, &tmp);
                printf("got %d, ret = %d\n", tmp, ret);
                }

        ring_buffer_print(my_ring_buffer, int_printer);

        ret = ring_buffer_destruct(&my_ring_buffer);
        return 0;
        }
