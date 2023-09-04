#include <linux/init.h>
#include <linux/ktime.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/kernel.h>
#include <linux/cdev.h>
#include <linux/errno.h>
#include <linux/types.h>
#include <asm/uaccess.h>
#define TEMP_SIZE 65536
typedef long long ll;

typedef struct node {
    char * key;
    uint64_t len;
    uint64_t t_stamp;
    struct node * prev;
    struct node * next;
} node;
/*list's node */

typedef struct list {
    node *front;
    node *rear;
    ll size;
} list;
/*list*/

void init_list ( list * lst ); /*this is initializer, which is dynamic */
void reset_list ( list * lst );/*resetting the list, without cleaning its data */
int8_t between  ( list * lst, char * item, node * r, node * element , uint64_t len, uint64_t t_stamp) ; /*adds node with this*/
int8_t enqueue ( list * lst, const char * item , uint64_t len, uint64_t t_stamp) ;   /* alias to enqueue task with between function */
void concat_list ( list * lst, list * lst_target ) ; /*concatenate two lists, without redundant enqueue function call*/

node * remove_item ( list * lst, node * element ) ;  /* it removes specified element */
node * dequeue ( list * lst ) ;  /* this is alias to dequeue test implemented by remove_item function. */
ll size ( list *lst ) ; /*returns its size */

void repair_size ( list *lst ) ; /*list size repair */
int8_t full ( list * lst ) ; /* returns 1 when its buffer is full */
void show ( list * lst ) ; /*it shows its data, into kernel log */
void free_list ( list * lst ) ;  /* when freeing its front && rear node */
void empty_list ( list * lst ) ; /* WARNING: it cleans all data ! */
node * find ( list * lst, unsigned char * key ) ; /* you can specify node with your key */
node * index_node ( list * lst, ll i ) ; /* this returns (i+1)th node. */

int __init init_device (void); /* Initialization of its device */

void __exit clean_device(void);/* exit call */
int device_open (struct inode *, struct file *);     /* mutex_lock when opened */
int device_release (struct inode *, struct file * ); /* mutex_unlock when closed */

/*I/O Tasks -----------------------------------------------------------------------*/
ssize_t device_read (struct file *, char *, size_t, loff_t *); 
ssize_t device_write (struct file *, const char *, size_t, loff_t *);
/*---------------------------------------------------------------------------------*/
void GET_UUID (char * string) ;   /* UUID generation */

ll index_of(list *lst , node *nd);    /* Index of specific node */
int comp(ll t_stamp_l, ll t_stamp_r);    /* comparison between two long long, with flag */
#define PREFIX TEMP_SIZE*4 /* this is string's max length*/
#define LST_MAX 10000 /* and list can handle up to 10000, if possible. */
#define CLEAR_THRESHOLD 200
#define UUID_LEN 36
#define LST_ERR "-1000000000"
