#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e5+5;
int T,n,m,f[2][2];
const int mod=1e9+7;
ll ksm(ll a,int b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod;b>>=1;
	}
	return ans;
}
signed main(){
//	freopen("a.in","r",stdin);
	T=read();
	while(T--)
	{
		memset(f,0,sizeof(f));
		n=read(),m=read();
		f[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			f[i&1][1]=(f[(i-1)&1][0]+f[(i-1)&1][1])%mod;
			f[i&1][0]=(f[(i-1)&1][0]+f[(i-1)&1][1])%mod;
//			cout<<f[i&1][1]<<" "<<f[i&1][0]<<'\n';
		}
		if(!(n&1))f[n&1][0]--;
		if(m==0){puts("1");continue;}
		ll now=1,ans=0;
//		cout<<ksm(2,m)<<" "<<f[n&1][0]<<"\n";
		for(int i=m-1;i>=0;i--)
		{
			ll to=0;
			if(!(n&1))ans+=now*ksm(2,1ll*n*(i)%(mod-1))%mod,ans%=mod;//1,0
			if(n&1)to+=now;//11
			to+=now*f[n&1][0]%mod,to%=mod;
			now=to;
		}
		ans+=now,ans%=mod;
		cout<<(long long)ans<<"\n";
	}
	return 0;
}