#include<unistd.h>
long long mypow(long long a,long long b){
	long long i=1;
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
long long str2int(char* a){
	long long i=0,b=0;
	while(a[i]!='\0'){ b=b*10+(a[i++]-48);}
	return b;
}
long long min(long long n){
	return mypow(10,n-=2);
}
long long max(long long n){
	return min(n+1)-2;
}
long long lengt(long long a, long long b,long long c){
	return (((b-a)/2)+1)*c;
}
long long length(long long a , long long b){
	long long da=0,db=0,aa=a,bb=b;
	while(aa!=0){ da+=1;aa/=10;}
	while(bb!=0){ db+=1;bb/=10;}
	if (da==db) { return lengt(a,b,da); }
	long long s = lengt(a,max(da),da);
	s=s+lengt(min(db),b,db);
	for (long long i=da+1;i<db;i++){
		s=s+5*mypow(10,i-2)+4*mypow(10,i-1);
	} return s;
}
