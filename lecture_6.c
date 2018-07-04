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
-Writing/reading block by block->It means the large number of information (1:41) in large chunks
-Therefore it is CPU intensive (1:45)
-Operation take long time to complete
-asynchorous with opoeration therefore the user doesn't need to wait for the operation of reading/writing (2:05) to the device
to be completed (2:08) before the user can continue doing anything (2:12) else
->Step 1 is to create the device file (2:32)
*/
