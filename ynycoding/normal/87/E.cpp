#include <cstdio>
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#define x first
#define y second
#define point vec
#define eps (1e-6)
#define mp std::make_pair
#define pb push_back
#define db double
#define ld long double
using std::string;
using std::pair;
using std::abs;
using std::sqrt;
using std::max;
using std::vector;
using std::cin;
using std::cout;
typedef pair<ld, ld> vec;
const int N=200005;

inline int sgn(ld x) { return x>eps?1:x<-eps?-1:0; }
inline bool eq(ld a, ld b) { return abs(a-b)<eps; }
inline ld sqr(ld x) { return x*x; }
inline bool le(ld a, ld b) { return a<b+eps; }
inline bool ge(ld a, ld b) { return a>b-eps; }

const ld Pi=acos(-1.0);
inline int nxt(int x, int len) { return x==len-1?0:x+1; }
inline int nxt1(int x, int len) { return x==len?1:x+1; }
namespace Vector{
	//basic
	inline void print(const vec &a, int x=6) { printf("%.*lf %.*lf\n", x, (db)a.x, x, (db)a.y); }
	inline vec add(const vec &a, const vec &b) { return mp(a.x+b.x, a.y+b.y); }
	inline vec dec(const vec &a, const vec &b) { return mp(a.x-b.x, a.y-b.y); }
	inline ld cross(const vec &a, const vec &b) { return a.x*b.y-b.x*a.y; }
	inline ld pmul(const vec &a, const vec &b) { return a.x*b.x+a.y*b.y; }
	inline ld len2(const vec &a) { return a.x*a.x+a.y*a.y; }
	inline ld len(const vec &a) { return sqrt(len2(a)); }
	
	//operators
	vec operator +(const vec &a, const vec &b) { return add(a, b); }
	vec operator -(const vec &a, const vec &b) { return dec(a, b); }
	ld operator *(const vec &a, const vec &b) { return cross(a, b); }
	vec operator *(const vec &a, const ld &x) { return mp(a.x*x, a.y*x); }
	vec operator /(const vec &a, const ld &x) { return mp(a.x/x, a.y/x); }
	
	//check
	inline int chkdir(const vec &a, const vec &b) { return sgn(a*b)==0; }
	
	//angles
	inline ld angcos(const vec &a, const vec &b)
	{
		return pmul(a, b)/(len(a)*len(b));
	}
	inline ld angsin(const vec &a, const vec &b)
	{
		return a*b/(len(a)*len(b));
	}
	inline ld incline(const vec &a) { return atan2(a.y, a.x); }
	
	//rotate
	inline vec rotate(const vec &a, ld x)
	{
		return mp(a.x*cos(x)-a.y*sin(x), a.x*sin(x)+a.y*cos(x));
	}
	inline vec rotate90(const vec &a)
	{
		return mp(-a.y, a.x);
	}
	
	//distance
	inline ld dis(const point &a, const point &b) { return len(b-a); }
	inline ld dis2(const point &a, const point &b) { return len2(b-a); }
}
using namespace Vector;

namespace Line{
	struct line{
		point s, t;
	};
	//basic
	inline void print(const line &a, int x=6)
	{
		printf("%.*lf %.*lf -> %.*lf %.*lf\n", x, (db)a.s.x, x, (db)a.s.y, x, (db)a.t.x, x, (db)a.t.y);
	}
	inline vec tovec(const line &a) { return a.t-a.s; }
	inline ld maxx(const line &a) { return std::max(a.s.x, a.t.x); }
	inline ld minx(const line &a) { return std::min(a.s.x, a.t.x); }
	inline ld maxy(const line &a) { return std::max(a.s.y, a.t.y); }
	inline ld miny(const line &a) { return std::min(a.s.y, a.t.y); }
	inline ld incline(const line &a) { return Vector::incline(tovec(a)); }
	
