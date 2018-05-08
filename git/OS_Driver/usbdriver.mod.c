#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

__visible struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x944af4ac, __VMLINUX_SYMBOL_STR(module_layout) },
	{ 0x7fb457b0, __VMLINUX_SYMBOL_STR(noop_llseek) },
	{ 0xc0346d35, __VMLINUX_SYMBOL_STR(usb_deregister) },
	{ 0xf22d6485, __VMLINUX_SYMBOL_STR(usb_register_driver) },
	{ 0xdb7305a1, __VMLINUX_SYMBOL_STR(__stack_chk_fail) },
	{ 0x4f8b5ddb, __VMLINUX_SYMBOL_STR(_copy_to_user) },
	{ 0xf08242c2, __VMLINUX_SYMBOL_STR(finish_wait) },
	{ 0x2207a57f, __VMLINUX_SYMBOL_STR(prepare_to_wait_event) },
	{ 0x1000e51, __VMLINUX_SYMBOL_STR(schedule) },
	{ 0xa1c76e0a, __VMLINUX_SYMBOL_STR(_cond_resched) },
	{ 0x14e075a7, __VMLINUX_SYMBOL_STR(mutex_lock_interruptible) },
	{ 0xe001c73a, __VMLINUX_SYMBOL_STR(usb_deregister_dev) },
	{ 0xc4838fbc, __VMLINUX_SYMBOL_STR(usb_autopm_put_interface) },
	{ 0x72584100, __VMLINUX_SYMBOL_STR(_dev_info) },
	{ 0x71b55308, __VMLINUX_SYMBOL_STR(usb_register_dev) },
	{ 0xd2b09ce5, __VMLINUX_SYMBOL_STR(__kmalloc) },
	{ 0xe9ccb88c, __VMLINUX_SYMBOL_STR(usb_get_dev) },
	{ 0x9e88526, __VMLINUX_SYMBOL_STR(__init_waitqueue_head) },
	{ 0x9cefe69c, __VMLINUX_SYMBOL_STR(__mutex_init) },
	{ 0x419a2b83, __VMLINUX_SYMBOL_STR(kmem_cache_alloc_trace) },
	{ 0x9d882c0, __VMLINUX_SYMBOL_STR(kmalloc_caches) },
	{ 0xa6bbd805, __VMLINUX_SYMBOL_STR(__wake_up) },
	{ 0xfacda96d, __VMLINUX_SYMBOL_STR(usb_unanchor_urb) },
	{ 0x609064a8, __VMLINUX_SYMBOL_STR(usb_submit_urb) },
	{ 0x27e1a5bc, __VMLINUX_SYMBOL_STR(usb_anchor_urb) },
	{ 0x4f6b400b, __VMLINUX_SYMBOL_STR(_copy_from_user) },
	{ 0x88db9f48, __VMLINUX_SYMBOL_STR(__check_object_size) },
	{ 0xd93462a6, __VMLINUX_SYMBOL_STR(usb_alloc_coherent) },
	{ 0x901d17c8, __VMLINUX_SYMBOL_STR(usb_alloc_urb) },
	{ 0x78764f4e, __VMLINUX_SYMBOL_STR(pv_irq_ops) },
	{ 0xe5815f8a, __VMLINUX_SYMBOL_STR(_raw_spin_lock_irq) },
	{ 0x156a8a59, __VMLINUX_SYMBOL_STR(down_trylock) },
	{ 0x6dc0c9dc, __VMLINUX_SYMBOL_STR(down_interruptible) },
	{ 0x78e739aa, __VMLINUX_SYMBOL_STR(up) },
	{ 0xed5aadf, __VMLINUX_SYMBOL_STR(usb_free_coherent) },
	{ 0x6bf1c17f, __VMLINUX_SYMBOL_STR(pv_lock_ops) },
	{ 0xe259ae9e, __VMLINUX_SYMBOL_STR(_raw_spin_lock) },
	{ 0xcf94219e, __VMLINUX_SYMBOL_STR(dev_err) },
	{ 0x27e1a049, __VMLINUX_SYMBOL_STR(printk) },
	{ 0x16305289, __VMLINUX_SYMBOL_STR(warn_slowpath_null) },
	{ 0xacd5a2b6, __VMLINUX_SYMBOL_STR(usb_autopm_get_interface) },
	{ 0x223e267b, __VMLINUX_SYMBOL_STR(usb_find_interface) },
	{ 0x37a0cba, __VMLINUX_SYMBOL_STR(kfree) },
	{ 0x7fec4713, __VMLINUX_SYMBOL_STR(usb_put_dev) },
	{ 0xdac846c6, __VMLINUX_SYMBOL_STR(usb_free_urb) },
	{ 0xc2032288, __VMLINUX_SYMBOL_STR(mutex_lock) },
	{ 0x1fd83028, __VMLINUX_SYMBOL_STR(usb_kill_urb) },
	{ 0x4395953e, __VMLINUX_SYMBOL_STR(usb_kill_anchored_urbs) },
	{ 0x24f45195, __VMLINUX_SYMBOL_STR(usb_wait_anchor_empty_timeout) },
	{ 0x34edf200, __VMLINUX_SYMBOL_STR(mutex_unlock) },
	{ 0xbdfb6dbb, __VMLINUX_SYMBOL_STR(__fentry__) },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("usb:v04D8p0053d*dc*dsc*dp*ic*isc*ip*in*");

MODULE_INFO(srcversion, "B0AB029A5E1E5A1595AF751");
