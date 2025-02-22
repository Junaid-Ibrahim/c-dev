#include<stdio.h>
int main(int argc, char** argv){
	int a=*argv[argc-1]-48;
	int b[a],c = 7;
	for (int i=0;i<c;i++){ b[i]=i;} 
	printf("%d",b[c-1]);
	return 0;
}
