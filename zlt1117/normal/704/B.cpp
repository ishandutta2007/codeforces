#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define sz(x) (int)(x.size())
#define pb push_back
#define PII pair<int,int>
#define ll long long
#define gc getchar()
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
const int maxn=5005;
int n,x[maxn],a[maxn],b[maxn],c[maxn],d[maxn],s,e;
ll dp[maxn][maxn];
inline void input()
{
	n=gi(),s=gi(),e=gi();
	FOR(i,1,n)x[i]=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)b[i]=gi();
	FOR(i,1,n)c[i]=gi();
	FOR(i,1,n)d[i]=gi();
}
inline void solve()
{
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	FOR(i,1,n)
	{
		FOR(j,1,n)
		{
			if(i==s)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]-x[i]+d[i]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+x[i]+c[i]);
			}
			else if(i==e)
			{
				dp[i][j]=min(dp[i][j],dp[i-1][j-1]-x[i]+b[i]);
				dp[i][j]=min(dp[i][j],dp[i-1][j]+x[i]+a[i]);
			}
			else
			{
				if(i<max(s,e)||j>2)dp[i][j]=min(dp[i][j],dp[i-1][j-1]-2*x[i]+d[i]+b[i]);
				if(j!=1||i<e)dp[i][j]=min(dp[i][j],dp[i-1][j]+d[i]+a[i]);
				if(j!=1||i<s)dp[i][j]=min(dp[i][j],dp[i-1][j]+b[i]+c[i]);
				dp[i][j]=min(dp[i][j],dp[i-1][j+1]+2*x[i]+c[i]+a[i]);
			}
		}
	}
	printf("%lld\n",dp[n][1]);
}
int main()
{
	input();
	solve();
	return 0;
}