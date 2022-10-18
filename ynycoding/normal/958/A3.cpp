#include <cstdio>
#include <numeric>
#include <ctime>
#include <random>
#include <cmath>
#include <unordered_map>
#include <algorithm>
#define eps (1e-1)
#define B 2
#define ld double
#define x first
#define y second
#define ull unsigned long long
#define uint unsigned int
using std::sqrt;
using std::abs;
using std::pair;
using std::unordered_map;
std::mt19937 rnd(time(0));
typedef std::pair<ld, ld> vec;
const int N=100005;
vec operator +(const vec &a, const vec &b) { return {a.x+b.x, a.y+b.y}; }
vec operator -(const vec &a, const vec &b) { return {a.x-b.x, a.y-b.y}; }
vec operator /(const vec &a, const ld &b) { return {a.x/b, a.y/b}; }
ld operator *(const vec &a, const vec &b) { return a.x*b.y-a.y*b.x; }
inline ld len2(const vec &a) { return a.x*a.x+a.y*a.y; }
inline ld len(const vec &a) { return sqrt(len2(a)); }
inline int sgn(ld x) { return x>eps?1:x<-eps?-1:0; }
vec mul(const vec &a, const vec &b) { return {a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x}; }

int n, m, k, vis[N], vis1[N], stk[N], top, stk1[N], top1;
vec p[N], p1[N];
int tt;
int conv(vec *p, int n, int *ban, int *rstk)
{
	static int stk[N], id[N], top;
	int tp=0;
	for(int i=1; i<=n; ++i) if(!ban[i]) id[++tp]=i;
	n=tp;
	if(!n) return 0;
	if(n==1)
	{
		rstk[1]=id[1];
		return 1;
	}
	top=0;
	std::sort(id+1, id+n+1, [&] (int x, int y) { return p[x].x<p[y].x; } );
	for(int i=1; i<=n; ++i)
	{
		while(top>1&&(p[stk[top]]-p[stk[top-1]])*(p[id[i]]-p[stk[top-1]])<-eps) --top;
		stk[++top]=id[i];
	}
	int rtop=0;
	std::copy(stk+1, stk+top+1, rstk+1);
	rtop=top;
	top=0;
	for(int i=n; i; --i)
	{
		while(top>1&&(p[stk[top]]-p[stk[top-1]])*(p[id[i]]-p[stk[top-1]])<-eps) --top;
		stk[++top]=id[i];
	}
	std::copy(stk+2, stk+top, rstk+rtop+1);
	rtop+=top-2;
	for(int i=1; i<=rtop; ++i) ban[rstk[i]]=1;
	return rtop;
}
int x[N], y[N], tp;
inline ull mp(uint x, uint y) { return ((ull)x<<32)|y; }
unordered_map<ull, int> rid;
inline bool chk(int a, int b, int c, int d)
{
	if(abs(len(p[b]-p[a])-len(p1[d]-p1[c]))>1) return 0;
	static vec rp[N], rp1[N];
	vec v=p[b]-p[a], v1=p1[d]-p1[c];
	v.y=-v.y, v1.y=-v1.y;
	v=v/len(v), v1=v1/len(v1);
	rid.clear();
	tp=0;
	for(int i=1; i<=n; ++i)
	{
		rp[i]=mul((p[i]-p[a]), v);
	}
	for(int i=1; i<=m; ++i)
	{
		rp1[i]=mul((p1[i]-p1[c]), v1);
	}
	for(int i=1; i<=m; ++i)
	{
		rid[mp((int)(rp1[i].x/B), (int)(rp1[i].y/B))]=i;
	}
	for(int i=1; i<=n; ++i)
	{
		for(int dx=-B+1; dx<B; ++dx) for(int dy=-B+1; dy<B; ++dy)
		{
			ull v=mp((int)(rp[i].x/B+dx), (int)(rp[i].y/B+dy));
			if(rid.count(v))
			{
				x[++tp]=i, y[tp]=rid[v];
				rid.erase(v);
				goto out;
			}
		}
		out:;
	}
	return tp*20>=k*19;
}
int rok[N], rok1[N];
int main()
{
	scanf("%d", &k);
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	scanf("%d", &m);
	for(int i=1; i<=m; ++i) scanf("%lf%lf", &p1[i].x, &p1[i].y);
	while(1)
	{
		int ptop=top, ptop1=top1;
		top+=conv(p, n, vis, stk+top);
		top1+=conv(p1, m, vis1, stk1+top1);
		for(int i=ptop; i<top1; ++i) for(int a=ptop1; a<top1; ++a)
		{
			int j=i+1, b=a+1;
			if(chk(stk[i], stk[j], stk1[a], stk1[b]))
			{
				for(int i=1; i<=std::min(k, tp); ++i) printf("%d %d\n", x[i], y[i]), rok[x[i]]=rok1[y[i]]=1;
				top=top1=0;
				for(int i=1; i<=n; ++i) if(!rok[i]) stk[++top]=i;
				for(int i=1; i<=m; ++i) if(!rok1[i]) stk1[++top1]=i;
				for(int i=1; i<=k-tp; ++i) printf("%d %d\n", stk[i], stk1[i]);
				return 0;
			}
		}
		for(int i=1; i<=top; ++i) for(int j=1; j<=top; ++j) if(i!=j&&(i>ptop||j>ptop))
			for(int a=1; a<=top1; ++a) for(int b=a+1; b<=top1; ++b) if(a!=b)
			{
				if(chk(stk[i], stk[j], stk1[a], stk1[b]))
				{
					for(int i=1; i<=std::min(k, tp); ++i) printf("%d %d\n", x[i], y[i]), rok[x[i]]=rok1[y[i]]=1;
					top=top1=0;
					for(int i=1; i<=n; ++i) if(!rok[i]) stk[++top]=i;
					for(int i=1; i<=m; ++i) if(!rok1[i]) stk1[++top1]=i;
					for(int i=1; i<=k-tp; ++i) printf("%d %d\n", stk[i], stk1[i]);
					return 0;
				}
			}
	}
	return 0;
}