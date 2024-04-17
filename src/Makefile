KDIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)
MAKE = /usr/bin/make
%.ko : obj-m=$(*).o
%.ko : %.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
