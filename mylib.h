#include<stdio.h>
#include<stdlib.h>
char * int2str(int a){
	int b=a,e=0,r;
	while (a!=0){ e+=1;a/=10;}
	int i = e-1;char *f=(char *)malloc((sizeof (char))*(e+1));
	f[i]='\0';
	while (b!=0){ r=b%10;b/=10; f[i]=r+48; i-=1;}
	return f;
}
