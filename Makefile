obj-m+=Hello.o

KDIR=/usr/src/Linux-headers-3.2.0-24-generic-pae

all:
	$(MAKE) -C $(KDIR) SUBDIRS=$(PWD) modules
clean:
	rm -rf *.o *.ko *.mod.* *.symvers *.order