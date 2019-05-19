source setup

as --32 boot.s -o boot.o
wllvm -m32 -c kernel.c -o kernel.o 
ld -m elf_i386 -T linker.ld kernel.o boot.o -o MyOS.bin -nostdlib
grub-file --is-x86-multiboot MyOS.bin 

mkdir -p isodir/boot/grub
cp MyOS.bin isodir/boot/MyOS.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o MyOS.iso isodir

qemu-system-x86_64 -cdrom MyOS.iso
