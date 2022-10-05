#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,m,T,x,y,a[101000];
map<ll,ll>phi;

ll GP(ll x){
	if (phi.count(x)) return phi[x];
	ll res=x,z=x;
	for (ll i=2;i*i<=x;++i) if (x%i==0){
		for (;x%i==0;) x/=i;
		res=res/i*(i-1);
	}
	if (x>1) res=res/x*(x-1);
	return phi[z]=res;
}

ll K(ll x,ll y,ll mod){
	ll res=1,fl=pow(x+0.,y)>mod-0.5;
	for (;y;y>>=1,x=x*x%mod) if (y&1) res=res*x%mod;
	return res+fl*mod;
}

ll que(int l,int r,ll mod){
	if (l==r) return a[l];
	if (mod==1) return 1;
	return K(a[l],que(l+1,r,GP(mod)),mod);
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=n;++i) scanf("%I64d",&a[i]);
	for (cin>>T;T--;){
		scanf("%I64d%I64d",&x,&y);
		printf("%I64d\n",que(x,y,m)%m);
	}
}