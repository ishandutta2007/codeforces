#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll n,k,f[1001000],jc[1001000],ans=0;

ll K(ll x,int y=mod-2){
	ll t=1; for (;y;x=x*x%mod,y>>=1) if (y&1) t=t*x%mod; return t;
}
ll C(int x,int y){
	return x<y? 0: jc[x]*K(jc[y])%mod *K(jc[x-y])%mod;
}

int main(){
	cin>>n>>k;
	jc[0]=1; for (int i=1;i<=n;i++) jc[i]=jc[i-1]*i%mod;
	for (int i=1,j;i<n;i++){
		f[i]=f[i-1]*i%mod;
		if ((j=i-k-1)>=0) (f[i]+=(jc[j]+mod-f[j])*jc[k]%mod *C(i-1,k)%mod )%=mod;
		(ans+=f[i]*C(n-1,i)%mod*jc[n-i-1])%=mod;
	}
	cout<<ans;
}