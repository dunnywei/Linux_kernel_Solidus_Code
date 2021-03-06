#include<linux/init.h>
#include<linux/module.h>
//First Step
#include<linux/module_param.h>
//Second step
//passing a value
//int param_var=0;
//end of passing a value

//passing an array
//int param_var[3]=[1,2,3];
//end of passing an array
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
//passing a value
//module_param(param_var,int,S_IRUSR|S_IWUSR);
//end of passing a value
//passing an array
module_param_array(param_var,int,NULL,S_IRUSR|S_IWUSR);
//->(3:07)
//end of passing an array


void display(void)
{
  //passing a value	
  //printk(KERN_ALERT "TEST: parameter is %d ",param_var);
  //(2:13)
  //end of passing a value
	
    //passing an array
    printk(KERN_ALERT "TEST: parameter is %d ",param_var[0]);
    printk(KERN_ALERT "TEST: parameter is %d ",param_var[1]);
    printk(KERN_ALERT "TEST: parameter is %d ",param_var[2]);
    //(3:34)
    //end of passing an array


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

/*
->https://www.youtube.com/playlist?list=PLZDevgBJtN8zyXV2QaozxzJzgJ9tpZY6p
->helpful lnnk->https://www.tldp.org/LDP/lkmpg/2.6/html/index.html
->Now we want to pass an array into the kernel (3:00)
->Let's go back to console and rebuild (3:39)
->type the following->"insmod Lecture4.ko param=24,535,19" in CLI (4:02)
->type the following->"dmesg"->(4:09)
->type the following->"rmmod Lecture4.ko"->(4:20)
 */
