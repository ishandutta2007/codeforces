#include<bits/stdc++.h>
#define ll long long
#define N 1010
#define M 998244353
using namespace std;

ll n,tt,ans,num[N],dp[N][2];
char str[N];
bool vis[N],xy[N];

inline void Add(ll &u,ll v){u=(u+v)%M;}
void dfs(ll now,ll u,bool ab)
{
    ll t;
    num[++tt]=now;
    vis[now]=1;
    if(ab)
    {
	t=n+1-now;
	if(vis[t]) return;
	dfs(t,u,0);
    }
    else
    {
	if(now>u) return;
	t=u+1-now;
	if(vis[t]) return;
	dfs(t,u,1);
    }
}

inline ll calc(ll u)
{
    tt=0;
    memset(vis,0,sizeof(vis));
    memset(xy,0,sizeof(xy));
    memset(dp,0,sizeof(dp));
    ll i,j,t,p,q,res=1;
    bool now=1;
    for(i=n;i>u;i--)
    {
	if(vis[i]) continue;
	dfs(i,u,1);
	xy[tt]=1;
	dp[tt+1][1]=0;
	dp[tt+1][0]=1;
    }
//    cout<<u<<":";for(i=1;i<=tt;i++) cout<<num[i]<<"("<<xy[i]<<") ";puts("");
    dp[1][1]=0,dp[1][0]=1;
    for(j=now=1;j<=n;j++,now^=1)
    {
	i=num[j];
	if(xy[j-1]) now=1;
	if(xy[j])
	{
	    if(xy[j-1])
	    {
		if(str[i]=='?') res=res*2%M;
		continue;
	    }
	    t=0;
	    if(i>u)
	    {
		if(str[i]!='1') t+=dp[j][0];
		if(str[i]!='0') t+=dp[j][1];
		t%=M;
	    }
	    else if(i==u&&!now)
	    {
		if(str[i]!='1') t+=dp[j][1];
		if(str[i]!='0') t+=dp[j][0];
		t%=M;
	    }
	    else
	    {
		t=(dp[j][1]+dp[j][0])%M;
		if(str[i]=='?') t=t*2%M;
	    }
//	    cout<<" "<<res<<" "<<t<<endl;
	    res=res*t%M;
	    continue;
	}
	p=q=0;
	if(str[i]!='0')
	{
	    p+=dp[j][1];
	    q+=dp[j][0];
	}
	if(str[i]!='1')
	{
	    p+=dp[j][0];
	    q+=dp[j][1];
	}
	p%=M,q%=M;
	if(num[j+1]==u) p=0;
	dp[j+1][0]=p;
	dp[j+1][1]=q;
//	cout<<"  "<<i<<' '<<p<<' '<<q<<endl;
    }
//    cout<<u<<' '<<res<<endl;
    return res;
}

int main()
{
    int i,j;
    scanf("%s",str+1);
    n=strlen(str+1);
    if(str[n]=='1')
    {
	puts("0");
	return 0;
    }
    reverse(str+1,str+n+1);
//    calc(3);return 0;
    for(i=1;i<n;i++) Add(ans,calc(i));
    cout<<ans;
}