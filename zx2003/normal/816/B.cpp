#include<cstdio>
#include<cctype>
inline int getint(){
	int x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	for(;isdigit(c);c=getchar())x=x*10+c-48;
	return x;
}
int buf[10];
inline void putint(int x){
	if(!x)putchar('0');
		else{
			int xb=0;
			for(;x;x/=10)buf[++xb]=x%10;
			for(;xb;--xb)putchar(buf[xb]+48);
		}
}
const int N=200010,M=N-10;
int l,r,n,i,q,k,a[N],b[N];
int main(){
	scanf("%d%d%d",&n,&k,&q);
	for(i=1;i<=n;++i){
		l=getint();
		r=getint();
		++a[l];
		--a[r+1];
	}
	for(i=1;i<=M;++i){
		a[i]+=a[i-1];
		b[i]=b[i-1]+(a[i]>=k);
	}
	while(q--){
		l=getint();
		r=getint();
		putint(b[r]-b[l-1]);
		putchar('\n');
	}
	return 0;
}