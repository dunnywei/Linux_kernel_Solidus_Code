/*Lecture_6
Two different type of device drivers

Character Devices:
-Writing/reading character by character
-Opertaing in the block mode(0:37)
   ->It means that it is an atomic operation. When the user writes on the device, user has to wait until the
device finish writing the last byte before cotinue the user code (0:48)
-synchrnous mode of operation(Same as block mode)
-Most common of all device driver (1:26)

Block Device
-Writing/reading block by block
-CPU intensive, Operation take long time to complete, asynchorous with opoeration
*/
