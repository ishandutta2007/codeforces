#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e7+1e3+7,P=1e9+7,M=2e7;

int T,n;

int c[N],f[N],p[N],ptot,vis[N];

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%lld",&x);
		c[x]++;
	}
	for(int i=1;i<=M;i++)
		for(int j=i*2;j<=M;j+=i)
			c[i]+=c[j];
	for(int i=2;i<=M;i++)
	{
		if(!vis[i])
			p[++ptot]=i;
		for(int j=1;j<=ptot&&i*p[j]<=M;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0)
				break;
		}
	}
	for(int i=M;i>=1;i--)
	{
		f[i]=i*c[i];
		for(int j=1;j<=ptot&&i*p[j]<=M;j++)
			f[i]=max(f[i],f[i*p[j]]+(c[i]-c[i*p[j]])*i);
	}
	printf("%lld\n",*max_element(f+1,f+M+1));
}