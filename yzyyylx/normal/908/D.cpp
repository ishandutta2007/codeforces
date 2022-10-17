#include<bits/stdc++.h>
#define ll long long
#define N 1010
#define M 1000000007
using namespace std;

ll a,b,ab,k,dp[N][N];

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
    if(v>=k) return v;
    if(u+v>=k) return (u+v+ab)%M;
    if(dp[u][v]!=-1) return dp[u][v];
    return dp[u][v]=(a*dfs(u+1,v)%M+b*dfs(u,u+v)%M)%M;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ll i,j,t;
    cin>>k>>a>>b;
    t=po(a+b,M-2);
    a=a*t%M;
    b=b*t%M;
    ab=a*po(b,M-2)%M;
    cout<<dfs(1,0);
}