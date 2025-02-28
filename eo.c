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
	a+=((a&1) ^ d);
	b-=((b&1) ^ d);
	int l = b-a;
	l+=length(a,b)+1;
	char *h=(char *)malloc((sizeof (char) )*(l+1));
	int k=l;
	for (; b>=a; b-=1){
		int j=b,r;
		h[k]='\n';
		while (j!=0){ k-=1;r=j%10;j/=10; h[k]=r+48;}
		k--;
	} h[l]='\0';puts(h);free(h);
//	e=clock()-e;double c=((double)e)/CLOCKS_PER_SEC;
//	printf("%f\n",c);
	return 0;
}