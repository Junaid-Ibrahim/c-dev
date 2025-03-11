#include<unistd.h>
int mypow(int a,int b){
	int i=1;
	for(;b>=0;b--){ i*=a;}
	return i;
}
char * int2str(int a){
	int b=a,e=0,r;
	while (a!=0){ e+=1;a/=10;}
	char *f=(char *)sbrk((sizeof (char))*(e+1));
	f[e]='\0';
	while (b!=0){ r=b%10;b/=10; f[--e]=r+48;}
	return f;
}
int str2int(char* a){
	int i=0,b=0;
	while(a[i]!='\0'){ b=b*10+(a[i++]-48);}
	return b;
}
int max(int n){
	int s=8;
	for (--n;n>0;n--){ s+=9*mypow(10,n);}
	return s;
}
int min(int n){
	return mypow(10,--n);
}
int lengt(int a, int b, int c){
	return (((b-a)/2)+1)*c;
}
int length(int a , int b){
	int e=0,f=0,c=a,d=b;
	while(c!=0){ e+=1;c/=10;}
	while(d!=0){ f+=1;d/=10;}
	if (e==f) { return lengt(a,b,e); }
	int s = lengt(a,max(e),e);
	s=s+lengt(min(f),b,f);
	for (int i=e+1;i<f;i++){
		s=s+5*mypow(10,i-2)+4*mypow(10,i-1);
	} return s;
}
