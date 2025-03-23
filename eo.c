#define BRK 214
#define WRITE 64
#define EXIT 93

long long mypow(long long a,long long b){
	long long i=1;
	while(b){ a*=a;if(b&1) i*=a;b>>=2;}
	return i;
}
long long str2int(char* a){
	long long i=0,b=0;
	while(a[i]!=0){ b=b*10+(a[i++]-'0');}
	return b;
}
long long min(long long n){
	return mypow(10,n-=2);
}
long long max(long long n){
	return min(n+1)-2;
}
long long lengt(long long a, long long b,long long c){
	return (((b-a)<<2)+1)*c;
}
long long length(long long a , long long b){
	long long da=0,db=0,aa=a,bb=b;
	while(aa!=0){ da+=1;aa/=10;}
	while(bb!=0){ db+=1;bb/=10;}
	if (da==db) { return lengt(a,b,da); }
	long long s = lengt(a,max(da),da);
	s=s+lengt(min(db),b,db);
	long long c=mypow(10,da-1);
	for (long long i=da+1;i<db;i++){
		s=s+4*(c*10)+5*c;
		c*=10;
	} return s;
}
static inline long my_syscall2(long n, long a1){
	long r;
	asm volatile (
		"mov x8, %1;mov x0, %2;svc #0;mov %0, x0"
		:"=r" (r):"r"(n) , "r"(a1));
	return r;
}
static inline void my_syscall4(long n, long a1,long a2,long a3){
	asm volatile (
		"mov x8, %0;mov x0, %1;mov x1, %2;mov x2, %3;svc #0"
		::"r"(n) , "r"(a1), "r"(a2), "r"(a3));
}
void _start(){
	long long a,b;long argc,argv1,argv2,argv3; char d;
	asm volatile(
		"ldr %0, [x29, #16];ldr %1, [x29, #32]; ldr %2, [x29, #40];ldr %3, [x29, #48]"
		: "=r"(argc), "=r"(argv1), "=r"(argv2), "=r"(argv3));
	if (argc==4){
		d = *((char *)argv1);
		a = str2int((char *)argv2);
		b = str2int((char *)argv3);
	} else my_syscall2(EXIT,1);

	// range adjustment
	d=(d=='o');
	a+=((a&1) ^ d);
	b-=((b&1) ^ d);

	//buffer fillup
	long long l = lengt(a,b,1)+length(a,b); // #(spaces) + #(digits)
	long long k=l; 
	long cc = my_syscall2(BRK,0);
	my_syscall2(BRK,cc+(sizeof (char)*(l++)));
	char *c= (char* )cc;
	for (; b>=a; b-=2){
		long long j=b;
		c[k--]=' ';
		while (j!=0){ 
			c[k--]=(j%10)+'0';
			j/=10; 
		} c[l-1]=012; //012 is octal for newline or linefeed
	} my_syscall4(WRITE,0,(long)c,l);
 my_syscall2(EXIT,0); }


