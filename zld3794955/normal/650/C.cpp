#include<bits/stdc++.h>
using namespace std;
const int N=1000100,Inf=N;
vector<int> v[N],num[N],tmp;
int n,m,k=0,p[N]={};
bool cmp(int x,int y)
{
	return tmp[x]<tmp[y];
}
int last[N]={},next[N*8]={},end[N*8]={},total_edge=1;
int dis[N]={},root[N]={};
inline int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
}
void init()
{
	scanf("%d%d",&n,&m);
	//n=1000,m=1000;
	for(int i=1;i<=n;++i)
	{
		v[i].resize(m+1);
		num[i].resize(m+1);
		for(int j=1;j<=m;++j)
		{
			//v[i][j]=rand();
			scanf("%d",&v[i][j]);
			num[i][j]=++k;
		}
	}
	for(int i=1;i<=k;++i)
		root[i]=i;
	for(int i=1;i<=n;++i)
	{
		tmp=v[i];
		for(int j=1;j<=m;++j)
			p[j]=j;
		sort(p+1,p+m+1,cmp);
		for(int j=2;j<=m;++j)
			if(tmp[p[j]]==tmp[p[j-1]])
				root[get_root(num[i][p[j]])]=get_root(num[i][p[j-1]]);
	}
	for(int j=1;j<=m;++j)
	{
		tmp.resize(1);
		for(int i=1;i<=n;++i)
			tmp.push_back(v[i][j]);
		for(int i=1;i<=n;++i)
			p[i]=i;
		sort(p+1,p+n+1,cmp);
		for(int i=2;i<=n;++i)
			if(tmp[p[i]]==tmp[p[i-1]])
				root[get_root(num[p[i]][j])]=get_root(num[p[i-1]][j]);
	}
	for(int i=1;i<=n;++i)
	{
		tmp=v[i];
		for(int j=1;j<=m;++j)
			p[j]=j;
		sort(p+1,p+m+1,cmp);
		for(int j=2;j<=m;++j)
			if(tmp[p[j]]>tmp[p[j-1]])
				add_edge(get_root(num[i][p[j]]),get_root(num[i][p[j-1]]));
	}
	for(int j=1;j<=m;++j)
	{
		tmp.resize(1);
		for(int i=1;i<=n;++i)
			tmp.push_back(v[i][j]);
		for(int i=1;i<=n;++i)
			p[i]=i;
		sort(p+1,p+n+1,cmp);
		for(int i=2;i<=n;++i)
			if(tmp[p[i]]>tmp[p[i-1]])
				add_edge(get_root(num[p[i]][j]),get_root(num[p[i-1]][j]));
	}
}
int dfs(int s)
{
	if(dis[s])
		return dis[s];
	dis[s]=1;
	for(int i=last[s];i;i=next[i])
		dis[s]=max(dfs(end[i])+1,dis[s]);
	return dis[s];
}
void work()
{
	for(int i=1;i<=k;++i)
		if(get_root(i)==i)
			dfs(i);
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			printf("%d ",dis[get_root(num[i][j])]);
		printf("\n");
	}//*/
	cerr<<clock()<<endl;
}
int main()
{	
	srand(time(0));
	init();
	work();
	return 0;
}