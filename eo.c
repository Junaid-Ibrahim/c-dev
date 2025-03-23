#include "mylib.h"
static inline long my_syscall2(long n, long a1){
	long r;
	asm volatile (
		"mov x8, %1;mov x0, %2;svc #0;mov %0, x0"
		:"=r" (r):"r"(n) , "r"(a1):"memory");
	return r;
}
static inline void my_syscall4(long n, long a1,long a2,long a3){
	asm volatile (
		"mov x8, %0;mov x0, %1;mov x1, %2;mov x2, %3;svc #0"
		::"r"(n) , "r"(a1), "r"(a2), "r"(a3):"memory");
}
void _start(){
	long long a,b;long argc,argv1,argv2,argv3; char d;
	asm volatile(
		"ldr %0, [x29, #16];ldr %1, [x29, #32]; ldr %2, [x29, #40];ldr %3, [x29, #48]"
		: "=r"(argc), "=r"(argv1), "=r"(argv2), "=r"(argv3)
		::"memory");
	if (argc==4){
		d = *((char *)argv1);
		a = str2int((char *)argv2);
		b = str2int((char *)argv3);
	} else my_syscall2(93,1);

	// range adjustment
	d=(d=='o');
	a+=((a&1) ^ d);
	b-=((b&1) ^ d);

	//buffer fillup
	long long l = lengt(a,b,1)+length(a,b); // #(spaces) + #(digits)
	long long k=l; 
	long cc = my_syscall2(214,0); // 214 is the syscall number for brk
	my_syscall2(214,cc+(sizeof (char)*(l++)));
	char *c= (char* )cc;
	for (; b>=a; b-=2){
		long long j=b;
		c[k--]=040; // 012 is octal for newline and 040 is for space in ascii
		while (j!=0){ 
			c[k--]=(j%10)+48; //48 is decimal for zero in ascii
			j/=10; 
		} c[l-1]=012;
	} my_syscall4(64,0,(long)c,l); my_syscall2(93,0); } // 64,93 are syscall numbers for write,exit

