#include<bits/stdc++.h>
#define ll long long
#define db double
#define N 310
using namespace std;

ll n,xx,ans,dp[N][N][6];
db x[N],y[N];
struct Xd
{
    ll u,v;
    db jd;
    bool operator < (const Xd &u) const{return jd<u.jd;}
}xd[N*N];

int main()
{
    ll i,j,k;
    cin>>n;
    for(i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(i=1;i<=n;i++)
    {
	for(j=1;j<=n;j++)
	{
	    if(i==j) continue;
	    xd[++xx]=(Xd){i,j,atan2(y[j]-y[i],x[j]-x[i])};
	}
    }
    sort(xd+1,xd+xx+1);
    for(i=1;i<=xx;i++)
    {
	dp[xd[i].u][xd[i].v][1]=1;
	for(j=1;j<=n;j++)
	{
	    for(k=2;k<=5;k++)
	    {
		dp[j][xd[i].v][k]+=dp[j][xd[i].u][k-1];
	    }
	}
    }
    for(i=1;i<=n;i++) ans+=dp[i][i][5];
    cout<<ans;
}