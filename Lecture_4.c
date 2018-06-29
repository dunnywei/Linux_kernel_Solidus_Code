#include<linux/init.h>
#include<linux/module.h>
//First Step
#include<linux/module_param.h>
//Second step
int param_var=0;
//Third step
/*
(0:37)
module_param(name_var,type,permission)

permission can be
S_IRUSR
S_IWUSR
S_IXUSR
S_IWGRP
S_IRGRP
S_IXGRP

OR S_IRUSR|S_IWUSR (0:51)
*/
module_param(param_var,int,S_IRUSR|S_IWUSR);

void display(void)
{
  printk(KERN_ALERT "TEST: parameter is %d ",param_var); 
  //(2:13)
}

static int hello_init(void)
{
	printk(KERN_ALERT "TEST:Hello world");
  display();
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "TEST:End of the Hello world");
	return 0;
}

module_int(hello_init);
module_exit(hello_exit);
