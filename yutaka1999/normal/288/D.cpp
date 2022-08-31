#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 80005

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
ll sum[SIZE];
int n;

ll dfs(int v=0,int p=-1)
{
	sum[v]=1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) sum[v]+=dfs(to,v);
	}return sum[v];
}
ll gen(int v=0,int p=-1)
{
	ll ret=0;
	ll path=sum[v]*sum[v]-1;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			ret+=gen(to,v);
			path-=sum[to]*sum[to];
		}
	}path/=2;
	return ret+path*path+2*path*sum[v]*(n-sum[v]);
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
	}dfs();
	ll all=(ll) n*(n-1)/2;all*=all;
	printf("%I64d\n",all-gen());
	return 0;
}