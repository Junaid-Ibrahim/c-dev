#include<stdio.h>
#include<stdlib.h>
int mypow(int a,int b){
	int i=1;
	for(;b>=0;b--){ i*=a;}
	return i;
}
char * int2str(int a){
	int b=a,e=0,r;
	while (a!=0){ e+=1;a/=10;}
	char *f=(char *)malloc((sizeof (char))*(e+1));
	f[e]='\0';
	while (b!=0){ e-=1;r=b%10;b/=10; f[e]=r+48;}
	return f;
}
int length(int a , int b){
	int e=0,f=0,c=a,d=b;
	while(c!=0){ e+=1;c/=10;}
	while(d!=0){ f+=1;d/=10;}
	if (e==f) { return ((b-a)*e); }
	int s = (b+1 - mypow(10,f-1))*f;
	s=(s+mypow(10,e)-a)*e;
	for (int h=e+1;h<f;h++){
		s+=8*mypow(10,h-1);
		for(int g=h-2;g>=0;g++){s+=9*mypow(10,g);}
	} return s;
}
