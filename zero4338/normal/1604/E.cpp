#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
int T;
const int maxn=1e5+5;
const int maxm=325;
const int mod=998244353;
int n,a[maxn],b[maxn],ans;
int val1[maxn][maxm],val2[maxn][maxm];
int dfs(int u,int x)
{
	if(!u)return 0;
	if(x>b[u+1])
	{
		if(~val2[u][a[u+1]/x])return val2[u][a[u+1]/x];
		else return val2[u][a[u+1]/x]=((ll)u*((a[u]-1)/x)%mod+dfs(u-1,a[u]/((a[u]-1)/x+1)))%mod;
	}
	else
	{
		if(~val1[u][x])return val1[u][x];
		else return val1[u][x]=((ll)u*((a[u]-1)/x)%mod+dfs(u-1,a[u]/((a[u]-1)/x+1)))%mod;
	}
}
int main()
{
	T=read();
	while(T--)
	{
		generate_n(a+1,n=read(),read);
		for(int i=1;i<=n-1;i++)
		{
			b[i+1]=sqrt(a[i+1]);
			for(int j=1;j<=b[i+1];j++)val1[i][j]=val2[i][j]=-1;
		}
		ans=0;
		for(int i=1;i<=n;i++)ans=(ans+dfs(i-1,a[i]))%mod;
		printf("%d\n",ans);
	}
	return 0;
}