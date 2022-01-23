#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <assert.h>

#include <stdio.h>

#include "ring_buffer.h"


int main(int arc, char *argv[])
{
    /** TODO: Write tests using assert.h */
    // Example - wrong data_size function argument: 
    // assert(ring_buffer_init(&ring, &data, 0) == false); 
    
    struct ring_buffer oval_tampon;     //oval tampon means ring buffer in turkish
    uint8_t data_address;
    uint8_t *data_read;

    assert(ring_buffer_init(&oval_tampon, &data_address, 8) == true);   //data_size is 8 bit      

    assert(ring_buffer_is_empty(&oval_tampon) == true);

    assert(ring_buffer_put(&oval_tampon, 55) == true);

    assert(ring_buffer_put(&oval_tampon, 23) == true);

    assert(ring_buffer_get_size(&oval_tampon) == 2);
    
    assert(ring_buffer_get(&oval_tampon, data_read) == true);

    assert(ring_buffer_get(&oval_tampon, data_read) == true);

    assert(ring_buffer_is_empty(&oval_tampon) == true);

    assert(ring_buffer_get_max_size(&oval_tampon) == 65);

    assert(ring_buffer_clear(&oval_tampon) == true);


    /*
    a = ring_buffer_init(&oval_tampon, &data_address, 8);
    printf("%d\n",a);

    ring_buffer_put(&oval_tampon, 55);
    ring_buffer_put(&oval_tampon, 38);

    a = ring_buffer_get(&oval_tampon, data_read);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",*data_read);

    assert(ring_buffer_clear(&oval_tampon) == true);

    a = ring_buffer_get(&oval_tampon, data_read);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",*data_read);

    a = ring_buffer_get(&oval_tampon, data_read);
    printf("\n");
    printf("%d\n",a);
    printf("%d\n",*data_read);
    */
};
