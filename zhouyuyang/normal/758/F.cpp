#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l,r,n,ans,m,a,b;
ll power(ll x,ll y){
	ll s=1;
	for (;y;y/=2,x=x*x)
		if (y&1) s=s*x;
	return s;
}
int main(){
	scanf("%lld%lld%lld",&n,&l,&r);
	if (n==1) return printf("%lld\n",r-l+1),0;
	if (n>25) return printf("%d\n",0),0;
	if (n==2) return printf("%lld",(r-l+1)*(r-l)),0;
	m=pow(2,log2(1e8)/(n-1));
	m=min(m,3200LL);
	for(ll i=1;i<=m;i++)
		for(ll j=i+1;j<=m;j++)
			if(__gcd(i,j)==1){
				a=power(j,n-1);
				b=power(i,n-1);
				if(l*a/b<=r)
					ans+=(r*b/a)/b-(l-1)/b;
			}
	cout<<ans*2;
}