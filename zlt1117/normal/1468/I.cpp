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
#define int ll
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
ll n,dx1,dy1,dx2,dy2;
inline void init()
{

}
inline void input()
{
	n=gi();
	dx1=gi(),dy1=gi(),dx2=gi(),dy2=gi();
}
inline void solve()
{
	if((!dx1&&!dx2)||(!dy1&&!dy2)){printf("NO\n");return ;}
	ll now=__gcd(abs(dx1),abs(dx2));
	ll now2=abs(dx1*dy2-dx2*dy1)/now;
	ll now3=__gcd(abs(dy1),abs(dy2));
	ll now4=abs(dx1*dy2-dx2*dy1)/now3;
	if(now<now3)
	{
		if(now2*now==n)
		{
			printf("YES\n");
			FOR(i,0,now-1)FOR(j,0,now2-1)printf("%lld %lld\n",i,j);
			return ;
		}
	}
	else if(now3*now4==n)
	{
		printf("YES\n");
		FOR(i,0,now4-1)FOR(j,0,now3-1)printf("%lld %lld\n",i,j);
		return ;
	}
	printf("NO\n");
}
signed main()
{
	init();
	input();
	solve();
	return 0;
}

///