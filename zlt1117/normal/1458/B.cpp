#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define PLL pair<ll,ll>
#define fi first
#define se second
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=105,maxt=200;
int dp[2][maxn][maxn*maxn*4];
int n,a[maxn],b[maxn];
int now,last,zero;
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=gi();
}
inline void solve()
{
	zero=maxt*maxt/2;
	memset(dp,0xcf,sizeof(dp));
	dp[now][0][zero]=0;
	FOR(i,1,n)
	{
		now=now^1;
		last=now^1;
		FOR(j,0,i+1)memset(dp[now][j],0xcf,sizeof(dp[now][j]));
		FOR(j,0,i)
		{
			FOR(k,zero-200*(i-1),zero+200*(i-1))
			{
				if(dp[last][j][k]<0)continue;
				dp[now][j][k-b[i]]=max(dp[last][j][k]+b[i],dp[now][j][k-b[i]]);
				dp[now][j+1][k+(a[i]-b[i])*2]=max(dp[now][j+1][k+(a[i]-b[i])*2],dp[last][j][k]+b[i]*2);
			}
		}
	}
	FOR(i,1,n)
	{
		int ans=0;
		FOR(k,zero-200*n,zero+200*n)
		{
			if(k>=zero)ans=max(ans,dp[now][i][k]);
			else ans=max(ans,dp[now][i][k]-(zero-k));
		}
		printf("%.9lf ",(double)ans/2);
	}
}
int main()
{
	init();
	input();
	solve();
	return 0;
}///