#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#define SIZE 100005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
ll F[SIZE],G[SIZE];
int nd[SIZE];
int n;

ll mpow(ll m,ll t)
{
	if(t==0) return 1LL;
	ll ret=mpow(m*m%MOD,t/2);
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
ll inv(ll m)
{
	return mpow(m,MOD-2);
}
void dfs(int v=0,int p=-1)
{
	if(vec[v].size()==1)
	{
		F[v]=G[v]=0;
		return;
	}
	ll sumG=0,sumF=vec[v].size();
	for(int i=0;i<vec[v].size();i++)
	{
		edge e=vec[v][i];
		sumG+=e.cost;
		if(sumG>=MOD) sumG-=MOD;
		if(e.to!=p)
		{
			dfs(e.to,v);
			sumG+=G[e.to];
			if(sumG>=MOD) sumG-=MOD;
			sumF-=F[e.to];
			if(sumF<0) sumF+=MOD;
		}
	}
	ll g=inv(sumF);
	F[v]=g;
	G[v]=g*sumG%MOD;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		vec[a].push_back(edge(b,c));
		vec[b].push_back(edge(a,c));
	}
	dfs();
	printf("%lld\n",G[0]);
	return 0;
}