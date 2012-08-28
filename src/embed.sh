#!/bin/bash

losetup /dev/loop0 ../grub/grub.img
mount /dev/loop0 /mnt/Grub
cp kernel /mnt/Grub/kernel
sleep 1
umount /dev/loop0
losetup -d /dev/loop0
