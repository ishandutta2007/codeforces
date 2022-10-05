#include<bits/stdc++.h>
#define se second
#define mb mp.begin()
#define ll long long
#define mod 1000000007
#define U(x,y) x=(x+y)%mod
using namespace std;

int n,m,x,c,tot;
map<int,int>mp;
ll jc[101000],f[101000],ans=0;

ll K(ll x,int y){
	ll t=1; for (;y;x=x*x%mod,y>>=1) if (y&1) t=t*x%mod; return t;
}

ll C(int x,int y){
	return jc[x]* K(jc[y],mod-2)%mod *K(jc[x-y],mod-2)%mod;
}

bool F(int x){
	for (;x;x/=10) if (x%10!=7&&x%10!=4) return 0;
	return 1;
}

int main(){
	jc[0]=1;
	for (int i=1;i<=100000;i++) jc[i]=jc[i-1]*i%mod;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d",&x);
		if (F(x)) mp[x]++,c++;
	}
	c=n-c;
	f[0]=1;
	for (;!mp.empty();mp.erase(mb))
		for (int i=++tot;i>0;i--)
			U(f[i],f[i-1]*mb->se);
	for (int i=max(0,m-c);i<=min(tot,m);i++)
		U(ans,f[i]*C(c,m-i));
	cout<<ans;
}