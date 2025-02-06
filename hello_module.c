#include <linux/init.h>    // Macros used to mark up functions e.g., __init __exit
#include <linux/module.h>  // Core header for loading LKMs into the kernel
#include <linux/kernel.h>  // Contains types, macros, functions for the kernel

// Module metadata
MODULE_LICENSE("GPL");                   // The license type -- this affects available functionality
MODULE_AUTHOR("Toni Helminen / AI");     // The author 
MODULE_DESCRIPTION("A simple Linux driver example.");  // Description -- see modinfo
MODULE_VERSION("1.0");              // The version of the module

// The __init macro means that for a built-in driver (not a LKM) the function is only used at initialization time and that it can be discarded and its memory freed up after that point.
static int __init hello_init(void) {
    printk(KERN_INFO "Hello, World!\n");
    return 0;    // Non-zero return means that the module couldn't be loaded.
}

// The __exit macro means that if this code is used for a built-in driver (not a LKM) this function is not required.
static void __exit hello_exit(void) {
    printk(KERN_INFO "Goodbye, World!\n");
}

// These macros define the initialization and cleanup functions for the module.
module_init(hello_init);
module_exit(hello_exit);
