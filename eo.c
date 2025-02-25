#include<stdio.h>
#include "mylib.h"
//#include<time.h>
int main(void){
	int a,b;char d;
	puts("(e)ven or (o)dd:");
	scanf("%c",&d);
	puts("range in the form : start stop");
	scanf("%d %d",&a,&b);
	puts("");
	
//	clock_t e=clock();
	d=(d=='o');
	if ((a&1) ^ d) a+=1;
	if ((b&1) ^ d) b-=1;
	for (; a<=b; a+=2){ char * f=int2str(a);puts(f);free(f);}
//	e=clock()-e;double c=((double)e)/CLOCKS_PER_SEC;
//	printf("%f\n",c);
	return 0;
}