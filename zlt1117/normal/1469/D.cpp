#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define rd (rand()<<16^rand())
#define PII pair<int,int>
#define pb push_back
#define sz(x) (int)(x.size())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
    int x=0,f=1;char ch=gc;
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
    while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
    return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=2e5+5;
int n;
int temp[]={2,4,16,256,65536,1000000};
set<int>s;
inline void init()
{
	
}
inline void input()
{
	n=gi();
}
inline void solve()
{
	vector<int>vec;
	vector<PII>v;
	int now=0;
	if(n>65537)
	{
		FOR(i,65538,n-1)v.pb({i,n});
		v.pb({n,65536});
		v.pb({n,65536});
		n=65537;
	}
	FOR(i,0,5)if(temp[i]>n){now=i-1;break;}
	FOR(i,3,n)if(!s.count(i)&&i!=n){v.pb({i,n});}
	if(!s.count(n))v.pb({n,temp[now]}),v.pb({n,temp[now]});
	for(int i=now;i>=1;--i)
	{
		v.pb({temp[now],temp[i-1]});
		v.pb({temp[i-1],temp[now]});
	}
	printf("%d\n",sz(v));
	for(auto x:v)
	{
		printf("%d %d\n",x.first,x.second);
	}
}
int main()
{
	int T=gi();
	FOR(i,0,4)s.insert(temp[i]);
	while(T--)
	{
		init();
		input();
		solve();
	}
	return 0;
}