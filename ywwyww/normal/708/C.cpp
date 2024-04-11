#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<queue>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=1000010;
struct tree
{
	int v[maxn];
	int t[maxn];
	int h[maxn];
	int n;
	tree()
	{
		memset(v,0,sizeof v);
		memset(t,0,sizeof t);
		memset(h,0,sizeof h);
		n=0;
	}
	void add(int x,int y)
	{
		n++;
		v[n]=y;
		t[n]=h[x];
		h[x]=n;
	}
};
tree a;
int n;
int sz[maxn];
int ans[maxn];
int up[maxn];
int down[maxn];
int f1[maxn];
int f2[maxn];
void dfs(int x,int f)
{
	sz[x]=1;
	int i;
	for(i=a.h[x];i;i=a.t[i])
		if(a.v[i]!=f)
		{
			dfs(a.v[i],x);
			sz[x]+=sz[a.v[i]];
		}
}
void dfs1(int x,int f)
{
	f1[x]=0;
	int i;
	int s=1;
	for(i=a.h[x];i;i=a.t[i])
		if(a.v[i]!=f)
		{
			dfs1(a.v[i],x);
			if(sz[a.v[i]]>n/2)
			{
				if(sz[a.v[i]]-f1[a.v[i]]>n/2)
					s=0;
			}
			f1[x]=max(f1[x],f1[a.v[i]]);
		}
	down[x]=s;
	if(sz[x]<=n/2)
		f1[x]=max(f1[x],sz[x]);
}
void dfs2(int x,int f,int d)
{
	int i;
	int cnt=0;
	for(i=a.h[x];i;i=a.t[i])
		if(a.v[i]!=f)
			cnt++;
	vector<int> pre(cnt+10);
	vector<int> suf(cnt+10);
	vector<int> v(cnt+10);
	cnt=0;
	for(i=a.h[x];i;i=a.t[i])
		if(a.v[i]!=f)
			v[++cnt]=a.v[i];
	for(i=1;i<=cnt;i++)
		pre[i]=suf[i]=f1[v[i]];
	for(i=2;i<=cnt;i++)
		pre[i]=max(pre[i],pre[i-1]);
	for(i=cnt-1;i>=1;i--)
		suf[i]=max(suf[i],suf[i+1]);
	pre[0]=suf[cnt+1]=0;
	for(i=1;i<=cnt;i++)
	{
		if(n-sz[v[i]]<=n/2)
			up[v[i]]=1;
		else
		{
			int p=max(max(d,pre[i-1]),suf[i+1]);
			if(n-sz[v[i]]-p<=n/2)
				up[v[i]]=1;
		}
	}
	for(i=1;i<=cnt;i++)
	{
		int k=d;
		k=max(max(pre[i-1],suf[i+1]),k);
		if(n-sz[v[i]]<=n/2)
			k=max(k,n-sz[v[i]]);
		dfs2(v[i],x,k);
	}
}
int main()
{
//	freopen("cf708c.in","r",stdin);
//	freopen("cf708c.out","w",stdout);
	int lx,ly;
	scanf("%d",&n);
	int i;
	for(i=1;i<n;i++)
	{
		scanf("%d%d",&lx,&ly);
		a.add(lx,ly);
		a.add(ly,lx);
	}
	memset(f1,0,sizeof f1);
	memset(f2,0,sizeof f2);
	memset(up,0,sizeof up);
	memset(down,0,sizeof down);
	dfs(1,0);
	dfs1(1,0);
	dfs2(1,0,0);
	up[1]=1;
	for(i=1;i<=n;i++)
	{
		ans[i]=down[i]&&up[i];
		printf("%d ",ans[i]);
	}
	printf("\n");
	return 0;
}