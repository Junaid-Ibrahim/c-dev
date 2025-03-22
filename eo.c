#include "mylib.h"
int main(int argc, char **argv){
	long long a,b; char d;
	if (argc==4){
		d = *argv[1];
		a = str2int(argv[2]);
		b = str2int(argv[3]);
	} else return 1;

	// range adjustment
	d=(d=='o');
	a+=((a&1) ^ d);
	b-=((b&1) ^ d);

	//buffer fillup
	long long l = lengt(a,b,1)+length(a,b); // #(spaces) + #(digits)
	long long k=l; 
	char *c = (char *)syscall(214,NULL); // 214 is the syscall number for brk
	syscall(214,c+(sizeof (char)*(l++)));
	for (; b>=a; b-=2){
		long long j=b;
		c[k--]=040; // 012 is octal for newline and 040 is for space in ascii
		while (j!=0){ 
			c[k--]=(j%10)+48; //48 is decimal for zero in ascii
			j/=10; 
		} c[l-1]=012;
	} syscall(64,0,c,l); return 0; } // 64 is the syscall number for write

