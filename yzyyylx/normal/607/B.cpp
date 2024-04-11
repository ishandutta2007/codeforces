#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define pi acos(-1)
#define INF 0x3f3f3f3f3f3f3f3f
#define N 510
#define M
using namespace std;

ll T,n,num[N],dp[N][N];

ll ask(ll u,ll v)
{
	if(u>=v) return 1;
	if(dp[u][v]!=-1) return dp[u][v];
	ll i,res=INF;
	if(num[u]==num[v]) res=ask(u+1,v-1);
	for(i=u;i<v;i++)
	{
		res=min(res,ask(u,i)+ask(i+1,v));
	}
	return dp[u][v]=res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j;
	cin>>n;
	for(i=1;i<=n;i++) scanf("%lld",&num[i]);
	cout<<ask(1,n);
}