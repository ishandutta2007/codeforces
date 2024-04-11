#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=200010;
int n;
const ll p=1000000007;
namespace T1
{
	ll a[N];
	void add(int x,ll v)
	{
		for(;x<=n;x+=x&-x)
			a[x]+=v;
	}
	ll query(int x)
	{
		ll s=0;
		for(;x;x-=x&-x)
			s+=a[x];
		return s%p;
	}
	ll query2(int x)
	{
		ll s=0;
		for(;x;x-=x&-x)
			s+=a[x];
		return s;
	}
	int gao(ll v)
	{
		int x=1<<18;
		for(int i=17;i>=0;i--)
		{
			if(x-(1<<i)>=n)
				x-=1<<i;
			else if(a[x-(1<<i)]>=v)
				x-=1<<i;
			else
				v-=a[x-(1<<i)];
		}
		return x;
	}
}
namespace T2
{
	ll a[N];
	void add(int x,ll v)
	{
		v%=p;
		for(;x<=n;x+=x&-x)
			(a[x]+=v)%=p;
	}
	ll query(int x)
	{
		ll s=0;
		for(;x;x-=x&-x)
			(s+=a[x])%=p;
		return s;
	}
}
namespace T3
{
	ll a[N];
	void add(int x,ll v)
	{
		v%=p;
		for(;x<=n;x+=x&-x)
			(a[x]+=v)%=p;
	}
	ll query(int x)
	{
		ll s=0;
		for(;x;x-=x&-x)
			(s+=a[x])%=p;
		return s;
	}
}
namespace T4
{
	ll a[N];
	void add(int x,ll v)
	{
		v%=p;
		for(;x<=n;x+=x&-x)
			(a[x]+=v)%=p;
	}
	ll query(int x)
	{
		ll s=0;
		for(;x;x-=x&-x)
			(s+=a[x])%=p;
		return s;
	}
}
int q;
ll a[N],w[N];
int main()
{
	open("c");
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&w[i]);
		T1::add(i,w[i]);
		T2::add(i,w[i]*a[i]);
		T3::add(i,w[i]*i);
		T4::add(i,w[i]*(n-i+1));
	}
	int l,r;
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&l,&r);
		if(l<0)
		{
			l=-l;
			T1::add(l,r-w[l]);
			T2::add(l,(r-w[l])*a[l]);
			T3::add(l,(r-w[l])*l);
			T4::add(l,(r-w[l])*(n-l+1));
			w[l]=r;
		}
		else
		{
			ll s2=T1::query2(r);
			ll s1=T1::query2(l-1);
			ll s=s1+(s2-s1+1)/2;
			int pos=T1::gao(s);
			if(pos<l)
				pos=l;
			if(pos>r)
				pos=r;
			ll ans=(a[pos]*(T1::query(pos)-T1::query(l-1))%p-(T2::query(pos)-T2::query(l-1))+(T2::query(r)-T2::query(pos))-a[pos]*(T1::query(r)-T1::query(pos)))%p;
			ans-=(T4::query(pos-1)-T4::query(l-1))-(T1::query(pos-1)-T1::query(l-1))*(n-(pos-1)+1-1);
			ans%=p;
			ans-=(T3::query(r)-T3::query(pos))-(T1::query(r)-T1::query(pos))*(pos+1-1);
			ans=(ans%p+p)%p;
			printf("%I64d\n",ans);
		}
	}
	return 0;
}