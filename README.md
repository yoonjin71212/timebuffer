
## TimeBuffer, Timestamp-based Sortable FIFO Device Driver for Linux
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/8c26c5411743427b900d6e1f5c7dfaf5)](https://www.codacy.com/gh/yoonjin2/timebuffer/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=yoonjin2/timebuffer&amp;utm_campaign=Badge_Grade)

# headers
----------------
```c
enum __IOCTL_CMD__ {
__ZERO__,
__PROTO_CLEAR__,
__PROTO_SORT_ASCENDING__,
__PROTO_SORT_DESCENDING__,
__PROTO_SIZE_CALL__,
};


#define IOCTL_MAGIC 'G'
#define __CLEAR__ _IO(IOCTL_MAGIC,__PROTO_CLEAR__) 

#define __SORT_ASCENDING__ _IO(IOCTL_MAGIC,__PROTO_SORT_ASCENDING__)
#define __SORT_DESCENDING__ _IO(IOCTL_MAGIC,__PROTO_SORT_DESCENDING__)
#define __SIZE_CALL__ _IOWR(IOCTL_MAGIC,__PROTO_SIZE_CALL__)
#define LST_ERR "-100000"
```

# IOCTL comments as table
|Name|Code|Task|Tested|
|---|---|---|---|
|`__CLEAR__`|1|Clear buffer|**O**| 
|`__SORT_ASCENDING__`|**2**|Sort buffer(ascending)|**O**|    
|`__SORT_DESCENDING__`|**3**|Sort buffer(descending)|**O**|
|`__SIZE_CALL__`|4|return buffer size|**O**|
-----------------------------------------
    
**Use with caution**

This is device driver that do all tasks in GFP_KERNEL.

You can change its allocation space.

Thanks.


