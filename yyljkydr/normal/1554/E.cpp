#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7,P=998244353;

#define int long long

int T,n;

vector<int>g[N];

int fac[N],f[N],inv[N],to[N];

int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}

void dfs(int x,int F,int b)
{
	int tot=0;
	for(auto v:g[x])
	{
		if(v==F)
			continue;
		dfs(v,x,b);
		tot++;
	}
	if(to[x]%b==0)
		to[F]++;
	else if((to[x]+1)%b!=0)
		f[b]=0;
}

signed main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		for(int i=1;i<=n;i++)
			g[i].clear(),f[i]=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%lld%lld",&u,&v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		fac[0]=1;
		for(int i=1;i<=n;i++)
			fac[i]=fac[i-1]*i%P;
		inv[n]=qpow(fac[n],P-2);
		for(int i=n-1;i>=0;i--)
			inv[i]=inv[i+1]*(i+1)%P;
		int ans=0;
		f[1]=qpow(2,n-1);
		for(int i=2;i<=n-1;i++)
			if((n-1)%i==0)
			{
				for(int j=1;j<=n;j++)
					to[j]=0;
				f[i]=1;
				dfs(1,0,i);
			}
		for(int i=n;i>=1;i--)
			for(int j=i*2;j<=n;j+=i)
				f[i]=(f[i]-f[j]+P)%P;
		for(int i=1;i<=n;i++)
			printf("%lld%c",f[i]," \n"[i==n]);
	}
}