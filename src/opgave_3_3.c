#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>
MODULE_LICENSE("Dual BSD/GPL");


static const int major = 500;
static const int minor = 0;
static const int amount = 1; // amount of major nrs.
static const char driver_name[] = "hello_driver";

/* device structures */
static struct cdev* device;

/**
* Open/release
**/
static int hello_open(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "hello_open()\n");
	return 0;
}
static int hello_release(struct inode *inode, struct file *file)
{
	printk(KERN_ALERT "hello_release()\n");
	return 0;
}

/**
* read / write
**/
static ssize_t
hello_read(struct file *file, char __user * buf, size_t lbuf, loff_t * ppos)
{
	printk(KERN_ALERT "hello_read()\n");
	return 0;
}
static ssize_t
hello_write(struct file *file, const char __user * buf, size_t lbuf, loff_t * ppos)
{
	printk(KERN_ALERT "hello_write())\n");
	return 0;
}

struct file_operations fops = {
	.read = hello_read,
	.write = hello_write,
	.open = hello_open,
	.release = hello_release,
};

static int hello_init(void)
{
	dev_t device_number;
	int result;
	device_number = MKDEV(major, minor);
	device = cdev_alloc();
	if(!device){
		printk(KERN_ALERT "Failed ALLOCATION");
		return -ENOMEM;
	}
	cdev_init(device, &fops);
	result = register_chrdev_region(device_number, amount, driver_name);     
	if (result < 0) {         
		printk(KERN_ALERT "Failed to register device region: %d\n", result);         
		return result;     
	}

    	result = cdev_add(device, device_number, amount);
    	if (result < 0) {
        	printk(KERN_ALERT "Failed to add cdev: %d\n", result);
        	unregister_chrdev_region(device_number, amount); 
		return result;
    	}

	printk(KERN_ALERT "hello_init()\n");
	return 0;
}
static void hello_exit(void)
{
	dev_t device_number;

	device_number = MKDEV(major, minor);
	cdev_del(device);

	unregister_chrdev_region(device_number, amount);

	printk(KERN_ALERT "hello_exit()\n");

}

module_init(hello_init);
module_exit(hello_exit);
