#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll n,k,f[2002000],ans,tot;
ll fix(ll &x){
	return x=(x%mod+mod)%mod;
}
ll K(ll x,int y=n){
	ll t=1;
	for (;y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
	return t;
}
int main(){
	cin>>n>>k;
	for (int i=1;i<=k;++i){
		f[i]+=K(i)-K(i-1);
		ans+=i^fix(tot+=fix(f[i]));
		for (int j=i+i;j<=k;j+=i)
			f[j]-=f[i];
	}
	cout<<ans%mod;
}