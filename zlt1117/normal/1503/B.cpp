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
int n;
vector<PII>vec[2];
inline void color(int x,int y,int c)
{
	printf("%d %d %d\n",c+1,x,y);
	fflush(stdout);
}
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)FOR(j,1,n)vec[(i+j)&1].pb({i,j});
}
inline void solve()
{
	FOR(i,1,n*n)
	{
		int x=gi();x--;
		if(x==2)
		{
			if(vec[0].size())
			{
				auto x=vec[0].back();
				color(x.first,x.second,0);
				vec[0].pop_back();
			}
			else
			{
				auto x=vec[1].back();
				color(x.first,x.second,1);
				vec[1].pop_back();
			}
			continue;
		}
		if(x==0)
		{
			if(vec[1].size())
			{	
				auto x=vec[1].back();
				color(x.first,x.second,1);
				vec[1].pop_back();
			}
			else
			{
				auto x=vec[0].back();
				color(x.first,x.second,2);
				vec[0].pop_back();
			}
		}
		if(x==1)
		{
			if(vec[0].size())
			{	
				auto x=vec[0].back();
				color(x.first,x.second,0);
				vec[0].pop_back();
			}
			else
			{
				auto x=vec[1].back();
				color(x.first,x.second,2);
				vec[1].pop_back();
			}
		}
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