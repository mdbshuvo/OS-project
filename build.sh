rm *.o *.bin
make myKernel.bin
qemu-system-i386 -kernel myKernel.bin
sudo cp myKernel.bin /boot/
