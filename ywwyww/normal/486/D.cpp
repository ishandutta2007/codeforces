#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
#include<utility>
using namespace std;
typedef long long ll;
ll mod=1000000007;
ll f[2010];
int a[2010];
int b[2010];
list<int> l[2010];
int now;
int d,n;
void dfs(int x,int fa)
{
	f[x]=1;
	for(auto v:l[x])
		if(v!=fa&&!b[v]&&a[v]>=a[now]-d)
		{
			dfs(v,x);
			f[x]=f[x]*(f[v]+1)%mod;
		}
}
pair<int,int> c[2010];
int main()
{
	scanf("%d%d",&d,&n);
	int i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		c[i].first=a[i];
		c[i].second=i;
	}
	int lx,ly;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&lx,&ly);
		l[lx].push_back(ly);
		l[ly].push_back(lx);
	}
	sort(c+1,c+n+1,greater<pair<int,int> >());
	memset(b,0,sizeof b);
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		now=c[i].second;
		dfs(c[i].second,0);
		b[c[i].second]=1;
		ans+=f[c[i].second];
		ans%=mod;
	}
	printf("%I64d\n",ans);
	return 0;
}