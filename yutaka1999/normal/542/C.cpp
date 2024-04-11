#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#define SIZE 205

using namespace std;
typedef long long int ll;

int f[SIZE];
vector <int> rvec[SIZE];
int deg[SIZE];
bool use[SIZE];

int dfs(int v,int d=0)
{
	int ret=d;
	for(int i=0;i<rvec[v].size();i++)
	{
		int to=rvec[v][i];
		if(deg[to]==0)
		{
			ret=max(ret,dfs(to,d+1));
		}
	}
	return ret;
}
ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int to;
		scanf("%d",&to);to--;
		f[i]=to;
		rvec[to].push_back(i);
		deg[to]++;
	}
	queue <int> que;
	for(int i=0;i<n;i++) if(deg[i]==0) que.push(i);
	while(!que.empty())
	{
		int v=que.front();que.pop();
		int to=f[v];
		deg[to]--;
		if(deg[to]==0) que.push(to);
	}
	ll lcm=1,M=0;
	for(int i=0;i<n;i++)
	{
		if(!use[i]&&deg[i]==1)
		{
			ll L=0;
			int now=i;
			do
			{
				use[now]=true;
				M=max(M,(ll) dfs(now));
				L++;
				now=f[now];
			}while(now!=i);
			lcm=lcm/gcd(lcm,L)*L;
		}
	}
	ll ret=lcm;
	while(ret<M) ret+=lcm;
	printf("%I64d\n",ret);
	return 0;
}