#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <set>
#define SIZE 300005

using namespace std;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF uf;
vector <int> vec[SIZE];
bool dm[SIZE];
set <int> zan;
set <int>::iterator it;

int main()
{
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		if(a>b) swap(a,b);
		if(a==0) dm[b]=true;
		else
		{
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
	}
	uf.init(n+2);
	for(int i=1;i<n;i++) zan.insert(i);
	int all=0;
	for(int i=1;i<n;i++)
	{
		if(zan.count(i))
		{
			all++;
			queue <int> que,pl;
			que.push(i);
			zan.erase(i);
			while(!que.empty())
			{
				int v=que.front();que.pop();
				for(int j=0;j<vec[v].size();j++)
				{
					int to=vec[v][j];
					if(zan.count(to))
					{
						pl.push(to);
						zan.erase(to);
					}
				}
				for(it=zan.begin();it!=zan.end();it++)
				{
					uf.unite(v,*it);
					que.push(*it);
				}
				zan.clear();
				while(!pl.empty())
				{
					zan.insert(pl.front());
					pl.pop();
				}
			}
		}
	}
	int cnt=0;
	for(int i=1;i<n;i++)
	{
		if(!dm[i])
		{
			cnt++;
			uf.unite(i,0);
		}
	}
	bool up=true;
	for(int i=1;i<n;i++) if(!uf.same(0,i)) up=false;
	if(cnt<k||all>k||!up)
	{
		puts("impossible");
		return 0;
	}
	puts("possible");
	return 0;
}