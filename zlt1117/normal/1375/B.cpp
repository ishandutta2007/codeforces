//#pragma GCC optimize(4)
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
const int maxn=305;
int a[maxn][maxn],n,m,b[maxn][maxn];
inline void init()
{
	FOR(i,1,n)FOR(j,1,m)a[i][j]=b[i][j]=0;
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)FOR(j,1,m)a[i][j]=gi();
}
inline void solve()
{
	FOR(i,1,n)FOR(j,1,m)b[i][j]=4;
	FOR(i,1,n)b[i][1]=b[i][m]=3;
	FOR(i,1,m)b[1][i]=b[n][i]=3;
	b[1][1]=2,b[1][m]=2,b[n][1]=2,b[n][m]=2;
	FOR(i,1,n)FOR(j,1,m)if(a[i][j]>b[i][j]){printf("NO\n");return ;}
	printf("YES\n");
	FOR(i,1,n)
	{
		FOR(j,1,m){printf("%d ",b[i][j]);}
		printf("\n");
	}
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