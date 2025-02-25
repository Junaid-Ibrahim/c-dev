#include<stdio.h>
#include<stdlib.h>
char * int2str(int a){
	int b=a,e=0,r;
	while (a!=0){ e+=1;a/=10;}
	char *f=(char *)malloc((sizeof (char))*(e+1));
	f[e]='\0';
	while (b!=0){ e-=1;r=b%10;b/=10; f[e]=r+48;}
	return f;
}
