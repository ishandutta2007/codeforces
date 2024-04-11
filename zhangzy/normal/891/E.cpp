#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int n,k,f[5200],inv,x;

int fix(ll x){
	return (x%mod+mod)%mod;
}
int K(ll x,int y){
	ll t=1; for (;y;y>>=1,x=fix(x*x)) if (y&1) t=fix(t*x); return t;
}

int main(){
	cin>>n>>k; inv=K(n,mod-2);
	for (int i=f[0]=1;i<=n;i++){
		cin>>x;
		for (int j=i;j>0;j--)
			f[j]=fix(f[j]+(ll)f[j-1]*x);
	}
	ll ans=0,pth=1,fl=-1,dep=0;
	for (int i=n;i>=0;i--){
		ans=fix(ans+(fl=-fl)*f[i]*pth%mod*K(inv,dep));
		pth=fix(pth*(k-dep++));
	}
	cout<<fix(f[n]-ans);
}