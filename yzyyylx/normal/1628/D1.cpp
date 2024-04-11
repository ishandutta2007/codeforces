#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 2010
#define M 1000000007
using namespace std;

ll T,n,m,ans,er,K,dp[N][N];

ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline ll cg(char u){return u-'a'+1;}
inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}

ll dfs(ll u,ll v)
{
//	cout<<"  "<<u<<" "<<v<<"  "<<dp[u][v]<<endl;
	if(u==v) return u;
	if(!v) return 0;
	if(dp[u][v]!=-1) return dp[u][v];
	ll x=(dfs(u-1,v)-dfs(u-1,v-1)+M)*er%M;
	return dp[u][v]=(x+dfs(u-1,v-1))%M;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,p,q,pp,qq;
	er=po(2,M-2);
	cin>>T;
	while(T--)
	{
		scanf("%lld%lld%lld",&n,&m,&K);
		printf("%lld\n",dfs(n,m)*K%M);
	}
}