#include "buffer.h"
#include <linux/string.h>
#include <linux/slab.h>
_Bool comp( ll t_stamp_l, ll t_stamp_r, _Bool is_ascending ) {
    if (is_ascending) {
        return (_Bool)(t_stamp_r-t_stamp_l>=0);
    } else {
        return (_Bool)(t_stamp_l-t_stamp_r>=0);
    }
    /* returns 0, or 1 by its flag */
}
_Bool regen_sorted( list * lst , _Bool is_ascending) {
    node * nd;
    _Bool ret = 0;
    nd = kmalloc (sizeof(node),GFP_KERNEL);
    for (nd = lst -> front -> next;nd!=lst->rear->prev;nd=nd->next) {
        ret=(!comp(nd->t_stamp,nd->next->t_stamp,is_ascending));
        if (ret) {
            break;
        }
    }
    return !ret;
    /*regeneration of its state, for accurate status update*/
}

void sortthree ( list * lst , _Bool is_ascending)
{
    node * front = lst -> front -> next ;
    node * rear = lst -> rear -> prev ;
    node *mid = index_node ( lst, lst->size/2 ) ;
    if(lst->is_sorted) {
        return ;
    }
    if (comp(front->t_stamp , mid->t_stamp,is_ascending) ) {
        swap_int (&front->t_stamp,&mid->t_stamp);
        swap_int (&front->len,&mid->len);
        swap_struct ( front->key,mid->key );
    }
    if (comp(front->t_stamp , rear->t_stamp,is_ascending) ) {
        swap_int ( &front->t_stamp,&rear->t_stamp);
        swap_int ( &front->len,&rear->len);
        swap_struct ( front->key,rear->key );
    }
    if ( comp(mid->t_stamp , rear->t_stamp,is_ascending) ) {
        swap_int ( &mid->t_stamp,&rear->t_stamp);
        swap_int ( &mid->len,&rear->len);
        swap_struct ( mid->key, rear->key );
    }
    /* Sort picked three nodes, by its t_stamp */
	
}
void sort_func ( list * lst , _Bool is_ascending )
{

    int sz = lst -> size ;
    char *key;
    node *piv,*track;
    uint64_t t_stamp, len;
    list *llst, *rlst;
    llst=kmalloc(sizeof(list),GFP_KERNEL);    /*List is allocated here*/
    rlst=kmalloc(sizeof(list),GFP_KERNEL);    /*List is allocated here*/
    key = kmalloc(sizeof(char)*TEMP_SIZE,GFP_KERNEL);
    piv = kmalloc(sizeof(node),GFP_KERNEL);
    track = kmalloc(sizeof(node),GFP_KERNEL);

    if ( lst -> size < 2 ) {
        return;
    }
    init_list (llst);
    init_list (rlst);
    sortthree( lst , is_ascending );
    piv = lst -> front -> next;
    key = piv ->  key;
    len = track -> len;
    t_stamp = piv -> t_stamp;
    for ( track = lst -> front -> next ; track != lst -> rear ; track = track -> next ) {
        if ( comp(track -> t_stamp , piv -> t_stamp, is_ascending) ) {
            enqueue ( llst, track -> key , track -> len , track -> t_stamp );
        } else {
            enqueue ( rlst, track -> key , track -> len , track -> t_stamp );
        }
        remove_item(lst,track);
        /* Split its keys by t_stamp */
    }
    sort_func ( llst , is_ascending ) ; /* recursive function calls*/
    sort_func ( rlst, is_ascending ) ; /*  recursive function calls*/
    /* Concatenates its left-ordered list */
    concat_list(lst,rlst);
    enqueue(lst,key,len,t_stamp);
    /* Concatenates its right-ordered list */
    concat_list(lst,rlst);
    lst -> size = sz ;
    lst -> is_sorted = 1;
    /* Regenerate its flag*/
}
