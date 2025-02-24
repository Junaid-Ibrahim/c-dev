#include<stdio.h>
int main(void){
	int a,b;char d;
	puts("(e)ven or (o)dd:");
	scanf("%c",&d);
	puts("range in the form : start stop");
	scanf("%d %d",&a,&b);
	
	d=(d=='o');
	if ((a&1) ^ d) a+=1;
	if ((b&1) ^ d) b-=1;
	for (; a<=b; a+=2){ printf("%d ",a);}
	puts("");
	return 0;
}