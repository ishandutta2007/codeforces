#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll fix(ll &x){
	x=(x%mod+mod)%mod;
}

ll K(ll x,int y=mod-2){
	ll t=1;
	for (fix(x);y;y>>=1,x=x*x%mod) if (y&1) t=t*x%mod;
	return t;
}

ll k,x,y,p1,p2,f[2020][2020],ans=0,t;

ll cal(ll x){
	ll y=K(1-x);
	return x*y%mod*y%mod;
}

int main(){
	cin>>k>>x>>y;
	p1=x*K(x+y)%mod; p2=y*K(x+y)%mod;
	f[0][0]=K(1-p2);
	for (int i=0;i<=k*2;++i){
		for (int j=1;j<=k;++j){
			if (i<k) f[i][j]=f[i][j-1]*p1%mod;
			if (i-j>=0&&i-j<k){
				f[i][j]+=f[i-j][j]*p2%mod;
				fix(f[i][j]);
			}
			if (f[i][j]&&i>=k&&j<k){
				ans+=f[i][j]*i;
				fix(ans);
			}
		}
	}
	cerr<<ans<<endl;
	for (int i=0;i<k;++i) if (t=f[i][k]){
		ans+=t*p2%mod *(i+k)%mod *K(1-p1)%mod;
		ans+=t*p2%mod *cal(p1)%mod;
		fix(ans);
	}
	cout<<ans;
}