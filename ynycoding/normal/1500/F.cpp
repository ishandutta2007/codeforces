#include <cstdio>
#include <list>
#include <assert.h>
#include <algorithm>
#define ll long long
#define x first
#define y second
using std::pair;
using std::list;
const int N=1000005;

namespace iobuff{
	const int LEN=1000000;
	char in[LEN+5], out[LEN+5];
	char *pin=in, *pout=out, *ed=in, *eout=out+LEN;
	inline char gc(void)
	{
		return pin==ed&&(ed=(pin=in)+fread(in, 1, LEN, stdin), ed==in)?EOF:*pin++;
	}
	inline void pc(char c)
	{
		pout==eout&&(fwrite(out, 1, LEN, stdout), pout=out);
		(*pout++)=c;
	}
	inline void flush()
	{ fwrite(out, 1, pout-out, stdout), pout=out; }
	template<typename T> inline void scan(T &x)
	{
		static int f;
		static char c;
		c=gc(), f=1, x=0;
		while(c<'0'||c>'9') f=(c=='-'?-1:1), c=gc();
		while(c>='0'&&c<='9') x=10*x+c-'0', c=gc();
		x*=f;
	}
	template<typename T> inline void putint(T x, char div)
	{
		static char s[100];
		static int top;
		top=0;
		x<0?pc('-'), x=-x:0;
		while(x) s[top++]=x%10, x/=10;
		!top?pc('0'), 0:0;
		while(top--) pc(s[top]+'0');
		pc(div);
	}
}
using namespace iobuff;

int n, rev, typ[N];
ll C, w[N], l[N], r[N], h[N], pr[N], off;
list<pair<ll, int> > q;
inline void procrev(ll w)
{
	rev^=1;
	off=w-off;
}
inline ll gback(void) { return rev?off-q.front().x:q.back().x+off; }
inline ll gfront(void) { return rev?off-q.back().x:q.front().x+off; }
inline int gbacky(void) { return rev?q.front().y:q.back().y; }
inline int gfronty(void) { return rev?q.back().y:q.front().y; }
inline void pop_front(void) { rev?q.pop_back():q.pop_front(); }
inline void pop_back(void) { rev?q.pop_front():q.pop_back(); }
inline void push_back(ll v, int id) { rev?q.push_front({off-v, id}):q.push_back({v-off, id}); }
int main()
{
	scanf("%d%lld", &n, &C);
	--n;
	for(int i=2; i<=n; ++i) scan(w[i]);
	l[1]=0, r[1]=w[2];
	for(int i=2; i<=n; ++i)
	{
		while(!q.empty()&&gback()>w[i]) pop_back();
		if(!q.empty()&&gback()==w[i]||l[i-1]<=w[i]&&r[i-1]>=w[i])
		{
			typ[i]=2;
			while(!q.empty()) q.pop_back();
			l[i]=0, r[i]=w[i];
			continue;
		}
		procrev(w[i]);
		l[i]=l[i-1], r[i]=std::min(r[i-1], w[i]);
		if(l[i]<=r[i])
		{
			std::swap(l[i], r[i]);
			l[i]=w[i]-l[i], r[i]=w[i]-r[i];
		}
		if(l[i]<=w[i]&&r[i]>=w[i]) continue;
		ll cl=l[i-1], cr=std::min(r[i-1], w[i]);
		if((!q.empty()&&gback()!=w[i])||cl<=cr)
		{
			typ[i]=1;
			procrev(w[i]);
			pr[i]=(cl<=cr?cl:gfront());
			procrev(w[i]);
			push_back(w[i], i);
		}
	}
	if(q.empty()&&l[n]>r[n]) return puts("NO"), 0;
	ll cv=l[n]<=r[n]?l[n]:gback();
	int t=n, sgn=1;
	while(t)
	{
		h[t]=cv*sgn;
		if(typ[t]==2)
		{
			sgn*=-1;
			cv=w[t];
		}
		else if(l[t]<=cv&&r[t]>=cv) cv=w[t]-cv;
		else if(cv==w[t]&&typ[t]==1) cv=pr[t], sgn*=-1;
		else cv=w[t]-cv;
		--t;
	}
	for(int i=1; i<=n; ++i) h[i]+=h[i-1];
	ll mn=0;
	for(int i=0; i<=n; ++i) mn=std::min(mn, h[i]);
	puts("YES");
	for(int i=0; i<=n; ++i) printf("%lld ", h[i]-mn);
	return 0;
}