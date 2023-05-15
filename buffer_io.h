#include <linux/ioctl.h>
enum __IOCTL_CMD__ {
__ZERO__,   /* literally 0. */
__PROTO_CLEAR__,   /* Clear function call */
/*ORT */
__PROTO_SORT_ASCENDING__,
__PROTO_SORT_DESCENDING__,
/*---*/
__PROTO_SIZE_CALL__, /*Size request*/
};
#define IOCTL_MAGIC 'G' /*Magic letter */
/*Actual IOCTL Commands, are here. */
#define __CLEAR__ _IO(IOCTL_MAGIC,(unsigned int)__PROTO_CLEAR__) 
#define __SORT_ASCENDING__ _IOW(IOCTL_MAGIC,(unsigned int)__PROTO_SORT_ASCENDING__,struct{})
#define __SORT_DESCENDING__ _IOW(IOCTL_MAGIC,(unsigned int)__PROTO_SORT_DESCENDING__,struct{})
#define __SIZE_CALL__ _IO(IOCTL_MAGIC,(unsigned int)__PROTO_SIZE_CALL__)
/*-------------------------------*/
/* This is error code for internal error detection */
#define LST_ERR "-100000"
