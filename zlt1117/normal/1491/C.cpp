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
const int maxn=5005;
int a[maxn],n;
ll ans;
set<int>s;
inline void init()
{
	s.clear();
	ans=0;
	FOR(i,1,n)a[i]=0;
}
inline void input()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	FOR(i,1,n)if(a[i]!=1)s.insert(i);
}
inline void zou(int pos)
{
	while(pos<=n)
	{
		bool ok=a[pos]!=1;
		int temp=pos+a[pos];
		if(a[pos]!=0)a[pos]=max(a[pos]-1,1);
		if(a[pos]==1&&ok)s.erase(pos);
		auto x=s.lower_bound(temp);
		if(x==s.end())break;
		pos=*x;
	}
	ans++;
}
inline void solve()
{
	if(s.empty())return printf("0\n"),void();
	int pos=*s.begin();
	int cnt=0;
	while(!s.empty())
	{
		if(a[pos]+pos>n)ans+=a[pos]+pos-n-1,a[pos]=n-pos+1;
		if(pos==n)break;
		zou(pos);
		//check();
		if(s.empty())break;
		pos=*s.begin();
		++cnt;
		//if(cnt%10000==0)cerr<<cnt<<endl;
	}
	printf("%lld\n",ans);
}
int main()
{
//	freopen("1.in","r",stdin);
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