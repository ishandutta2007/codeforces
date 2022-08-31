#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100010

using namespace std;

struct BIT
{
	vector <int> bit[SIZE];
	int n;
	
	void add(int k,int x)
	{
		while(k<=n)
		{
			bit[k].push_back(x);
			k+=k&-k;
		}
	}
	void built()
	{
		for(int i=0;i<SIZE;i++) sort(bit[i].begin(),bit[i].end());
	}
	int num(int k,int x)
	{
		int ret=0;
		while(k>0)
		{
			ret+=upper_bound(bit[k].begin(),bit[k].end(),x)-lower_bound(bit[k].begin(),bit[k].end(),x);
			k-=k&-k;
		}
		return ret;
	}
	int num(int a,int b,int k)
	{
		return num(b,k)-num(a-1,k);
	}
};
BIT bit;
int par[SIZE][20];
vector <int> vec[SIZE];
int vx[SIZE],dep[SIZE],mxch[SIZE],id[SIZE];
bool use[SIZE];
int n,k;

int dfs(int v,int d)
{
	vx[k]=v;
	dep[k]=d;
	id[v]=k;
	mxch[v]=k;k++;
	for(int i=0;i<vec[v].size();i++) mxch[v]=max(mxch[v],dfs(vec[v][i],d+1));
	return mxch[v];
}
void make()
{
	for(int i=1;i<20;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(par[j][i-1]==-1) par[j][i]=-1;
			else par[j][i]=par[par[j][i-1]][i-1];
		}
	}
	memset(use,false,sizeof(use));
	k=0;
	for(int i=0;i<n;i++) if(!use[i]&&par[i][0]==-1) dfs(i,0);
	bit.n=n+5;
	for(int i=0;i<k;i++) bit.add(i+1,dep[i]);
	bit.built();
}
int parent(int v,int p)
{
	for(int i=19;i>=0;i--)
	{
		if(v==-1) return -1;
		if(p>>i&1) v=par[v][i];
	}
	return v;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int p;
		scanf("%d",&p);p--;
		par[i][0]=p;
		if(p!=-1) vec[p].push_back(i);
	}make();
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int v,p;
		scanf("%d %d",&v,&p);v--;
		int tp=parent(v,p);
		if(tp==-1)
		{
			printf("%d\n",0);
			continue;
		}
		int s=id[tp],e=mxch[tp];
		//printf("%d %d %d\n",s,e,dep[id[v]]);
		printf("%d\n",bit.num(s+1,e+1,dep[id[v]])-1);
	}
	return 0;
}