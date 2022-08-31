#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 100005
#define EPS 1e-15
#define DINF 1e20
#define PI 3.14159265358979

using namespace std;
typedef long double ld;

struct L
{
	ld a,b,c;// ax+by+c=0
	L(ld a=0.0,ld b=0.0,ld c=0.0):a(a),b(b),c(c){}
};
struct P
{
	ld x,y;
	P(ld x=0.0,ld y=0.0):x(x),y(y){}
};
struct SG
{
	P p,q;
	SG(P p,P q):p(p),q(q){}
};
ld ABS(ld a){return max(a,-a);}
P inter(L s,L t)
{
	ld det=s.a*t.b-s.b*t.a;
	if(ABS(det)<EPS) return P(DINF,DINF);
	return P((-t.b*s.c+s.b*t.c)/det,(-t.c*s.a+s.c*t.a)/det);
}
L convLine(P s,P t)// (x1,y1),(x2,y2)^
{
	ld theta=atan2(t.y-s.y,t.x-s.x);
	ld A=sin(theta);
	ld B=-cos(theta);
	ld C=-(s.x*A+s.y*B);
	return L(A,B,C);
}
L perpend(L s,P t)
{
	//ax+by+c=0  bx-ay+hoge=0
	return L(s.b,-s.a,s.a*t.y-s.b*t.x);
}
P foot(L s,P t)
{
	L l=perpend(s,t);
	return inter(s,l);
}
bool contain_S(SG s,P t)//tconvLine(s.p,s.q)Ats
{
	ld lx=min(s.p.x,s.q.x),rx=max(s.p.x,s.q.x);
	if(ABS(lx-rx)>EPS) return lx+EPS<=t.x&&t.x+EPS<=rx;
	ld ly=min(s.p.y,s.q.y),ry=max(s.p.y,s.q.y);
	return ly+EPS<=t.y&&t.y+EPS<=ry;
}
ld norm(P a)
{
	return a.x*a.x+a.y*a.y;
}
ld dist_P(P s,P t)
{
	return sqrt(norm(P(s.x-t.x,s.y-t.y)));
}
ld dist_L(L s,P t)// _
{
	return ABS(s.a*t.x+s.b*t.y+s.c)/sqrt(s.a*s.a+s.b*s.b);
}
ld dist_S(SG s,P t)
{
	ld ret=min(dist_P(s.p,t),dist_P(s.q,t));
	P f=foot(convLine(s.p,s.q),t);
	if(contain_S(s,f)) ret=dist_L(convLine(s.p,s.q),t);
	return ret;
}
P vt[SIZE];

int main()
{
	int n;
	int x,y;
	scanf("%d %d %d",&n,&x,&y);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		vt[i]=P(a,b);
	}
	ld mn=DINF,mx=0.0;
	for(int i=0;i<n;i++)
	{
		int nxt=(i+1)%n;
		ld d=dist_S(SG(vt[i],vt[nxt]),P(x,y));
		mn=min(mn,d);
		ld e=dist_P(vt[i],P(x,y));
		mx=max(mx,e);
	}
	ld calc=mx*mx-mn*mn;
	printf("%.10f\n",(double) calc*PI);
	return 0;
}