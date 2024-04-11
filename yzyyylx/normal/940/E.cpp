#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define INF 0x3f3f3f3f
#define N 100100
using namespace std;

ll num[N],n,st[N][30],c,dp[N],sum;

inline ll log(ll u)
{
    ll res=0;
    while(u)
    {
        res++;
        u>>=1;
    }
    return res-1;
}

inline ll ask(ll u,ll v)
{
    ll len;
    len=v-u+1;
    len=log(len);
    return min(st[u][len],st[v-(1 << len)+1][len]);
}

ll dfs(ll now)
{
	if(!now) return 0;
	if(dp[now]!=-1) return dp[now];
	ll res=dfs(now-1);
	if(now-c>=0) res=max(res,dfs(now-c)+ask(now-c+1,now));
	return dp[now]=res;
}

int main()
{
	ll i,j;
	cin>>n>>c;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
		st[i][0]=num[i];
	}
	for(i=1;(1 << i)<=n;i++)
	{
		for(j=1;j+(1 << i)-1<=n;j++)
		{
			st[j][i]=min(st[j][i-1],st[j+(1 << (i-1))][i-1]);
		}
	}
	/*
	for(i=1;i+c-1<=n;i++)
	{
		cout<<ask(i,i+c-1)<<" ";
	}
	//*/
	memset(dp,-1,sizeof(dp));
	cout<<sum-dfs(n);
}