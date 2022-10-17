#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N 5010
using namespace std;

ll m,n,num[N],ans,dp[N][N][2];

inline void Min(ll &u,ll v)
{
	if(v<u) u=v;
}

ll dfs(ll now,ll sy,bool sf)
{
//	cout<<now<<' '<<sy<<" "<<sf<<endl;
	if(sy<= 0) return 0;
	if(now<=0) return INF;
	if(dp[now][sy][sf]!=-1) return dp[now][sy][sf];
	if(now==1) return dp[now][sy][sf]=sy<=sf?0:INF;
	ll res=INF,t=0;
	if(sf)
	{
		t=max(-1ll,num[now-1]-num[now])+1;
		return dp[now][sy][sf]=min(dfs(now-2,sy-1,0),dfs(now-2,sy-1,1)+max(-1ll,num[now-1]-t-num[now-2])+1)+t;
	}
	return dp[now][sy][sf]=min(dfs(now-1,sy,0),dfs(now-1,sy,1)+max(-1ll,num[now]-num[now-1])+1);
}

int main()
{
//	freopen("2.txt","r",stdin);
//	freopen("3.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
	ll i,j;
	cin>>n;
	for(i=1; i<=n; i++) scanf("%lld",&num[i]);
	num[0]=num[n+1]=-INF;
	for(i=1; i<=(n+1)/2; i++) printf("%lld ",min(dfs(n,i,1),dfs(n,i,0)));
}