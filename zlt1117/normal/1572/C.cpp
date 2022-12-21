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
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=3005,inf=0x3f3f3f3f;
int dp[maxn][maxn],n,a[maxn];
vector<int>v[maxn];
inline void init()
{
	FOR(i,1,n)FOR(j,1,n)dp[i][j]=0;
	FOR(i,1,n)v[a[i]].clear();
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),v[a[i]].pb(i);
}
inline void solve()
{
	FOR(len,2,n)
	{
		FOR(i,1,n-len+1)
		{///can be the leftest all the time
			int j=i+len-1;
			dp[i][j]=dp[i+1][j]+1;
			if(a[i]==a[j])dp[i][j]=dp[i+1][j];
			for(int x:v[a[i]])
			{
				if(x<=i||x>=j)continue;
				dp[i][j]=min(dp[i][j],dp[i][x-1]+dp[x][j]);
			}
		}
	}
	printf("%d\n",dp[1][n]);
}
int main()
{
	int T=1;
	T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}