	//intersect
	inline vec inter(const line &a, const line &b)
	{
		ld s1=(b.s-a.s)*(a.t-a.s), s2=(a.t-a.s)*(b.t-a.s);
		ld s=s1+s2;
		s1/=s, s2/=s;
		return b.s*s2+b.t*s1;
	}
	inline int chkdir(const line &a, const line &b) { return Vector::chkdir(tovec(a), tovec(b)); }
	inline int chkside(const point &a, const line &b)
	{
		return sgn(tovec(b)*(a-b.s));
	}
	inline int on(const point &a, const line &b)
	{
		int ret=0;
		ret|=(sgn((a-b.s)*tovec(b))==0);
		if(a.x<minx(b)-eps||a.x>maxx(b)+eps||a.y<miny(b)-eps||a.y>maxy(b)+eps) ret|=2;
		return ret;
	}
	inline int chkinter(const line &a, const line &b)
	{
		if(maxx(a)<minx(b)||maxx(b)<minx(a)||maxy(a)<miny(b)||maxy(b)<miny(a)) return 0;
		if(abs(tovec(a)*tovec(b))<eps) return 2;
		vec va=tovec(a), vb=tovec(b);
		return sgn((a.s-b.s)*vb)!=sgn((a.t-b.s)*vb)&&sgn((b.s-a.s)*va)!=sgn((b.t-a.s)*va);
	}
	inline int chkrayinter(const line &a, const line &b)// a is a ray
	{
		if(abs(tovec(a)*tovec(b))<eps) return 2;
		vec va=tovec(a), vb=tovec(b);
		ld s1=(a.s-b.s)*vb, s2=(a.t-b.s)*vb;
		if(s1<0) s1=-s1, s2=-s2;
		return sgn((b.s-a.s)*va)!=sgn((b.t-a.s)*va)&&s1>s2;
	}
	
	//distance
	inline ld dis(const point &a, const line &b)
	{
		return abs((a-b.s)*tovec(b))/len(tovec(b));
	}
	inline ld dis2(const point &a, const line &b)
	{
//		print(b);
//		printf("fa %Lf\n", len2(tovec(b)));
		return sqr((a-b.s)*tovec(b))/len2(tovec(b));
	}
	inline ld dis_seg(const point &a, const line &b)
	{
		if(sgn(pmul((a-b.s), tovec(b)))==sgn(pmul(a-b.t, tovec(b))))
		{
			return std::min(Vector::dis(a, b.s), Vector::dis(a, b.t));
		}
		return dis(a, b);
	}
	inline ld dis2_seg(const point &a, const line &b)
	{
		if(sgn(pmul((a-b.s), tovec(b)))==sgn(pmul(a-b.t, tovec(b))))
		{
			return std::min(Vector::dis2(a, b.s), Vector::dis2(a, b.t));
		}
		return dis2(a, b);
	}
	
	//relative points
	inline point foot(const point &a, const line &b)
	{
		ld s1=pmul((a-b.s), tovec(b)), s2=pmul((b.t-a), tovec(b));
		ld s=s1+s2;
		s1/=s, s2/=s;
		return b.s*s2+b.t*s1;
	}
	inline int foot_on(const point &a, const line &b)
	{
		return sgn(pmul((a-b.s), tovec(b)))!=sgn(pmul(a-b.t, tovec(b)));
	}
	inline point symmetry(const point &a, const line &b)
	{
		point t=foot(a, b);
		return t*2-a;
	}
}
using namespace Line;

namespace Polygon{
	//basic
	ld area(const vector<point> &p)
	{
		if(p.size()<=2) return 0;
		ld s=0;
		for(int i=0; i<p.size()-1; ++i) s+=p[i]*p[i+1];
		s+=(*p.rbegin())*p[0];
		return abs(s)/2;
	}
	ld parameter(const vector<point> &p)
	{
		if(p.size()<=1) return 0;
		ld ret=0;
		for(int i=0; i<p.size()-1; ++i) ret+=len(p[i+1]-p[i]);
		ret+=len(p[0]-*p.rbegin());
		return ret;
	}
	
	//convex
	int top;
	point cv, stk[N];
	bool cmp(const point &a, const point &b)
	{
		int s=sgn((a-cv)*(b-cv));
		return s==0?a.x<b.x:s>=0;
	}
	vector<point> convex(vector<point> p)
	{
		top=0;
		int id=0;
		cv=mp(1e9, 1e9);
		for(int i=0; i<p.size(); ++i) if((eq(cv.x, p[i].x)&&p[i].y<cv.y)||p[i].x<cv.x)
			cv=p[i], id=i;
		std::swap(p[0], p[id]);
		std::sort(p.begin()+1, p.end(), cmp);
		stk[++top]=p[0];
		for(int i=1; i<p.size(); ++i)
		{
			while(top>1&&sgn((p[i]-stk[top-1])*(stk[top]-stk[top-1]))>=0) --top;
			stk[++top]=p[i];
		}
		return vector<point>(stk+1, stk+top+1);
	}
	bool cmp1(const point &a, const point &b) { return eq(a.x, b.x)?a.y<b.y:a.x<b.x; }
	vector<point> convex_andrew(vector<point> p)
	{
		std::sort(p.begin(), p.end(), cmp1);
		int top=0;
		for(int i=0; i<p.size(); ++i)
		{
			point x=p[i];
			while(top>1&&chkside(stk[top], line{stk[top-1], x})>=0) --top;
			stk[++top]=x;
		}
		vector<point> ret(stk+1, stk+top+1);
		top=0;
		for(int i=p.size()-1; ~i; --i)
		{
			point x=p[i];
			while(top>1&&chkside(stk[top], line{stk[top-1], x})>=0) --top;
			stk[++top]=x;
		}
		for(int i=2; i<top; ++i) ret.pb(stk[i]);
		return ret;
	}
	
