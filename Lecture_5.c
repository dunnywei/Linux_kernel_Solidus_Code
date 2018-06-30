
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
->while plugiing in the USB to the computer, the "USB host controller" takes all
 (0:21), info to he binary named "USD_CORE" which is platfform independently
 in kernel space(0:34)
 ->The USB_core will then give then info to the operating system (0:39) at Linux Kernel (0:42)
 ->The kernel will see if there is any device available to handle the particular device (0:50)
 ->IF there is one available, it makes the device available to the user space (0:55)
 ->If there is no driver available, the kernel still recognize the device (1:00)
 ->the application in user space can't never know if the device exist or not (1:06)
 ->The USD device is configured in the way that everyone has a profolio (1:13) contains configuration(1:16)
 ->WIthin the configuration, there are number of interfaces such as interface 1 or interface 2 (1:21)
 ->The interface describes the functinality of the (1:26) of the device (1:28)
 ->For example, it can be a printer, fax, (1:33) for scanner.
 ->For each function, it is going to be an interface. At the same time(1:39), each interface has one 
 or more endpoints(s).
 ->Each end point (1:44) describes input and output so it can take information from computer to the device(1:53)
 ->Every device has "end point 0". "End point 0" is (1:58) to intialize device and make it ready for usuage(2:02)
 ->There are different types of "end points". They are Control, Interrupt, Bulk, isochronous (2:05)
 ->"Control Endpoint"=control the device eg. resetting the device or query the infomration (2:19)
 ->"Interrupt end point" is used to sending fast information between the device and computer (2:25)
 ->"Bulk end point" apply long the most significatnt bit to indicate the direction of data either 
 from the computer to device or device to computer (2:37)
 ->All these types of endpoint are unit directional except(2:43) the control point which is bi-directional(2:47)
 ->
 
 
 
 */