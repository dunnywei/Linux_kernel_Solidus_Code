
#include<linux/init.h>
#include<linux/module.h>

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
->https://www.youtube.com/watch?v=NYRhkGrt4Q4&index=5&list=PLZDevgBJtN8zyXV2QaozxzJzgJ9tpZY6p
->helpful lnnk1->https://www.tldp.org/LDP/lkmpg/2.6/html/index.html
->helpful link2->https://static.lwn.net/images/pdf/LDD3/ch14.pdf
               ->https://static.lwn.net/images/pdf/LDD3/ch01.pdf
->Lecture 5_1
->USB device has a VendorID and Major ID
 */
