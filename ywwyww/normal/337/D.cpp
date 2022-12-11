#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<list>
#include<vector>
using namespace std;
typedef long long ll;
list<int> l[100010];
int down[100010];
int up[100010];
int a[100010];
void dfs(int x,int f)
{
	if(a[x])
		down[x]=0;
	else
		down[x]=0x80000000;
	for(auto v:l[x])
		if(v!=f)
		{
			dfs(v,x);
			down[x]=max(down[x],down[v]+1);
		}
	if(down[x]<0)
		down[x]=0x80000000;
}
void dfs2(int x,int f,int d)
{
//	printf("%d\n",x);
	up[x]=d;
	int cnt=0;
	for(auto v:l[x])
		if(v!=f)
			cnt++;
	vector<int> pre(cnt+5),suf(cnt+5),c(cnt+5);
	cnt=0;
	for(auto v:l[x])
		if(v!=f)
		{
			c[++cnt]=v;
			pre[cnt]=suf[cnt]=down[v];
		}
	int i;
	for(i=2;i<=cnt;i++)
		pre[i]=max(pre[i],pre[i-1]);
	for(i=cnt-1;i>=1;i--)
		suf[i]=max(suf[i],suf[i+1]);
	pre[0]=suf[cnt+1]=0x80000000;
	for(i=1;i<=cnt;i++)
	{
		int k=max(max(pre[i-1],suf[i+1])+1,d);
		if(a[x])
			k=max(k,0);
		k++;
		if(k<0)
			k=0x80000000;
		if(a[c[i]])
			k=max(k,0);
		dfs2(c[i],x,k);
	}
}
int main()
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	int i;
	memset(a,0,sizeof a);
	int lx,ly;
	for(i=1;i<=m;i++)
	{
		scanf("%d",&lx);
		a[lx]=1;
	}
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&lx,&ly);
		l[lx].push_back(ly);
		l[ly].push_back(lx);
	}
	dfs(1,0);
	dfs2(1,0,0x80000000);
	int ans=0;
	for(i=1;i<=n;i++)
		if(down[i]<=d&&up[i]<=d)
			ans++;
	printf("%d\n",ans);
	return 0;
}