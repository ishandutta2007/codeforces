#include <cstdio>
typedef long double LD;
const int N=1e5+10;
const LD eps=1e-7;
int T,n,a[N],t[N];
template<typename T>T rv(T x){return x>T()?x:-x;}
template<typename T>void cmax(T &x,T y){if(x<y)x=y;}
LD check(LD x){
	LD res=0;
	for(int i=1;i<=n;++i)cmax(res,rv(x-a[i])+t[i]);
	return res;
}
LD bsc(){
	LD a,b,l=0,r=1e8;
	while(r-l>eps){
		a=(2*l+r)/3,b=(l+2*r)/3;
		if(check(a)<check(b))r=b;
		else l=a;
	}
	return l;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)scanf("%d",&t[i]);
		printf("%.8Lf\n",bsc());
	}
	return 0;
}