#include <stdio.h>
int main(int argc,char** argv) {
	unsigned char a[]="st";
	printf("program name is %s\n",argv[0]);
	for(unsigned char i = 1; i < argc; i++){
		switch(i){ 
			case 2: a[0]='n';a[1]='d';break;
			case 3: a[0]='r';break;
			case 4: a[0]='t';a[1]='h';
		}
		printf("%d%s argument is %s\n",i,a,argv[i]);
	}
	return 0;
}

