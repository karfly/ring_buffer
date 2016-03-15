#ifndef RING_BUFFER_RING_BUFFER_H
#define RING_BUFFER_RING_BUFFER_H

#include <stdint.h> // For uint32_t

#define RING_BUFFER_SIZE 1024

typedef enum
        {
        SUCCESS          = 0,
        ERROR            = 1,
        WRONG_ARGUMENTS  = 2,
        } ret_code_t;

typedef struct ring_buffer ring_buffer_t;
typedef void   ring_buffer_elem_t;

ret_code_t ring_buffer_construct(ring_buffer_t ** , uint32_t);
ret_code_t ring_buffer_destruct(ring_buffer_t **);

ret_code_t ring_buffer_put (ring_buffer_t * , const ring_buffer_elem_t *, double *);
ret_code_t ring_buffer_get (ring_buffer_t * , ring_buffer_elem_t * );
ret_code_t ring_buffer_getn(ring_buffer_t * , ring_buffer_elem_t ** , uint32_t, uint32_t *);

ret_code_t ring_buffer_print(ring_buffer_t *, void (*) (const ring_buffer_elem_t *));


#endif //RING_BUFFER_RING_BUFFER_H
