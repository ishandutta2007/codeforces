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
vector<int>u,v,w;
int L,R;
inline void init()
{

}
inline void input()
{
	L=gi(),R=gi();
}
inline void solve()
{
	printf("YES\n");
	FOR(i,2,23)u.pb(1),v.pb(i),w.pb(L);
	if(L!=R)
	{
		R-=L-1;
		FOR(i,3,22)
		{
			FOR(j,2,i-1)
			{
				u.pb(j),v.pb(i),w.pb((1<<(j-2)));
			}
		}
		while((R&-R)!=R)
		{
			int now=R,cnt=0;
			while(now)now>>=1,cnt++;
			cnt--;///2^cnt
			u.pb(cnt+2),v.pb(23),w.pb(R-(1<<cnt));
			R^=(1<<cnt);
		}
		int pos=0;
		while((1<<pos)!=R)pos++;
		FOR(i,2,pos+1)u.pb(i),v.pb(23),w.pb((1<<(i-2)));
	}
	printf("23 %d\n",sz(u));
	FOR(i,0,sz(u)-1)printf("%d %d %d\n",u[i],v[i],w[i]);
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