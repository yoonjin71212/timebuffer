#include <linux/module.h>
#define INCLUDE_VERMAGIC
#include <linux/build-salt.h>
#include <linux/elfnote-lto.h>
#include <linux/export-internal.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;
BUILD_LTO_INFO;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif


static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
	{ 0x88db9f48, "__check_object_size" },
	{ 0xeea3c1d8, "__class_create" },
	{ 0x13c49cc2, "_copy_from_user" },
	{ 0x6a2dd7c, "class_destroy" },
	{ 0x37a0cba, "kfree" },
	{ 0xcbd4898c, "fortify_panic" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0x52c9aed, "ktime_get_real_fast_ns" },
	{ 0x122c3a7e, "_printk" },
	{ 0xa19b956, "__stack_chk_fail" },
	{ 0x7682ba4e, "__copy_overflow" },
	{ 0xa916b694, "strnlen" },
	{ 0x599fb41c, "kvmalloc_node" },
	{ 0x2dcc02c1, "cdev_add" },
	{ 0x4c0ac327, "device_create" },
	{ 0x449ad0a7, "memcmp" },
	{ 0x9ed12e20, "kmalloc_large" },
	{ 0xcefb0c9f, "__mutex_init" },
	{ 0x5b8239ca, "__x86_return_thunk" },
	{ 0x6b10bee1, "_copy_to_user" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0x7e38d25d, "device_destroy" },
	{ 0x41ed3709, "get_random_bytes" },
	{ 0x850e6a88, "kmalloc_trace" },
	{ 0x32ab4392, "cdev_init" },
	{ 0xad6d045f, "kmalloc_caches" },
	{ 0xf7fb9e48, "cdev_del" },
	{ 0x453e7dc, "module_layout" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "8F7AF3637E07E5358A0E69A");
