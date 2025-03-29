#define BRK 214
#define WRITE 64
#define EXIT 93
typedef long long int ll;

ll mypow(ll a,ll b){
	ll i=1;
	while(b){ if(b&1) i*=a;b>>=1; a*=a; }
	return i;
}
ll str2int(char* a){
	ll i=0,b=0;
	while(a[i]!=0){ b=b*10+(a[i++]-'0');} // zero, not null, since it is not a convential string
	return b;
}
ll min(ll n){
	return mypow(10,n-2);
}
ll max(ll n){
	return min(n+1)-2;
}
ll lengt(ll a, ll b,ll c){
	return (((b-a)>>1)+1)*c;
}
ll length(ll a , ll b){
	ll da=0,db=0,aa=a,bb=b;
	while(aa!=0){ da+=1;aa/=10; }
	while(bb!=0){ db+=1;bb/=10; }
	if (da==db) { return lengt(a,b,da); }
	ll s = lengt(a,max(da),da); //head
	s=s+lengt(min(db),b,db); // tail
	ll c=mypow(10,da-1);
	for (ll i=da+1;i<db;i++){
		s=s+4*(c*10)+5*c;c*=10; //lengt(min(n),max(n),n)=4*(n-1)+5*(n-2)
	} //body
	return s;
}
long my_syscall2(long n, long a1){
	long r;
	asm volatile (
		"mov x8, %1;mov x0, %2;svc #0;mov %0, x0"
		:"=r" (r)
		:"r" (n) , "r" (a1));
	return r;
}
void my_syscall4(long n, long a1,long a2,long a3){
	asm volatile (
		"mov x8, %0;mov x0, %1;mov x1, %2;mov x2, %3;svc #0"
		::"r"(n) , "r"(a1), "r"(a2), "r"(a3));
}
void _start(){
	ll b,e;long ac,a1,a2,a3; char d;
	asm volatile(
		"ldr %0, [x29, #16];ldr %1, [x29, #32]; ldr %2, [x29, #40];ldr %3, [x29, #48]"
		: "=r"(ac), "=r"(a1), "=r"(a2), "=r"(a3));
	if (ac==4){
		d = *((char *)a1);
		b = str2int((char *)a2);
		e = str2int((char *)a3);
	} else my_syscall2(EXIT,1);

	// range adjustment
	d=(d=='o');
	b+=((b&1) ^ d);
	e-=((e&1) ^ d);

	//buffer fillup
	ll l = lengt(b,e,1)+length(b,e); // #(spaces) + #(digits)
	ll k=l;
	long cc = my_syscall2(BRK,0);
	my_syscall2(BRK,cc+(sizeof (char)*(l++)));
	char *c= (char* )cc;
	for (; e>=b; e-=2){
		ll j=e;
		c[k--]=' ';
		while (j!=0){ 
			c[k--]=(j%10)+'0';
			j/=10; }
	} c[l-1]=012;
	my_syscall4(WRITE,0,(long)c,l); my_syscall2(EXIT,0); }

