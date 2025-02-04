#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/device.h>

#define DEVICE_NAME "mychardev"
#define BUFFER_SIZE 1024

static char device_buffer[BUFFER_SIZE];
static int device_open = 0;
static dev_t dev_num;
static struct cdev my_cdev;
static struct class *my_class;

static int mychardev_open(struct inode *inode, struct file *file) {
    if (device_open)
        return -EBUSY;
    device_open++;
    try_module_get(THIS_MODULE);
    printk(KERN_INFO "mychardev: Device opened\n");
    return 0;
}

static int mychardev_release(struct inode *inode, struct file *file) {
    device_open--;
    module_put(THIS_MODULE);
    printk(KERN_INFO "mychardev: Device closed\n");
    return 0;
}

static ssize_t mychardev_read(struct file *file, char __user *user_buffer, size_t size, loff_t *offset) {
    size_t bytes_to_read = min(size, (size_t)(BUFFER_SIZE - *offset));
    if (bytes_to_read == 0)
        return 0;
    if (copy_to_user(user_buffer, device_buffer + *offset, bytes_to_read))
        return -EFAULT;
    *offset += bytes_to_read;
    printk(KERN_INFO "mychardev: Read %zu bytes\n", bytes_to_read);
    return bytes_to_read;
}

static ssize_t mychardev_write(struct file *file, const char __user *user_buffer, size_t size, loff_t *offset) {
    size_t bytes_to_write = min(size, (size_t)(BUFFER_SIZE - *offset));
    if (bytes_to_write == 0)
        return -ENOMEM;
    if (copy_from_user(device_buffer + *offset, user_buffer, bytes_to_write))
        return -EFAULT;
    *offset += bytes_to_write;
    printk(KERN_INFO "mychardev: Written %zu bytes\n", bytes_to_write);
    return bytes_to_write;
}

static long mychardev_ioctl(struct file *file, unsigned int cmd, unsigned long arg) {
    printk(KERN_INFO "mychardev: IOCTL called with cmd=%u, arg=%lu\n", cmd, arg);
    return 0;
}

static const struct file_operations mychardev_fops = {
    .owner          = THIS_MODULE,
    .open           = mychardev_open,
    .release        = mychardev_release,
    .read           = mychardev_read,
    .write          = mychardev_write,
    .unlocked_ioctl = mychardev_ioctl,
};

static int __init mychardev_init(void) {
    if (alloc_chrdev_region(&dev_num, 0, 1, DEVICE_NAME) < 0)
        return -1;
    cdev_init(&my_cdev, &mychardev_fops);
    if (cdev_add(&my_cdev, dev_num, 1) < 0)
        goto unregister_dev;
    my_class = class_create(THIS_MODULE, DEVICE_NAME);
    if (IS_ERR(my_class))
        goto del_cdev;
    if (!device_create(my_class, NULL, dev_num, NULL, DEVICE_NAME))
        goto destroy_class;
    printk(KERN_INFO "mychardev: Device registered with major %d, minor %d\n", MAJOR(dev_num), MINOR(dev_num));
    return 0;

destroy_class:
    class_destroy(my_class);
del_cdev:
    cdev_del(&my_cdev);
unregister_dev:
    unregister_chrdev_region(dev_num, 1);
    return -1;
}

static void __exit mychardev_exit(void) {
    device_destroy(my_class, dev_num);
    class_destroy(my_class);
    cdev_del(&my_cdev);
    unregister_chrdev_region(dev_num, 1);
    printk(KERN_INFO "mychardev: Device unregistered\n");
}

module_init(mychardev_init);
module_exit(mychardev_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Your Name");
MODULE_DESCRIPTION("Simple Character Device Driver");
