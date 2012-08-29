OBJS=boot.o main.o common.o screen.o gdt.o gdt_reload.o isr.o interrupt.o
CC=i686-elf-gcc
LD=i686-elf-ld
CFLAGS=-nostdlib -nostdinc -fno-builtin -fno-stack-protector -Wall -Wextra -pedantic
LDFLAGS=-Tlink.ld
ASFLAGS=-felf32

all: $(OBJS) link
	sudo ./embed.sh

link:
	$(LD) $(LDFLAGS) -o kernel $(OBJS)

.s.o:
	nasm $(ASFLAGS) $<

clean:
	rm *.o kernel
