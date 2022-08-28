#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 400005

using namespace std;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
};
BIT bit;
vector <int> vec[SIZE];
int nd[SIZE];
bool ans[SIZE];
int n;

void dfs(int v=0,int p=-1)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			nd[v]+=nd[to];
		}
	}
}
P center(int v=0,int p=-1)
{
	int mx=n-nd[v];
	P ret=P(SIZE,-1);
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			ret=min(ret,center(to,v));
			mx=max(mx,nd[to]);
		}
	}
	ret=min(ret,P(mx,v));
	return ret;
}
void recalc(int v,int p=-1)
{
	nd[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			recalc(to,v);
			nd[v]+=nd[to];
		}
	}
}
void dfs1(int v,int p=-1)
{
	bit.add(n-nd[v],1);
	if(p!=-1)
	{
		int left=(n-nd[v])-n/2,right=n/2;
		//leftright
		ans[v]|=bit.get(left,right)>=1;
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs1(to,v);
	}
	bit.add(n-nd[v],-1);
	bit.add(nd[v],1);
}
void dfs2(int v,int p=-1)
{
	bit.add(n-nd[v],1);
	if(p!=-1)
	{
		int left=(n-nd[v])-n/2,right=n/2;
		//leftright
		ans[v]|=bit.get(left,right)>=1;
	}
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][vec[v].size()-i-1];
		if(to!=p) dfs1(to,v);
	}
	bit.add(n-nd[v],-1);
	bit.add(nd[v],1);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	int rt=center().second;
	ans[rt]=true;
	recalc(rt);
	bit.init();
	dfs1(rt);
	bit.init();
	dfs2(rt);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}