	vector<point> mergeconvex(const vector<point> &a, const vector<point> &b)
	{
		int l=0, r=0;
		vector<point> ret;
		int n=a.size(), m=b.size();
		while(l<n&&r<m)
		{
			ret.pb(a[l]+b[r]);
			if((sgn((a[nxt(l, n)]-a[l])*(b[nxt(r, m)]-b[r]))>=0)) ++l;
			else ++r;
		}
		while(l<n) ret.pb(a[l]+b[0]), ++l;
		while(r<m) ret.pb(a[0]+b[r]), ++r;
		return ret;
	}
	
	//checks
	int on(point t, const vector<point> &p)
	{
		for(int i=0; i<p.size(); ++i)
		{
			int j=nxt(i, p.size());
			if(on(t,line{p[i], p[j]})==1) return 1;
		}
		return 0;
	}
	int in(point t, const vector<point> &p)
	{
		line l=line{t, t+mp(10, 3*eps)};
		int ok=0;
		for(int i=0; i<p.size()-1; ++i) if(chkrayinter(l, line{p[i], p[i+1]})==1)
			++ok;//ok^=1;
		if(chkrayinter(l, line{*p.rbegin(), p[0]})==1) ++ok;//ok^=1;
		ok&=1;
		return ok;
	}
	int in_ang(point t, const vector<point> &p)//only for non-self-intersecting polygon
	{
		int ok=0;
		for(int i=0; i<p.size(); ++i)
		{
			int j=nxt(i, p.size());
			int a=sgn(p[i].y-t.y), b=sgn(p[j].y-t.y);
			if(a!=b)
			{
				if(sgn((p[i]-t)*(p[j]-t))>0)
				{
					if(a) ++ok;
					if(b) ++ok;
				}
				else
				{
					if(a) --ok;
					if(b) --ok;
				}
			}
		}
		return ok;
	}
	int in_ang(point t, point s, const vector<point> &p, const vector<ld> &a)//only for non-self-intersecting polygon
	{
		ld b=incline(t-s);
		int id=std::upper_bound(a.begin(), a.end(), b)-a.begin();
		if(!id&&eq(b, a[0])) ++id;
		if(id==a.size()&&eq(b, *a.rbegin())) --id;
		
		if(id==a.size()||id==0) return 0;
		int state=chkside(t, line{p[id], p[nxt(id, p.size())]});
		if(state==0) return on(t, line{p[id], p[nxt(id, p.size())]})==1;
		return state>0;
	}
	inline void fixconvex(vector<point> &a)
	{
		int id=0, top=0;
		for(int i=0; i<a.size(); ++i) if(a[i]<a[id]) id=i;
		std::rotate(a.begin(), a.begin()+id, a.end());
		while(a.size()>1&&eq(incline(a[a.size()-1]-a[0]), incline(a[a.size()-2]-a[0]))) a.pop_back();
		int d=0;
		while(d+2<a.size()&&eq(incline(a[d+2]-a[0]), incline(a[d+1]-a[0]))) ++d;
		for(int i=1; i+d<a.size(); ++i) std::swap(a[i], a[i+d]);
		a.resize(a.size()-d);
	}
	
