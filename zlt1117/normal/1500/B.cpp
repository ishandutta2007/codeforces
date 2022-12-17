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
#define int ll
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
const int maxn=1e6+5; 
int n,m,k,a[maxn],b[maxn],pos[maxn];
inline void init()
{

}
inline void input()
{
	n=gi(),m=gi(),k=gi();
	FOR(i,1,n)a[i]=gi(),pos[a[i]]=i;
	FOR(i,1,m)b[i]=gi(); 
}
vector<pair<int,int> >v;
inline int exgcd(int a,int b,int &x,int &y)
{
	if(b==0)
	{
		x=1,y=0;
		return a;
	}
	int g=exgcd(b,a%b,x,y);
	int t=x;
	x=y,y=t-a/b*y;
	return g;
}
inline int count(int x)
{
	int ret=x;
	for(auto vv:v)
	{
		int a=vv.first,b=vv.second;
		ret-=(x-a+b)/b;
	}
	return ret;
}
inline void solve()
{
	int x=0,y=0;		
	int g=exgcd(m,n,x,y);
	FOR(i,1,m)
	{
		if(pos[b[i]]!=0)
		{ 
			int t=pos[b[i]];
			t=((t-i)%n+n)%n;
			if(t%g==0)
			{
				int temp=n/g;
				int xx=x*t/g;xx=(xx%temp+temp)%temp;
				xx*=m;xx%=m/g*n;xx+=i; 
				v.pb({xx,n/g*m}); 
			}
		}
	}
	int l=0,r=1e18,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(count(mid)>=k)ans=mid,r=mid-1;
		else l=mid+1;	
	} 
	printf("%lld\n",ans);
}
signed main()
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