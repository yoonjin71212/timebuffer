#include "buffer.h"
//show list
void show(list *lst)
{
    node* t;
    for (t=lst->front->next;t!=lst->rear;t=t->next) { //show all nodes' key
        if(strnlen(t->key,PREFIX)<LST_MAX) {
            printk ("%s\n", (char*)t->key);  //no other data;just the key
        }
    }
}
MODULE_LICENSE("GPL");
