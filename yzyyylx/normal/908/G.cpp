#include<bits/stdc++.h>
#define ll long long
#define N 710
#define MN 700
#define M 1000000007
using namespace std;

ll n,ans,num[N],ten[N],qz[N],dp[N][10][N];
char str[N];

inline void Add(ll &u,ll v){u=(u+v)%M;}
ll dfs(ll now,ll jz,ll ct,bool lim,bool qd)
{
    if(ct<0) return 0;
    if(now>n) return !ct;
    if(!lim&&!qd&&dp[now][jz][ct]!=-1) return dp[now][jz][ct];
    ll i,mx=9,res=0;
    if(lim) mx=num[now];
    for(i=0;i<=mx;i++)
    {
	Add(res,dfs(now+1,jz,ct-(i>=jz),lim&&i==mx,qd&&!i));
    }
    if(!lim&&!qd) dp[now][jz][ct]=res;
//    cerr<<now<<" "<<jz<<" "<<ct<<" "<<lim<<" "<<qd<<" "<<mx<<" "<<res<<endl;
    return res;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ll i,j;
    scanf("%s",str+1);
    n=strlen(str+1);
    for(i=1;i<=n;i++) num[i]=str[i]-'0';
    ten[1]=qz[1]=1;
    for(i=2;i<=MN;i++)
    {
	ten[i]=ten[i-1]*10%M;
	qz[i]=(qz[i-1]+ten[i])%M;
    }
    for(i=1;i<=9;i++)
    {
	for(j=1;j<=n;j++)
	{
//	    cerr<<" "<<qz[j]<<" "<<dfs(1,i,j,1,1)<<endl;
	    Add(ans,qz[j]*dfs(1,i,j,1,1)%M);
	}
    }
    cout<<ans;
}