#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<utility>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
struct uni
{
	int f[200010];
	int find(int x)
	{
		return f[x]==x?x:f[x]=find(f[x]);
	}
	void merge(int x,int y)
	{
		f[find(x)]=find(y);
	}
};
uni un;
list<pii> l[200010];
ll dp[200010];
int f[200010];
int d[200010];
int fsum[200010];
int vis[200010];
ll dfs(int x,int fa,int dep,int sum2)
{
	fsum[x]=sum2;
	d[x]=dep;
	ll s=0;
	f[x]=fa;
	dp[x]=0;
	for(auto v:l[x])
		if(v.first!=fa&&!vis[v.first])
		{
			s=max(s,dfs(v.first,x,dep+1,v.second));
			s=max(s,dp[x]+dp[v.first]+v.second);
			dp[x]=max(dp[x],dp[v.first]+v.second);
		}
	return s;
}
int a1[200010];
int a2[200010];
int cnt1,cnt2;
ll presum1[200010];
ll presum2[200010];
ll pref[200010];
ll suff[200010];
ll premax[200010];
ll sufmax[200010];
ll f1[200010];
ll f2[200010];
int main()
{
//	freopen("f.in","r",stdin);
//	freopen("f.out","w",stdout);
	memset(vis,0,sizeof vis);
	int n;
	scanf("%d",&n);
	int x,y,z;
	int i;
	for(i=1;i<=n;i++)
		un.f[i]=i;
	int sx,sy,sz;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(un.find(x)!=un.find(y))
		{
			l[x].push_back(pii(y,z));
			l[y].push_back(pii(x,z));
			un.merge(x,y);
		}
		else
		{
			sx=x;
			sy=y;
			sz=z;
		}
	}
	ll ans=dfs(1,0,1,0);
	ll ans2=0;
	cnt1=cnt2=0;
	int last=0;
	while(sx!=sy)
	{
		if(d[sx]>d[sy])
		{
			a1[++cnt1]=sx;
			presum1[cnt1]=last;
			last=fsum[sx];
			sx=f[sx];
		}
		else
		{
			a2[++cnt2]=sy;
			presum2[cnt2]=fsum[sy];
			sy=f[sy];
		}
	}
	a1[++cnt1]=sx;
	presum1[cnt1]=last;
	while(cnt2)
	{
		cnt1++;
		a1[cnt1]=a2[cnt2];
		presum1[cnt1]=presum2[cnt2];
		cnt2--;
	}
	for(i=2;i<=cnt1;i++)
		presum1[i]+=presum1[i-1];
	for(i=1;i<=cnt1;i++)
		vis[a1[i]]=1;
	ll sum=presum1[cnt1];
	for(i=1;i<=cnt1;i++)
	{
		ll ans3=dfs(a1[i],0,1,0);
		ans2=max(ans2,ans3);
		f1[i]=presum1[i]+dp[a1[i]];
		f2[i]=sum-presum1[i]+dp[a1[i]];
	}
	for(i=2;i<=cnt1;i++)
		f1[i]=max(f1[i],f1[i-1]);
	for(i=cnt1-1;i>=1;i--)
		f2[i]=max(f2[i],f2[i+1]);
	premax[0]=sufmax[cnt1+1]=0;
	pref[0]=suff[cnt1+1]=0;
	presum1[0]=0;
	presum1[cnt1+1]=presum1[cnt1];
	for(i=1;i<=cnt1;i++)
	{
		premax[i]=max(premax[i-1],pref[i-1]+dp[a1[i]]+presum1[i]-presum1[i-1]);
		pref[i]=max(dp[a1[i]],pref[i-1]+presum1[i]-presum1[i-1]);
	}
	for(i=cnt1;i>=1;i--)
	{
		sufmax[i]=max(sufmax[i+1],suff[i+1]+dp[a1[i]]+presum1[i+1]-presum1[i]);
		suff[i]=max(dp[a1[i]],suff[i+1]+presum1[i+1]-presum1[i]);
	}
	for(i=1;i<cnt1;i++)
	{
		ll s=f1[i]+f2[i+1]+sz;
		s=max(s,ans2);
		s=max(s,max(premax[i],sufmax[i+1]));
		ans=min(ans,s);
	}
	printf("%I64d\n",ans);
	return 0;
}