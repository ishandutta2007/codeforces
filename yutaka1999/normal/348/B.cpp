#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <vector>
#define SIZE 100005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;

struct P
{
	ll n,k;
	P(ll n=0,ll k=0):n(n),k(k){}
};
vector <int> vec[SIZE];
P dp[SIZE];
int num[SIZE];
ll ans;

ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
ll lcm(ll x,ll y)
{
	ll g=gcd(x,y);
	if(x/g>=INF/y+1) return INF;
	return x/g*y;
}
void dfs(int v=0,int p=-1)
{
	if(num[v]>0||(v!=0&&vec[v].size()==1))
	{
		dp[v]=P(1,num[v]);
		return;
	}
	ll sum=0,mn=INF,L=1,c=0;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			dfs(to,v);
			c++;
			L=lcm(L,dp[to].n);
			sum+=dp[to].k;
			mn=min(mn,dp[to].k);
		}
	}
	ll NT=mn/L*L;
	ans+=sum-NT*c;
	if(L>=INF/c+1) L=INF;
	else L*=c;
	dp[v].k=NT*c;
	dp[v].n=L;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	dfs();
	printf("%I64d\n",ans);
	return 0;
}