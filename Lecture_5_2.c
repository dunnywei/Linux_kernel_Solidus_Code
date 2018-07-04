#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/module_param.h>
//Lecture 5_2
//For usb driver


//disconnect function
static void pen_disconnect(struct usb_interfaace* interface)
{
	printk(KERN_INFO "USB KERNEL_DRIVE removed\n");
	return;
}

//probe function
/*
*/
static int _pen_probe(struct usb_interfaace *interface,const struc usb_device_id *id)
{
	printk(KERN_INFO "[*] Pen Drve starts(%04x:%04x) to plug\n",id->idVendor,id-id->idProduct);
	return 0;// return 0 means we will manage this device
}



//usb_device_id
static struct usb_device_id pen_table[]={
   //0781:6506->this info is obtained by typing "lsusb" in CLI @(1:03)
/*
->what we have here is a way for the kernel to match any currenlty attached device (1:04) against all
available drivers to find the right driver (1:09) to call 
->To use that driver to manage (1:11) the newly installed and attached device so (1:16)

*/
   {USB_DEVICE(0x0781,0x5406)}, //->I can have more than more usb devcies by adding (3:13)as the following line(3:18)
	                       //so it can support more than one device (3:20)
   //{USB_DEVICE(v,p)},
	{} /*For terminating entry*/
}

static struct usb_driver pen_driver=
{
	.name="My-USB DEVICE pen driver", //->naming the drive as a whole(0:30)
	.id_table=pen_table,//->Id table is used to match this drive with any device that is attached to the USB bus(0:40)
	                    //->This is how kernel knows which driver to call to(0:46) to handle a particular device when it is plugged into the computer(0:49)
	                    //->This is a usb_device_id (0:55)
	.probe=pen_probe,//(@3:34)
	.disconnect=pen_disconnect,
};
static int __init pen_init(void)
{
	int ret=-1;
	printk(KERN_INFO "[*]TEST:pen_init");
	printk(KERN_INFO "\tTEST:REGISTER drive with kernel");
	ret=usb_register(&pen_driver);
	printk(KERN_INFO "\tTEST:Reiistration complete");
	return ret;
}

static void __exit pen_exit(void)
{
     printk(KERN_INFO "[*]TEST:exit of driver");
     usb_deregister(&pen_drive);
     printk(KERN_INFO "\tTEST:UNREGISTER drive with kernel DONE");	
}

module_int(pen_init);
module_exit(pen_exit);

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
 ->"Bulk end point"(??) or interrupt(??) apply long the most significatnt bit to indicate the direction of data either 
 from the computer to device or device to computer (2:37)
 ->All these types of endpoint are unit directional except(2:43) the control point which is bi-directional(2:47)
 ->"Bulk end point"->it is used for mass storage and (2:55) transfer large amount of data at once(2:58)
 ->"isochronous" is like a bulk transfer for tranfering large qunatitiy of infomration (3:06).However
it has bandwith gurarentee (3:09) and it is usually found in audio/video device (3:13)
->End poit is identified by address and so each end point (3:18)  has a particulcar address used to
(3:21) include the type info and send ino to the actual device or get the infomration from device to the
(3:28) to the kernel (3:31)
 ->There is a command called "lsusb" in CLI (3:36). It will dispaly all USB devices connected to your coomputer(3:40)
 ->After typing the command "lsusb", you will see sth like "root hub"=ignore(3:48)
 ->focus on wacom or wireless mouse (3:59)
 ->BUS 003=on Bus number 3 with ID=046d(vendor id):C52f(prouct id) (4:04)(4:09)
 ->We need to know theose value during coding (4:13) for USB driver (4:33)
 ->
 */

/*Lectutre_5_2
->Type "lsusb" then find out that there is no pen_drive installed in my computer
->Now I am going to instert the USB pendrive to my computer and then run (1:48) it again.
->Type "lsusb" again, I find my pen drive (1:52) with ID 0781:5406 as VendorID:Product(ID) (2:25)
->If you want to get more info about the vendor info, type "lsusb -v" (2:36)


-->In the probe function
->It is called Whenever a device is plugged into your computer.However, it won't be called if another driver currentlly own that
particlular device(@3:49)
->If another driver is currenly installed and indicating to the kernel that it is repsonsible to manage the particular device that's
plugged in (3:58) into the computer.
->(@4:00) Then your probe function will not get called. As a result, if you want your device driver to manage a device instead
(@4:07)Instead, you will have to unload the other driver and install yours in its place (4:13)

->Proble function take as structure of (4:19) usb_interface described from prvious video (4:25)
->It represents a logical device such as a USB speaker, camera (@4:30)
->The usb_device_id is the same as the usb_device_id pen_table[] (@4:38)
->The device is plugged into the computer and the kernel calls the particular (@4:45) probe function (4:48) and want to see if the
particular driver is willing to handle this device with usb_device_id supplied (4:55) At which points the probe function (4:57)
->Probe function intialize the the local info (4:59), structures, memories (5:02) and return 0 indicating it is willing to manage the device
(5:04)
->However the probe function won't get called if another (5:10) driver is taking claim to the device (5:14)

-->Inside static struct usb_driver pen_driver
->.disconnect=pen_disconnect (5:17). This function is used to clean up the memory. It is called upon whenever the device is removed from
the system (5:26)
->The definition will be implemented in (5:30) disconnect function
->disconnect function is called whenever the pen is removed (5:33)
->That's the definition of the USB driver of "static struct usb_driver pen_driver" (5:39)
->Now we need to register this pen drive (5:45) to the USB cord (5:47)
->It is like register the char device but we will now register the USB port (5:54). See function of pen_init(void)
->So we will have debug info and register the pen_drive to the usb cord (6:05)
->Then we will move to the pen_exit(void) function
->we are going to degresiter our (6:10) pendrive (6:12)
->Now let's move to the makefile (6:30)
*/
