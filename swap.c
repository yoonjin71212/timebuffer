#include "buffer.h"
#include <linux/slab.h>
#include <linux/string.h>
void swap_string ( char * a, char * b )
{
    char * tmp = (char*)kmalloc(TEMP_SIZE,GFP_ATOMIC);
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(a,tmp);
    
} /*swaps two values' memory address,   *
   *this is far better...               */

void swap_int(int64_t *a, int64_t *b) {
    int64_t tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
/*But in this case, it's far better to use*
 *usual form of call-by-reference         */


MODULE_LICENSE("GPL");
