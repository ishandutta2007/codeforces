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
int q;
inline void init()
{

}
inline void input()
{
	q=gi();
}
inline void solve()
{
	while(q--)
	{
		vector<int>v1;set<int>v2;
		int x=gi(),y=gi(),xx=x,yy=y;
		FOR(i,0,30)
		{
			if(x&1)v1.pb(i);
			x>>=1;
		}
		FOR(i,0,30)
		{
			if(y&1)v2.insert(i);
			y>>=1;
		}
		if(sz(v1)<sz(v2)||xx>yy)printf("no\n");
		else
		{
			reverse(v1.begin(),v1.end());
			int cnt=sz(v1);
			for(int i=sz(v1)-1;i>=0;--i)
			{
				auto it=v2.lower_bound(v1[i]);
				if(it==v2.end())i--,cnt-=2;
				else v2.erase(it),cnt--;
			}
			if(sz(v2))printf("no\n");
			else if(cnt%2==1)printf("no\n");
			else printf("yes\n");
		}
	}
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