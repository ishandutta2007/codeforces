#include<bits/stdc++.h>
using namespace std;
const int N=200200,M=400400,L=0,R=1,Unknown=0;
struct query
{
	int type,a,b;
}t[M];
int n,m;
int l[N]={},r[N]={},tot=0,root[N]={},qtot=0,dtot=0,ans[M]={};
bool to[N]={};
vector<pair<int,int> > q[M];
vector<int> son[N];
int get_root(int r)
{
	if(r!=root[r])
		root[r]=get_root(root[r]);
	return root[r];
}
void init()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",&t[i].type);
		if(t[i].type==1)
			scanf("%d%d",&t[i].a,&t[i].b);
		if(t[i].type==2)
			scanf("%d",&t[i].a);
		if(t[i].type==3)
			scanf("%d%d",&t[i].a,&t[i].b);
	}
	for(int i=1;i<=n;++i)
		root[i]=i;
}
void dfs(int s)
{
	l[s]=++tot;
	for(int i=0;i<(int)son[s].size();++i)
		dfs(son[s][i]);
	r[s]=tot;
}
void make_final_tree()
{
	for(int i=1;i<=m;++i)
		if(t[i].type==1)
		{
			son[t[i].b].push_back(t[i].a);
			to[t[i].a]=true;
		}
	for(int i=1;i<=n;++i)
		if(!to[i])
			dfs(i);
}
void process()
{
	for(int i=1;i<=m;++i)
		if(t[i].type==3)
			q[t[i].b].push_back(make_pair(t[i].a,++qtot));
	dtot=0;
	for(int i=1;i<=m;++i)
	{
		if(t[i].type==1)
			root[get_root(t[i].a)]=get_root(t[i].b);
		if(t[i].type==2)
			for(vector<pair<int,int> >::iterator it=q[++dtot].begin();
				it!=q[dtot].end();++it)
				ans[it->second] = 
				(l[it->first]<=l[t[i].a] && r[t[i].a]<=r[it->first]
				&& get_root(t[i].a)==get_root(it->first));
	}
	for(int i=1;i<=qtot;++i)
		puts(ans[i] ? "YES" : "NO");
}
int main()
{	
	init();
	make_final_tree();
	process();
	return 0;
}