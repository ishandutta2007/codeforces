#include<bits/stdc++.h>
using namespace std;
struct Edge
{
	int fr,to,val;
	bool operator<(const Edge& ano)const
	{
		return val<ano.val;
	}
}e[1000001];
int fa[100001];
int Root(int x)
{
	return fa[x]==x?x:fa[x]=Root(fa[x]);
}
struct EE
{
	int to,val;
	EE(int t,int v):to(t),val(v){}
};
vector<EE> g[100001];
int s,t;
void dfs(int u,int f,int m)
{
	if(u==t)
	{
		printf("%d\n",m);
		exit(0);
	}
	for(vector<EE>::iterator iter=g[u].begin();iter!=g[u].end();iter++)
		if(iter->to!=f)
			dfs(iter->to,u,max(m,iter->val));
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	if(m == n-1) {
		printf("1000000000\n");
		return 0;
	}
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&e[i].fr,&e[i].to,&e[i].val);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	sort(e+2,e+m+1);
	int cnt=0;
	for(int i=2;i<=m;i++)
	{
		int rx=Root(e[i].fr),ry=Root(e[i].to);
		if(rx!=ry)
		{
			fa[rx]=ry;
			g[e[i].fr].push_back(EE(e[i].to,e[i].val));
			g[e[i].to].push_back(EE(e[i].fr,e[i].val));
			if(++cnt==n-1)
				break;
		}
	}
	s=e[1].fr;
	t=e[1].to;
	dfs(s,0,0);
	return 0;
}