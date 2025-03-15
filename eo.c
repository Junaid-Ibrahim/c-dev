#include "mylib.h"
int main(int argc, char **argv){
	int a,b; char d;
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
	int l = lengt(a,b,1)+length(a,b); // #(spaces) + #(digits)
	int k=l; char *h; 
	if((h=(char *)sbrk((sizeof (char) )*(++l))) == ((void *)-1)) { return 2;}
	for (; b>=a; b-=2){
		int j=b;
		h[k--]=040; // 012 is octal for newline and 040 is for space in ascii
		while (j!=0){ 
			h[k--]=(j%10)+48; //48 is decimal for zero in ascii
			j/=10; 
		}
	} write(0,h,++l); return 0; }