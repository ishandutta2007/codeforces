#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005
#define MOD 1000000007

using namespace std;
typedef long long int ll;

vector <int> vec[SIZE];
ll dp[SIZE],ans[SIZE];
int cnt[SIZE];

ll mpow(ll m,ll t)
{
	if(t==0) return 1;
	ll ret=mpow(m,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*m%MOD;
	return ret;
}
ll inv(ll v)
{
	return mpow(v,MOD-2);
}
void dfs(int v=0,int p=-1)
{
	dp[v]=1;
	cnt[v]=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			ll vl=((cnt[to]>0?0:dp[to])+1)%MOD;
			if(vl==0) cnt[v]++;
			else
			{
				dp[v]*=vl;
				dp[v]%=MOD;
			}
		}
	}
}
void make(int v=0,int p=-1)
{
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			ll vl=((cnt[to]>0?0:dp[to])+1)%MOD;
			ll mul;
			if(vl==0)
			{
				if(cnt[v]>1) mul=0;
				else mul=dp[v];
			}
			else
			{
				if(cnt[v]>0) mul=0;
				else mul=dp[v]*inv(vl)%MOD;
			}
			mul++;
			mul%=MOD;
			dp[to]*=mul;
			dp[to]%=MOD;
			make(to,v);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int p;
		scanf("%d",&p);p--;
		vec[i+1].push_back(p);
		vec[p].push_back(i+1);
	}
	dfs();
	make();
	for(int i=0;i<n;i++) printf("%I64d\n",cnt[i]>0?0:dp[i]);
	return 0;
}