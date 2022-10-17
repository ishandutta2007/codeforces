#include<bits/stdc++.h>
#define ll long long
#define N 200100
#define M 998244353
using namespace std;

ll n,dp[N][3];
vector<ll>to[N];

inline void Add(ll &u,ll v){u=(u+v)%M;}
ll dfs(ll now,ll u)
{
    if(dp[now][u]!=-1) return dp[now][u];
    if(!to[now].size()) return !!u;
    ll i,t;
    if(!u)
    {
	ll res=1;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    res=res*(dfs(t,0)+dfs(t,2))%M;
	}
//	cout<<now<<" "<<u<<" "<<res<<endl;
	return dp[now][u]=res;
    }
    if(u==1)
    {
	ll a,b;
	a=1,b=0;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    b=b*(dfs(t,0)+dfs(t,1)+dfs(t,2))%M;
	    Add(b,a*dfs(t,1)%M);
	    a=a*(dfs(t,0)+dfs(t,2))%M;
	}
//	cout<<now<<" "<<u<<" "<<b<<endl;
	return dp[now][u]=b;
    }
    if(u==2)
    {
	ll a,b,c;
	a=1,b=0,c=0;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    c=c*(dfs(t,0)+dfs(t,1)+dfs(t,2))%M;
	    Add(c,b*dfs(t,1)%M);
	    b=b*(dfs(t,0)+dfs(t,2))%M;
	    Add(b,a*dfs(t,1)%M);
	    a=a*(dfs(t,0)+dfs(t,2))%M;
	}
//	cout<<now<<" "<<u<<" "<<c<<endl;
	return dp[now][u]=c;
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ll i,j,t;
    cin>>n;
    for(i=2;i<=n;i++)
    {
	scanf("%lld",&t);
	to[t].push_back(i);
    }
    cout<<(dfs(1,0)+dfs(1,2))%M;
}