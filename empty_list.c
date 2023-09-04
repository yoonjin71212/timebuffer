#include "buffer.h"
#include <linux/slab.h>
// function that empties list.
void empty_list(list* lst)
{
    node* element=lst-> front;// list is first value, that is next of the front node
    if(lst->size==0) {
        return;
    }
    while(element->next!=lst->rear) { // while list is not rear node
        node* new_addr=element->next->next;
        kfree(element->next);          // free the list
        element->next=new_addr;  // go to the next node
        element=element->next;
    }
    lst->front->next=lst->rear ;
    lst->rear->prev=lst->front ;
    lst->size=0 ;
}
void free_list(list* lst)   // freeing the list
{
    empty_list(lst);    // first, clear the list
    kfree(lst->front);// free the list->front
    kfree(lst->rear);// free the list->rear
}
MODULE_LICENSE("GPL");
