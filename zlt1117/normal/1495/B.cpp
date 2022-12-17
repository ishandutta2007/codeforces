#pragma GCC optimize("Ofast")
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
const int maxn=1e5+5;
int pre[maxn],suf[maxn],n,a[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
bool vis[maxn];
inline void solve()
{
	pre[1]=suf[n]=1;
	FOR(i,2,n)pre[i]=a[i]>a[i-1]?pre[i-1]+1:1;
	for(int i=n-1;i>=1;--i)suf[i]=a[i]>a[i+1]?suf[i+1]+1:1;
	int maxv=0;
	FOR(i,1,n)maxv=max(maxv,max(pre[i],suf[i]));
	FOR(i,1,n)if(pre[i]==maxv||suf[i]==maxv)vis[i]=1;
	int cnt=0;
	FOR(i,1,n)cnt+=vis[i];
	if(cnt>=2)printf("0\n");
	else 
	{
		int pos=0;
		FOR(i,1,n)if(max(pre[i],suf[i])==maxv)pos=i;
		int minv=min(suf[pos],pre[pos]);
		if(maxv%2==1&&minv==maxv)printf("1\n");
		else printf("0\n");
	}
}
int main()
{
	int T=1;
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}