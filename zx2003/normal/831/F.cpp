#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll n,i,j,a[105],x,ans,l,r,m,k,s;
inline void up(ll&a,ll b){
	if(a>b)a=b;
}
inline ll sum(ll x){
	ll s=0;
	for(ll j=1;j<=n;++j)
		s+=1ll*(a[j]+x-1)/x*x-a[j];
	return s;
}
int main(){
	cin>>n>>k;
	for(i=1;i<=n;++i)cin>>a[i];
	j=n+1;
	for(i=1;x<1ll<<40;i=x+1){
		x=1ll<<40;
		for(j=1;j<=n;++j)if(a[j]>i)up(x,(a[j]-1)/((a[j]-1)/i));
		if(sum(x)<=k)ans=x;
			else if(sum(i)<=k){
				l=i;
				r=x;
				while(l<r){		
					m=(l+r+1)>>1;
					if(sum(m)<=k)l=m;
						else r=m-1;
				}
				ans=l;
			}
	}
	cout<<ans<<endl;
	return 0;
}