#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=110,M=110,D=10;
struct edge
{
	int u,v,c;
}e[M]={};
bool edge_cmp(const edge &e1,const edge &e2)
{
	return e1.c<e2.c;
}
int n,m,last[N]={},next[M+M]={},end[M+M]={},total_edge=0;
int v[N]={},now=0,q[N]={},stot=0;
vector<int> f[N];
bool in[N/D+5][N]={};
set<int> last_del;
inline void add_edge(int u,int v)
{
	next[++total_edge]=last[u];
	last[u]=total_edge;
	end[total_edge]=v;
	last_del.insert(u);
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].c);
	sort(e+1,e+m+1,edge_cmp);
}
void bfs(int s)
{
	int head=0,tail=0;
	q[++tail]=s;
	v[s]=now;
	while(head!=tail)
		for(int s=q[++head],i=last[s];i;i=next[i])
			if(v[end[i]]!=now)
				v[end[i]]=now,q[++tail]=end[i];
	sort(q+1,q+tail+1);
	if(tail<=D)
		for(int i=1;i<=tail;++i)
			for(int j=i+1;j<=tail;++j)
				f[q[i]].push_back(q[j]);
	else
	{
		++stot;
		for(int i=1;i<=tail;++i)
			in[stot][q[i]]=true;
	}
}
void color_calc(int l,int r)
{
	for(set<int>::iterator it=last_del.begin();it!=last_del.end();++it)
		last[*it]=0;
	last_del.clear();
	total_edge=0;
	for(int j=l;j<=r;++j)
		add_edge(e[j].u,e[j].v),add_edge(e[j].v,e[j].u);
	++now;
	for(int j=l;j<=r;++j)
		if(v[e[j].u]!=now)
			bfs(e[j].u);
}
void work()
{
	int last=1;
	for(int i=1;i<=m;++i)
		if(e[i].c!=e[last].c)
		{
			color_calc(last,i-1);
			last=i;
		}
	color_calc(last,m);
	for(int i=1;i<=n;++i)
		sort(f[i].begin(),f[i].end());
}
void query()
{
	int q,u,w;
	//for(int i=1;i<=atot;++i)
	//	cout<<a[i].first<<' '<<a[i].second<<endl;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&u,&w);
		if(u>w)
			swap(u,w);
		int ans=upper_bound(f[u].begin(),f[u].end(),w)-
				lower_bound(f[u].begin(),f[u].end(),w);
		for(int i=1;i<=stot;++i)
			if(in[i][u] && in[i][w])
				++ans;
		printf("%d\n",ans);
	}
}
int main()
{	
	init();
	work();
	query();
	return 0;
}