	//rotating calipers
	inline ld diameter2(const vector<point> &p)
	{
		ld ans=0;
		int n=p.size();
		if(n==1) return 0;
		if(n==2) return Vector::dis2(p[0], p[1]);
		for(int i=0, j=0; i<n; ++i)
		{
			while(chkside(p[nxt(j, n)], line{p[j], p[j]-(p[nxt(i, n)]-p[i])})<=0) j=nxt(j, n);
			ans=std::max(ans, std::max(dis2(p[i], p[j]), dis2(p[nxt(i, n)], p[j])));
		}
		return ans;
	}
}
using Polygon::area;
using Polygon::parameter;
using Polygon::convex;
using Polygon::convex_andrew;
using Polygon::mergeconvex;
using Polygon::on;
using Polygon::in;
using Polygon::in_ang;
using Polygon::fixconvex;
using Polygon::diameter2;

namespace HalfPlaneIntersection{
	int low, top;
	point p[N];
	line l[N], stk[N];
	bool cmp(const line &a, const line &b) { return incline(a)<incline(b); }
	inline int HPIS(int n, const line *rl, line *ret, bool tp=0, point *rep=NULL)
	{
		std::copy(rl, rl+n+1, l);
		int rt=0;
		std::sort(l+1, l+n+1, cmp);
		for(int cl=1, cr; cl<=n; cl=cr+1)
		{
			cr=cl;
			while(cr<n&&chkdir(l[cl], l[cr+1])) ++cr;
			int id=cl;
			for(int i=cl; i<=cr; ++i) if(chkside(l[i].s, l[id])>0) id=i;
			l[++rt]=l[id];
		}
		low=1, top=0;
		for(int i=1; i<=rt; ++i)
		{
			while(top>low&&chkside(p[top], l[i])<0) --top;
			while(top>low&&chkside(p[low+1], l[i])<0) ++low;
			if(top>=low) p[top+1]=inter(l[i], stk[top]);
			stk[++top]=l[i];
		}
		while(top>low&&chkside(p[top], stk[low])<0) --top;
		p[low]=inter(stk[low], stk[top]);
		std::copy(stk+low, stk+top+1, ret+1);
		if(tp) std::copy(p+low, p+top+1, rep+1);
		return top-low+1;
	}
}
using HalfPlaneIntersection::HPIS;

namespace Circle{
	struct cir{
		point o;
		ld r;//r^2
	};
	//basic
	inline void print(const cir &c, int x=6)
	{
		printf("o: %.*lf %.*lf r:%.*lf\n", x, (db)c.o.x, x, (db)c.o.y, x, (db)sqrt(c.r));
	}
	inline int in(const point &a, const cir &b)
	{
		return sgn(b.r-Vector::dis2(a, b.o));
	}
	
	//advanced
	inline cir getcir(const point &a, const point &b, const point &c)
	{
		point B=(a+b)/2, C=(a+c)/2;
		point o=inter(line{B, B+rotate90(b-a)}, line{C, C+rotate90(c-a)});
		return cir{o, Vector::dis2(o, a)};
	}
	inline cir mincover(vector<point> p)
	{
		int n=p.size();
		cir c=cir{p[0], 0};
		std::random_shuffle(p.begin(), p.end());
		for(int i=0; i<n; ++i) if(in(p[i], c)==-1)
		{
			c=cir{p[i], 0};
			for(int j=0; j<i; ++j) if(in(p[j], c)==-1)
			{
				c=cir{(p[i]+p[j])/2, dis2(p[i], p[j])/4};
				for(int k=0; k<j; ++k) if(in(p[k], c)==-1)
				{
					c=getcir(p[i], p[j], p[k]);
				}
			}
		}
		return c;
	}
}
using namespace Circle;
int n, m, t, q;
point s;
vector<point> a, b, c;
int main()
{
	std::ios::sync_with_stdio(false);
	cin>>n;
	a.resize(n);
	for(int i=0; i<n; ++i) cin>>a[i].x>>a[i].y;
	cin>>m;
	b.resize(m);
	for(int i=0; i<m; ++i) cin>>b[i].x>>b[i].y;
	cin>>t;
	c.resize(t);
	for(int i=0; i<t; ++i) cin>>c[i].x>>c[i].y;
	fixconvex(a), fixconvex(b), fixconvex(c);
	vector<point> d=mergeconvex(mergeconvex(a, b), c);
	fixconvex(d);
	vector<ld> ang;
	s=*d.begin();
	for(int i=1; i<d.size(); ++i) ang.pb(incline(d[i]-s));
	cin>>q;
	for(int i=1; i<=q; ++i)
	{
		point t;
		cin>>t.x>>t.y;
		puts(in_ang(mp(t.x*3, t.y*3), s, d, ang)?"YES":"NO");
	}
	return 0;
}