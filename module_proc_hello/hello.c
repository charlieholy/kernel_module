#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/sched.h>
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Charlie");



void hello_exit(void)
{
    printk(KERN_INFO "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
    printk(KERN_INFO "Goodbye World Proc...\n");
}

int hello_open(struct inode * inode, struct file * file){
    printk(KERN_INFO "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
    printk(KERN_INFO "Hello World Open...\n");
}

int hello_read(struct inode * inode, struct file * file){
    printk(KERN_INFO "Hello World Read...\n");
}

static const struct file_operations proc_hello_operations = {
	.read		= hello_read,
	.open		= hello_open,
};

int hello_init(void)
{

    printk(KERN_INFO "The process is \"%s\" (pid %i)\n", current->comm, current->pid);
    printk(KERN_INFO "Hello World Proc...\n");
    //proc_create("hello", S_IRUSR, NULL, &proc_hello_operations);
    return 0;
}

module_init(hello_init);
module_exit(hello_exit);
