#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005
#define BT 20

using namespace std;

vector <int> vec[SIZE];
int G[SIZE],nd[SIZE];
int par[SIZE][BT];
int mx[SIZE];
int n;

void dfs(int v=0,int p=-1)
{
	nd[v]=1;
	par[v][0]=p;
	mx[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			nd[v]+=nd[to];
			mx[v]=max(mx[v],nd[to]);
		}
	}
}
void make()
{
	for(int i=0;i+1<BT;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
//gvdS <=> mx[g]<=nd[v]-mx[g] && nd[v]-nd[g]<=nd[g] <=> mx[g]*2<=nd[v]<=2*nd[g]
void solve()
{
	memset(G,-1,sizeof(G));
	for(int i=0;i<n;i++)
	{
		int low=i,up=i;
		for(int j=BT-1;j>=0;j--)
		{
			if(par[low][j]!=-1&&nd[par[low][j]]<mx[i]*2) low=par[low][j];
			if(par[up][j]!=-1&&nd[par[up][j]]<=nd[i]*2) up=par[up][j];
		}
		if(low==i&&nd[low]>=mx[i]*2) G[i]=i;
		while(low!=up)
		{
			low=par[low][0];
			if(low==-1) break;
			G[low]=i;
		}
	}
}
int main()
{
	int m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int p;
		scanf("%d",&p);p--;
		vec[p].push_back(i+1);
	}
	dfs();
	make();
	solve();
	for(int i=0;i<m;i++)
	{
		int c;
		scanf("%d",&c);c--;
		printf("%d\n",G[c]+1);
	}
	return 0;
}