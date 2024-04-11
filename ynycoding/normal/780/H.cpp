#include <cstdio>
#include <cmath>
#include <algorithm>
#define ld double
#define x first
#define y second
#define eps (1e-7)
using std::pair;
using std::sqrt;
using std::abs;
typedef pair<ld, ld> vec;
const int N=400005;

inline int sgn(ld x) { return x>eps?1:x<eps?-1:0; }
inline vec operator +(const vec &a, const vec &b) { return {a.x+b.x, a.y+b.y}; }
inline vec operator -(const vec &a, const vec &b) { return {a.x-b.x, a.y-b.y}; }
inline vec operator -(const vec &a) { return {-a.x, -a.y}; }
inline vec operator /(const vec &a, const ld &d) { return {a.x/d, a.y/d}; }
inline vec operator *(const vec &a, const ld &d) { return {a.x*d, a.y*d}; }
inline ld len(const vec &a) { return sqrt(a.x*a.x+a.y*a.y); }
inline ld len2(const vec &a) { return a.x*a.x+a.y*a.y; }
inline vec norm(const vec &a) { return a/len(a); }
inline ld cross(const vec &a, const vec &b) { return a.x*b.y-a.y*b.x; }
inline ld pmul(const vec &a, const vec &b) { return a.x*b.x+a.y*b.y; }
inline ld sqr(ld x) { return x*x; }
int n, m, tp, top;
vec p[N];
ld l[N], r[N], slen, rlen;
pair<ld, int> tag[N];
bool chk(ld c)
{
	int x=1, y=1;
	ld res=rlen;
	vec px=p[1], py=p[1];
	while(res>eps)
	{
		ld clen=len(p[y+1]-p[y]), t=std::min(clen, res);
		res-=t;
		// printf("t %Lf %Lf\n", t, res);
		py=p[y]+(p[y+1]-p[y])*(t/clen);
		if(res>eps) ++y;
	}
	top=tp=0;
	ld cs=0;
	ld c2=c*c;
	while(x<=n)
	{
		vec pos=py-px, v=norm(p[y+1]-p[y])-norm(p[x+1]-p[x]);
		ld lim=std::min(len(p[x+1]-px), len(p[y+1]-py));
		if(len(v)<eps)
		{
			if(len(pos)<c+eps) l[++tp]=cs, r[tp]=cs+lim;
		}
		else
		{
			ld b2=sqr(cross(pos, v))/len2(v);
			if(b2>c2) goto out;
			ld t=sqrt(c2-b2)/len(v);
			ld l1=pmul(v, -pos)/len2(v)-t, r1=l1+2*t;
			l[++tp]=std::max((ld)0, l1)+cs, r[tp]=std::min(lim, r1)+cs;
		}
		out:;
		cs+=lim;
		if(len(p[x+1]-px)<lim+eps) ++x, px=p[x];
		else px=px+norm(p[x+1]-p[x])*lim;
		if(len(p[y+1]-py)<lim+eps) ++y, py=p[y];
		else py=py+norm(p[y+1]-p[y])*lim;
	}
	int cur=0;
	for(int i=1; i<=tp; ++i) if(l[i]<r[i])
	{
		int x=l[i]/rlen, y=r[i]/rlen;
		cur+=y-x;
		tag[++top]={l[i]-x*rlen+eps, 1};
		tag[++top]={r[i]-y*rlen-eps, -1};
	}
	if(cur>=m) return 1;
	std::sort(tag+1, tag+top+1);
	for(int i=1; i<=top; ++i)
	{
		cur+=tag[i].y;
		if(cur>=m) return 1;
	}
	return 0;
}
int main()
{
	scanf("%d%d", &n, &m);
	if(m==1) return puts("0"), 0;
	for(int i=1; i<=n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
	std::copy(p+1, p+n+1, p+n+1);
	for(int i=1; i<=n; ++i) slen+=len(p[i+1]-p[i]);
	rlen=slen/m;
	ld l=0, r=rlen;
	while(l+eps<r)
	{
		ld mid=(l+r)/2;
		if(chk(mid)) r=mid;
		else l=mid;
	}
	printf("%.10lf\n", l);
	return 0;
}