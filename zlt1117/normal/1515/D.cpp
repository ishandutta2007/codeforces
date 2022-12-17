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
#define db double
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
const int maxn=2e5+5;
int n,l,r,c[maxn];
int cnt[maxn],ans;
inline void init()
{
	ans=0;
	memset(cnt,0,sizeof(int)*(n+1));
}
inline void input()
{
	n=gi(),l=gi(),r=gi();
	FOR(i,1,l)
	{
		int x=gi();
		cnt[x]++;
	}
	FOR(i,1,r)
	{
		int x=gi();
		cnt[x]--;
	}
	ans+=abs(r-l)/2;
}
inline void solve()
{
	int now=0,temp=0;
	FOR(i,1,n)
	{
		now+=abs(cnt[i]);
		if(r>l&&cnt[i]<0)temp+=abs(cnt[i])/2;
		if(r<=l&&cnt[i]>0)temp+=cnt[i]/2;
	}
	ans+=now/2;ans-=min(temp,abs(r-l)/2);
	printf("%d\n",ans);
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