#include<bits/stdc++.h>
#define ll long long
#define N 260
#define M 1000000007
using namespace std;

ll n,m,ans,tot,dp[N][33000][2][2];
bool mm[N][N];
char str[N];

inline void Add(ll &u,ll v){u+=v,u%=M;}
inline ll get(ll u,ll v){return (u>>(v-1))&1;}
inline ll chg(ll u,ll v,ll w){return u+(w-get(u,v))*(1<<(v-1));}
int main()
{
    ll i,j,k,a,b,t,pos;
    cin>>m>>n;
    for(i=1;i<=m;i++)
    {
	scanf("%s",str+1);
	for(j=1;j<=n;j++)
	{
	    mm[i][j]=(str[j]=='x');
	}
    }
    if(m<n)
    {
	swap(m,n);
	for(i=1;i<=m;i++)
	{
	    for(j=1;j<i;j++)
	    {
		swap(mm[i][j],mm[j][i]);
	    }
	}
    }
    dp[1][0][0][0]=1;
    for(i=1;i<=m;i++)
    {
	for(j=1;j<=n;j++)
	{
	    pos=(i-1)*n+j;
	    for(k=0;k<(1 << n);k++)
	    {
		for(a=0;a<2;a++)
		{
		    for(b=0;b<2;b++)
		    {
			t=dp[pos][k][a][b];
			if(!t) continue;
			if(mm[i][j]) Add(dp[pos+1][chg(k,j,0)][0][b],t);
			else
			{
			    Add(dp[pos+1][chg(k,j,1)][j<n][b],t);
			    if(!b||a||get(k,j)) Add(dp[pos+1][k][a&&j<n][b||(!a&&!get(k,j))],t);
			}
		    }
		}
	    }
	}
    }
    for(i=0;i<(1 << n);i++) Add(ans,dp[m*n+1][i][0][0]+dp[m*n+1][i][0][1]);
    cout<<ans;
}