#include<linux/init.h>
#include<linux/module.h>

static int hello_init(void)
{
	printk(KERN_ALERT "Hello world \n");
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "End of the Hello world \n");
	return 0;
}

module_int(hello_init);
module_exit(hello_exit);