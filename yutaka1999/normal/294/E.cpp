#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 5005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

struct edge
{
	int to,cost,n;
	edge(int t,int c,int n):to(t),cost(c),n(n){}
};
vector <edge> vec[SIZE];
int a[SIZE],b[SIZE],w[SIZE];
ll es[SIZE][SIZE];
int n;

ll make(int s,int v,int p=-1,ll len=0)
{
	ll sum=len;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p)
		{
			ll plus=make(s,e.to,v,len+e.cost);
			sum+=plus;
			es[s][e.n]=plus;
		}
	}
	return sum;
}
void make()
{
	for(int i=0;i<n;i++)
	{
		ll all=make(i,i);
		for(int j=0;j<n-1;j++) es[i][j]=all-es[i][j];
	}
}
ll dfs(int v,int num,int p)
{
	ll ret=es[v][num];
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) ret=min(ret,dfs(e.to,num,v));
	}
	return ret;
}
int dfs2(int v,int p)
{
	int ret=1;
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		if(e.to!=p) ret+=dfs2(e.to,v);
	}
	return ret;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		scanf("%d %d %d",&a[i],&b[i],&w[i]);a[i]--;b[i]--;
		vec[a[i]].push_back(edge(b[i],w[i],i));
		vec[b[i]].push_back(edge(a[i],w[i],i));
	}
	make();
	ll ret=INF;
	for(int i=0;i<n-1;i++)
	{
		ll cost=0;
		for(int j=0;j<n;j++) cost+=es[j][i];
		cost/=2;
		ll cl=dfs(a[i],i,b[i]);
		ll cr=dfs(b[i],i,a[i]);
		int nl=dfs2(a[i],b[i]);
		int nr=dfs2(b[i],a[i]);
		ret=min(ret,cost+cl*nr+cr*nl+(ll) nl*nr*w[i]);
	}
	printf("%I64d\n",ret);
	return 0;
}