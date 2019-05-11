#include "kernel.h"

uint16 vga_entry(unsigned char ch, uint8 fore_color, uint8 back_color){
	uint16 ax = 0;
	uint8 ah = 0, al = 0;
	ah = back_color;
	ah <<= 4;
	ah |= fore_color;
	ax = ah;
 	ax <<= 8;
	al = ch;
	ax |= al;
	return ax;
}
void clear_vga_buffer(uint16 ** buffer, uint8 fore_color, uint8 back_color){
	uint32 i;
	for(i = 0 ; i < BUFSIZE; i++){
		(*buffer)[i] = vga_entry(NULL, fore_color, back_color);
	}
}
void init_vga(uint8 fore_color, uint8 back_color){
	vga_buffer = (uint16*) VGA_ADDRESS;
	clear_vga_buffer(&vga_buffer,fore_color,back_color);
}
void stringCopier (unsigned char * str , uint16** vga_buffer, uint32 strLength){
	uint32 i;
	for(i = 0 ; i < strLength ; i++){
		(*vga_buffer)[i] = vga_entry(str[i], WHITE, BLACK);
	}
}
void kernel_entry(){
	init_vga(WHITE,BLACK);
	stringCopier("DilawerRocks", &vga_buffer, 12);
}
