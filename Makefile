all:
	sh run.sh
	extract-bc kernel.o -l llvm-link-4.0
	llvm-dis-4.0 kernel.o.bc
clean: 
	rm *.o *.bin *.iso
	rm -rf isodir
	rm kernel.o.bc
	rm kernel.o.ll 
