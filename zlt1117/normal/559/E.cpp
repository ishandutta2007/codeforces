//#pragma GCC optimize("Ofast")
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
const int maxn=105;
pair<int,int>a[maxn];
int n;
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i].first=gi(),a[i].second=gi();
	sort(a+1,a+n+1);
}
int dp[maxn][maxn][2];
inline void solve()
{
	memset(dp,0xcf,sizeof(dp));
	a[0].first=-1e9;dp[0][0][0]=0;
	FOR(i,0,n)FOR(j,0,i)FOR(k,0,1)
	{
		int pos=a[j].first+k*a[j].second;
		pair<int,int>right={-1e9,0};
		if(a[i+1].first+a[i+1].second<pos)dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
		else dp[i+1][i+1][1]=max(dp[i+1][i+1][1],dp[i][j][k]+a[i+1].first+a[i+1].second-max(a[i+1].first,pos));
		FOR(p,i+1,n)
		{
			if(right.first>a[p].first)
			{
				int len=right.first-max(a[p].first-a[p].second,pos);
				dp[p][right.second][1]=max(dp[p][right.second][1],dp[i][j][k]+len);
			}
			else
			{
				int len=a[p].first-max(a[p].first-a[p].second,pos);
				dp[p][p][0]=max(dp[p][p][0],dp[i][j][k]+len);
			}
			right=max(right,{a[p].first+a[p].second,p});
		}
	}
	int answer=0;
	FOR(i,1,n)FOR(j,0,1)answer=max(answer,dp[n][i][j]);
	printf("%d\n",answer);
}
int main()
{
	input();
	solve();
	return 0;
}