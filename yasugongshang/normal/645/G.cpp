#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<bits/stdc++.h>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long double eps=1e-10;
struct point{
	long double x,y;
	point(long double _x=0,long double _y=0):x(_x),y(_y){}
	point operator +(const point b){return point(x+b.x,y+b.y);}
	point operator -(const point b){return point(x-b.x,y-b.y);}
	long double operator *(const point b){return x*b.x+y*b.y;}//dot
	long double operator ^(const point b){return x*b.y-b.x*y;}//cha
	point operator *(long double d){return point(x*d,y*d);}
	friend point operator *(long double d,const point x){return point(x.x*d,x.y*d);}
	point operator /(long double d){return point(x/d,y/d);}
	friend point operator /(long double d,const point x){return point(x.x/d,x.y/d);}
	point operator -(){return point(-x,-y);}
	bool operator ==(const point b){return fabs(x-b.x)<eps&&fabs(y-b.y)<eps;}
	bool operator !=(const point b){return !(*this==b);}
};
inline long double dist(point x,point y){return sqrt((x.x-y.x)*(x.x-y.x)+(x.y-y.y)*(x.y-y.y));}
inline point rotate(point x,long double angle){
	return point(x.x*cos(angle)-x.y*sin(angle),x.y*cos(angle)+x.x*sin(angle));
}
struct circle{
    point c;
    long double r;
    circle(point c, long double r) :c(c), r(r) {}
    point findpoint(long double a){
        return point(c.x+cos(a)*r,c.y+sin(a)*r);
    }
};
int dcmp(long double x){
    if(fabs(x)<1e-10) return 0;
    else
        return x < 0 ? -1 : 1;
}
long double angle(point A){  	
	return atan2(A.y,A.x);  
}
void getcirclecircleIntersection(circle C1,circle C2,vector<point>& sol){
    long double d=dist(C1.c,C2.c);
    if(dcmp(d)==0){
        if(dcmp(C1.r - C2.r) == 0) return ; return;
    }
    if(dcmp(C1.r+C2.r-d) < 0) return ; //
    if(dcmp(fabs(C1.r - C2.r) - d) > 0) return ; //
    long double a = angle(C2.c - C1.c); //C1C2
    long double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d)); //C1C2C1P1
    point p1 = C1.findpoint(a-da),p2 = C1.findpoint(a+da);
    sol.push_back(p1);
    if(p1 == p2) return;
    sol.push_back(p2);
    return ;
}
const long double pi=M_PI;
const int N=100005;
vector<point> v;
pair<long double,double> q[N<<1];
int n,A;
point a[N];
long double r[N];
inline bool cmp(pair<long double,long double> a,pair<long double,long double> b){
	return a.first==b.first?a.second>b.second:a.first<b.first;
}
set<long double> s;
set<long double>::iterator it;
bool check(long double x){
	vector<point> v; int nn=0;
	for(int i=1;i<=n;i++){
		long double dis=sqrt(sqr(a[i].x-A)+sqr(a[i].y));
		if (dis>r[i]+x || r[i]>dis+x || x>dis+r[i]) continue;
		long double u=atan2(a[i].y,a[i].x-A),t=acos((sqr(dis)+sqr(x)-sqr(r[i]))/(2.0*dis*x));
		long double ll=u-t,rr=u+t;
		if (ll<-pi) ll+=2*pi;
		if (ll>pi) ll-=2*pi;
		if (rr<-pi) rr+=2*pi;
		if (rr>pi) rr-=2*pi;
		if (ll>rr) {
			t=ll;ll=rr;rr=t;
		}
		q[++nn]=mp(ll,rr);
	}
	sort(&q[1],&q[nn+1]);  s.clear();
	for(int i=1;i<=nn;i++){
		it=s.upper_bound(q[i].first);
		if(it!=s.end()&&(*it)<q[i].second)return 1;
		s.insert(q[i].second);
	}
	return 0;
}
int main(){
	n=read(); A=read();
	for(int i=1;i<=n;i++){
		int x=read(),y=read();
		a[i]=point(x,y); r[i]=dist(a[i],point(-A,0));
	}
	long double l=0,r=2*A;
	while(l+eps<r&&l+l*eps<r){
		long double mid=(l+r)/2;
		if(check(mid))r=mid; else l=mid;
	}
	double ans=l;
	printf("%.8lf\n",ans);
}
/*
sqr(x-a.x)+sqr(y-a.y)=sqr(r) sqr(x-b.x)+sqr(y-b.y)=sqr(b.r)
x^2+a.x^2-2*x*a.x+y^2+a.y^2-2*y*a.y=r*r
x^2+b.x^2-2*x*b.x+y^2+b.y^2-2*y*b.y=b.r*b.r
(a.x-b.x)*(a.x+b.x)+2*x(b.x-a.x)+(a.y+b.y)*(a.y-b.y)
*/