#include<bits/stdc++.h>
#define ll long long
#define xxx 1001000
using namespace std;
ll n,m,a,q,an[xxx],mod,jc[xxx]={0},ny[xxx]={0},sc[xxx]={0};

ll K(ll x,ll y){
	ll z=1;
	for (;y;y>>=1){
		if (y&1){
			z=(z*x)%mod;
		}
		x=(x*x)%mod;
	}
	return z;
}
ll C(ll x,ll y){
	if (x<y) return 0;
	return jc[x]*ny[x-y]%mod*ny[y]%mod;
}

int main(){
	cin>>n>>m>>a>>q;
	an[0]=1;
	for (an[mod=1]=a;1;){
		a=(an[++mod]=a*an[1]%q);
		if (a==1) break;
	}
	
	ll mx=min(1000000ll,mod-1);
	jc[0]=1;
	for (ll i=1;i<=mx;i++){
		jc[i]=jc[i-1]*i%mod;
	}
	ny[mx]=K(jc[mx],mod-2);
	for (ll i=mx-1;i>=0;i--){
		ny[i]=(ny[i+1]*(i+1))%mod;
	}
	for (ll i=0;i<=n;i++){
		sc[i]=C(m,i);
		//printf(" %lld",sc[i]);
	}//printf(" (mod %lld)\n",mod);
	for (ll i=1;i<=n;i++){
		sc[i]=(sc[i-1]+sc[i])%mod;
	}
	for (ll i=1;i<=n;i++){
		printf("%I64d ",an[sc[n-i]]);
	}
}