#include<bits/stdc++.h>
#define MN 2000
#define N 110
#define M 2010
using namespace std;

int n,an,ans,dp[N][M],use[N][M];
struct Zt
{
    int t,d,p,id;
    bool operator < (const Zt &u) const{return d<u.d;}
}zt[N];
vector<int>buy;

inline void Max(int &u,int v){if(v>u) u=v;}
int main()
{
    int i,j,k;
    cin>>n;
    for(i=1;i<=n;i++)
    {
	scanf("%d%d%d",&zt[i].t,&zt[i].d,&zt[i].p);
	zt[i].id=i;
	zt[i].d--;
    }
    sort(zt+1,zt+n+1);
    for(i=1;i<=n;i++)
    {
	memcpy(dp[i],dp[i-1],sizeof(dp[i]));
	for(j=zt[i].d;j>=zt[i].t;j--)
	{
	    if(dp[i-1][j-zt[i].t]+zt[i].p>dp[i][j])
	    {
		dp[i][j]=dp[i-1][j-zt[i].t]+zt[i].p;
		use[i][j]=i;
	    }
	}
    }
    for(i=0;i<=MN;i++)
    {
	if(dp[n][i]>ans)
	{
	    ans=dp[n][i];
	    an=i;
	}
    }
    cout<<ans<<endl;
    for(i=n,j=an;i>=1;i--)
    {
	if(use[i][j])
	{
	    buy.push_back(zt[use[i][j]].id);
	    j-=zt[use[i][j]].t;
	}
    }
    cout<<buy.size()<<endl;
    for(i=buy.size()-1;i>=0;i--) printf("%d ",buy[i]);
}