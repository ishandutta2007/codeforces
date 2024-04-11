#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define PII pair<int,int>
#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}
const int maxn=2e5+5;
int n;
ll dp[maxn][3][2][2];
int a[maxn];
inline void A(ll &a,ll b){a=max(a,b);}
int main()
{
	memset(dp,0xcf,sizeof(dp));
	n=gi();
	FOR(i,1,n)a[i]=gi();
	if(n==1){printf("%d\n",a[1]);return 0;}
	dp[1][2][0][0]=-a[1];
	dp[1][1][1][0]=a[1];
	FOR(i,1,n-1)
	{
		FOR(j,0,2)
		{
			FOR(k,0,1)/// 
			{
				FOR(t,0,1)/// 
				{
					if(t!=k)A(dp[i+1][(j+((t==0)?2:1))%3][t][0],dp[i][j][k][0]+((t==1)?a[i+1]:-a[i+1]));
					if(t==k)A(dp[i+1][(j+((t==0)?2:1))%3][t][1],dp[i][j][k][0]+((t==1)?a[i+1]:-a[i+1]));
					A(dp[i+1][(j+((t==0)?2:1))%3][t][1],dp[i][j][k][1]+((t==1)?a[i+1]:-a[i+1]));
				}
			}
		}
	}
	printf("%lld\n",max(dp[n][1][1][1],dp[n][1][0][1]));
	return 0;
}