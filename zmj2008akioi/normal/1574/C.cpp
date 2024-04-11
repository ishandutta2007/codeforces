#include <cstdio>
#include <algorithm>
int n,m,l,r,mid;
long long atk,def,sum,a[200010];
inline long long min(long long x,long long y){
	return x<y?x:y;
}
inline long long max(long long x,long long y){
	return x>y?x:y;
}
long long div1(){
	l=0,r=n;
	if(a[l]>=def)return 3e18;
	while(r-l>1){
		mid=l+r>>1;
		if(a[mid]>=def)r=mid;
		else l=mid;
	}
	return def-a[l]+max(0,atk-sum+a[l]);
}
long long div2(){
	l=-1,r=n-1;
	if(a[r]<def)return 3e18;
	while(r-l>1){
		mid=l+r>>1;
		if(a[mid]>=def)r=mid;
		else l=mid;
	}
	return max(0,atk-sum+a[r]);
}
int main(){
	scanf("%d",&n);
	for(register int i=0;i<n;++i)scanf("%lld",&a[i]),sum+=a[i];
	std::sort(a,a+n);
	scanf("%d",&m);
	for(register int i=0;i<m;++i){
		scanf("%lld %lld",&def,&atk);
		printf("%lld\n",min(div1(),div2()));
	}
	return 0;
}