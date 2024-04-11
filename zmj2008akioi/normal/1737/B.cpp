#include <cstdio>
typedef long long LL;
int T;LL l,r;
template<typename T>T sq(T x){return x*x;}
template<typename T>T md(T x,T y){return (x+y)/2;}
LL sqrt(LL x){
	LL mid,l=0,r=1e9+1;
	while(l!=r){
		mid=md(l,r+1);
		if(sq(mid)<=x)l=mid;
		else r=mid-1;
	}
	return l;
}
LL calc(LL x){
	LL p=sqrt(x),q=sq(p);
	return 3*(p-1)+(x>=q)+(x>=q+p)+(x>=q+2*p);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",calc(r)-calc(l-1));
	}
	return 0;
}