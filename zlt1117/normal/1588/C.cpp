//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define sz(x) (int)(x.size())
#define rd (rand()<<16^rand())
#define db double
#define mk make_pair
#define iter set<int>::iterator
#define gc getchar()
#define int ll
//#define gc (_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
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
const int maxn=3e5+5;
int n,a[maxn];
ll c[2];
inline void init()
{
	c[0]=c[1]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
}
inline void solve()
{
	ll ans=0;
	map<ll,ll>s;s[0]++;
	FOR(i,1,n)
	{
		///odd-even
		int nows=c[1]-c[0];
		if(i&1)
		{
			for(auto it=s.lower_bound(a[i]+1+nows);it!=s.end();)s.erase(it++);
//			auto it=s.lower_bound(nows);
//			vector<pair<int,int>>v;
//			for(auto it1=s.begin();it1!=it;++it1)v.pb(*it1);
//			for(auto x:v)s.erase(x.first);
		}
		else 
		{
//			for(auto it=s.upper_bound(nows+1);it!=s.end();)s.erase(it++);
			auto it=s.lower_bound(-a[i]+nows);
			vector<pair<int,int>>v;
			for(auto it1=s.begin();it1!=it;++it1)v.pb(*it1);
			for(auto x:v)s.erase(x.first);
		}
//		cerr<<i<<endl;
//		for(auto x:s)cerr<<x.first<<' '<<x.second<<endl;
		c[i&1]=(c[i&1]+a[i]);
		if(i&1)ans+=s[c[i&1]-c[(i-1)&1]];
		else ans+=s[c[(i-1)&1]-c[i&1]];
		if(i&1)s[c[i&1]-c[(i-1)&1]]++;
		else s[c[(i-1)&1]-c[i&1]]++;
//		cerr<<"ans="<<ans<<endl;
	}
	printf("%lld\n",ans);
}
signed main()
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
/*
1
3
1 0 1
*/