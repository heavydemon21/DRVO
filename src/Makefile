
inputFile=opgave_3_3
KDIR := /lib/modules/$(shell uname -r)/build
PWD := $(shell pwd)

obj-m = $(inputFile).o

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

%.ko:%.c
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	rm -f *.o *.ko *.order *.cmd *.symvers *.mod.c
	rm -rf .tmp_versions
