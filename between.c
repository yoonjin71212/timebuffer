#include "buffer.h"
#include <linux/string.h>
#include <linux/slab.h>
// add number between two nodes
int8_t between( list * lst, char * item, node * b, node * n , uint64_t len , uint64_t t_stamp)
{
    node * element ;
    if ( ( element = ( node * ) kmalloc ( sizeof ( node ), GFP_ATOMIC ) ) == NULL ) {
        return 1 ;
    }
    if ( ( b != n -> prev ) ) { //you can't push your element when extra nodes are in between of two nodes.
        kfree( element ); //So, I will free allocated node...
        return -1;
    } else {
        element -> key = item ; //this is your key.
        element -> t_stamp = t_stamp; // timestamp inserted
        element -> len  = len;
        b -> next = element ; //node b's next node is your newly added node
        element -> prev = b;  //so new node's previous node is b
        element -> next = n ; // new node's next node is node n;
        n -> prev = element ; // node n's previous node is new node.
        lst -> size ++ ;      // new_size=old_size+1
    }
    return 0;
}
int8_t enqueue ( list * lst, const char * item , uint64_t len, uint64_t t_stamp)
{
    if(!t_stamp) {
        t_stamp = ktime_get_real_ns();
    }
    return between ( lst, (char *)item, lst-> rear -> prev ,  lst -> rear , len, t_stamp);
} // alias for enquque
void concat_list ( list * lst, list * lst_target )
{
    node * push_node = kmalloc(sizeof(node),GFP_ATOMIC);
    node * target_node = kmalloc(sizeof(node),GFP_ATOMIC) ;
    node * target_end = kmalloc(sizeof(node),GFP_ATOMIC);
    if((lst_target->size&lst->size)==0) {
        return;
    }
    push_node = lst -> rear -> prev;
    target_node = lst_target -> front -> next;
    target_end  = lst_target -> rear -> prev;
    push_node -> next = target_node;
    target_node -> prev = push_node;
    target_end -> next = lst -> rear;
    lst -> rear -> prev = target_end;
    lst -> size += lst_target->size ;
    reset_list(lst_target);

} // enqueue whole queue
MODULE_LICENSE("GPL");
