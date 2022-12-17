//#pragma GCC optimize("Ofast")
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
const int maxn=505;
int n,m;
char s[maxn][maxn];
inline void init()
{
	FOR(i,1,n)FOR(j,1,m)s[i][j]=0;
}
inline void input()
{
	n=gi(),m=gi();
	FOR(i,1,n)scanf("%s",s[i]+1);
}
inline void solve()
{
	if(n==1)
	{
		FOR(i,1,m)printf("X");
		printf("\n");
		return ;
	}
	FOR(i,1,n)if(i%3==2)FOR(j,1,m)s[i][j]='X';
	for(int i=3;i<=n;i+=3)
	{
		if(i==n)break;
		int j=i+1;int pos1=0,pos2=0;
		FOR(k,1,m)pos1=s[i][k]=='X'?k:pos1;
		FOR(k,1,m)pos2=s[j][k]=='X'?k:pos2;
		if(pos1==0&&pos2==0)s[i][1]=s[j][1]='X';
		else if(pos2==0)s[j][pos1]='X';
		else s[i][pos2]='X';
	}
	if(n%3==1)FOR(i,1,m)if(s[n][i]=='X')s[n-1][i]='X';
	FOR(i,1,n)printf("%s\n",s[i]+1);
}
int main()
{
	int T=gi();
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}