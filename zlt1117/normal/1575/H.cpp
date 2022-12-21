#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define gc getchar()
#define mk make_pair
#define iter set<int>::iterator
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=509;
int dp[maxn][maxn][maxn];
char s[maxn],t[maxn],tmp[maxn];
int n,m;
int fail[maxn],nxt[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi();
	scanf("%s%s",s+1,t+1);
}
inline void run_kmp()
{
	fail[1]=0;fail[0]=-1;
	FOR(i,1,m)
	{
		int j=fail[i-1];
		while(j!=-1)
		{
			if(t[j+1]==t[i])break;
			j=fail[j];
		}
		fail[i]=j+1;
	}
	nxt[m+1]=fail[m];
	FOR(i,1,m)
	{
		int j=fail[i-1];
		while(j!=-1)
		{
			if(t[j+1]!=t[i])break;
			j=fail[j];
		}
		nxt[i]=j+1;
	}
}
inline void solve()
{
	memset(dp,0x3f,sizeof(dp));
	run_kmp();
	dp[0][0][0]=0;
	FOR(i,1,n)
	{
		FOR(j,0,n-m+1)
		{
			FOR(k,0,m-1)
			{
				if(k==m-1) dp[i][j+1][nxt[m+1]]=min(dp[i][j+1][nxt[m+1]],dp[i-1][j][k]+(s[i]!=t[k+1]));
				else dp[i][j][k+1]=min(dp[i][j][k+1],dp[i-1][j][k]+(s[i]!=t[k+1]));
				dp[i][j][nxt[k+1]]=min(dp[i][j][nxt[k+1]],dp[i-1][j][k]+(s[i]==t[k+1]));
			}
		}
	}
	FOR(i,0,n-m+1)
	{
		int ans=n+1;
		FOR(j,0,m-1)ans=min(ans,dp[n][i][j]);
		if(ans==n+1)printf("-1 ");
		else printf("%d ",ans);
	}
	puts("");
}
int main()
{
	int T=1;
	//T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}