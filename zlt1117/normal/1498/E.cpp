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
const int maxn=505;
int n;
int k[maxn];
inline void init()
{

}
inline void input()
{
	n=gi();
	FOR(i,1,n)k[i]=gi();
}
inline int query(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char s[10];
	scanf("%s",s+1);
	if(s[1]=='Y')return 1;
	else return 0;
}
set<PII>s;
inline void solve()
{
	vector<PII>vec;
	FOR(i,1,n)vec.pb({k[i],i});
	sort(vec.begin(),vec.end());
	vector<pair<int,pair<int,int> > >vec2;
	FOR(i,0,sz(vec)-1)
	{
		FOR(j,i+1,sz(vec)-1)
		{
			vec2.pb(make_pair(abs(vec[j].first-vec[i].first),PII(vec[i].second,vec[j].second)));
		}
	} 
	sort(vec2.begin(),vec2.end(),greater<pair<int,PII> >()); 
	for(auto x:vec2)
	{
		s.insert(PII(x.second.second,x.second.first));
		if(query(x.second.second,x.second.first))
		{
			printf("! %d %d\n",x.second.second,x.second.first);
			fflush(stdout);
			return ;
		}
	}
	printf("! 0 0\n");
	fflush(stdout);
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