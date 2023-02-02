#include "buffer.h"
#include <linux/slab.h>
#include <linux/string.h>
void init_list ( list * lst )   // init list
{
    lst -> front = ( node * ) kmalloc( sizeof ( node ), GFP_ATOMIC );  // rear pointer. This is allocated into GFP_ATOMIC
    lst -> rear = ( node * ) kmalloc( sizeof ( node ), GFP_ATOMIC );  // rear pointer. This is allocated into GFP_ATOMIC
    lst -> front -> key = LST_ERR;
    lst -> rear -> key =  LST_ERR;
    reset_list(lst);
}

void reset_list ( list * lst )   // re-init list (reset list)
{
    lst -> front -> next = lst -> rear ; //front is directly connected to rear; but data is not cleaned ...
    lst -> rear -> prev = lst -> front ; //rear is directly connected to front...
    lst -> front -> prev = lst -> rear;  // Implementation as a 
    lst -> rear -> next = lst -> front;  // Ring Buffer
    lst -> size = 0 ; //size reset;now it's zero again.
}
MODULE_LICENSE("GPL");
