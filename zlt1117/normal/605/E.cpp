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
const int maxn=1005;
double p[maxn][maxn],dp[maxn];
int vis[maxn],n; 
inline void input()
{
	n=gi();
	FOR(i,1,n)FOR(j,1,n)
	{
		int x=gi();
		p[i][j]=(double)x/100;
	}
}
double val[maxn],tmp[maxn];
inline void solve()
{
	dp[n]=0;
	FOR(i,1,n)val[i]=1;
	FOR(i,1,n)
	{
		int pos=0;
		if(i!=1)FOR(j,1,n)if(!vis[j]&&(pos==0||(dp[j]+1)/(1-val[j])<=(dp[pos]+1)/(1-val[pos])))pos=j;
		if(i==1)pos=n;vis[pos]=1;
		if(pos!=n)
		{
			dp[pos]=(dp[pos]+1)/(1-val[pos]);
		}
		FOR(j,1,n)if(!vis[j])
		{
			dp[j]+=val[j]*p[j][pos]*dp[pos];
			val[j]*=(1-p[j][pos]);
		}
	}
	printf("%.10lf",dp[1]);
}
int main()
{
	input();
	solve();
	return 0;
}