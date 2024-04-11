#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,i,j;
ll h,a,l,r,m;
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%lld",&h),a+=h;
	l=0,r=1e12,m;
	for(;l<r;){
		m=l+r>>1;
		if(1ll*(m+m+n-1)*n/2>=a)r=m;else l=m+1;
	}
	m=l;if(1ll*(m+m+n-1)*n/2==a){for(i=1;i<=n;++i)printf("%lld%c",m+i-1,i==n?'\n':' ');return 0;}
	for(i=1;i<n;++i){
		l=0,r=1e12,m;
		auto F=[&](ll x){return 1ll*((x-i+1)+(x-i+1)+n-2)*(n-1)/2+x;};
		for(;l<r;){
			m=l+r>>1;
			if(F(m)>=a)r=m;else l=m+1;
		}
		if(F(l)==a){
			for(j=1;j<=i;++j)printf("%lld%c",l-(i-j),j==n?'\n':' ');
			for(;j<=n;++j)printf("%lld%c",l+(j-i-1),j==n?'\n':' ');
			break;
		}
	}
}