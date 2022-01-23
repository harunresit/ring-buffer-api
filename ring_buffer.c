#include "ring_buffer.h"
#include <stdlib.h>

static int instanceNumber = 0;

bool ring_buffer_init(struct ring_buffer *me, uint8_t *data, size_t data_size){
    
    if(data_size < 1){
        return false;
    }

    me->head = 0;
    me->tail = 0;
    me->capacity = CAPACITY_OF_BUFFER + 1;
    me->dataSize = data_size;
    me->data = data;                                            //assigned data address to buffer address
    me->data = (uint8_t*)malloc(me->dataSize*me->capacity);
    
    return true;
}

bool ring_buffer_clear(struct ring_buffer *me){
    
    if(me->data){
        free(me->data);
    }

    free(me);

    if(me == NULL){
        return true;
    }else{
        return false;
    }
    
}

bool ring_buffer_is_empty(const struct ring_buffer *me){

    if (me->tail == me->head)
    {
        return true;
    }else{
        return false;
    }
    
}

size_t ring_buffer_get_size(const struct ring_buffer *me){
    size_t size_of_buffer = 0;
    size_of_buffer = (me->tail - me->head);
    return size_of_buffer;
}

size_t ring_buffer_get_max_size(const struct ring_buffer *me){
    return me->capacity;
}

bool ring_buffer_put(struct ring_buffer *me, uint8_t data){
    if(((me->tail)+1) == (me->head))
        return false;                   //buffer is full
    (me->data)[me->tail] = data;
    (me->tail)++;

    if(me->tail > me->capacity)
        me->tail = 0;

    return true;
}

bool ring_buffer_get(struct ring_buffer *me, uint8_t *data){
    if(ring_buffer_is_empty(me))
        return false;
    *data = (uint8_t)(me->data)[me->head];
    (me->head)++;

    if(me->head > me->capacity)
        me->head = 0;

    return true;
}