#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int ask(const vector<int>& p)
{
	printf("? %d",(int)p.size());
	for(int i=0;i<(int)p.size();i++)
		printf(" %d",p[i]);
	printf("\n");
	fflush(stdout);
	int x;
	scanf("%d",&x);
	return x;
}
void ans(int a,int b)
{
	printf("! %d %d\n",a,b);
	fflush(stdout);
}
int u[MAXN],v[MAXN];
int loc[MAXN<<1],cnt;
vector<pair<int,int>> e[MAXN];
void dfs(int u,int fa)
{
	for(auto t : e[u])
	{
		int v=t.first;
		if(v==fa)continue;
		loc[++cnt]=t.second;
		dfs(v,u);
		//loc[++cnt]=t.second;
	}
}
int get(int l,int r)
{
	vector<int> p;
	for(int i=l;i<=r;i++)
		p.push_back(u[loc[i]]),p.push_back(v[loc[i]]);
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	return ask(p);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u[i],&v[i]);
		e[u[i]].emplace_back(v[i],i);
		e[v[i]].emplace_back(u[i],i);
	}
	dfs(1,0);
	int l=1,r=cnt,mx=get(l,r);
	while(l<r)
	{
		int m=(l+r)/2;
		if(get(l,m)<mx)l=m+1;
		else r=m;
	}
	ans(u[loc[l]],v[loc[l]]);
	return 0;
}