#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
using namespace std;

#define LL __int64

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pll;
typedef vector<int> vi;

template< typename T >
inline void read(T &res)
{
    T x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=!f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    res = f ? -x : x ;
}

template< typename T >
inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T >
inline void Min(T &a, T b) {if(b<a) a=b;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 1e5+20;
const int maxm=(int) 1e6+15;

inline int sig(double x) {return x<-eps?-1:x>eps;}
inline void fadd(LL &x,LL a) {x+=a; if(x>=MOD) x-=MOD;}

//--------------start------------------

struct point
{
    double x,y;
    point(double _x=0.0,double _y=0.0):x(_x),y(_y) {}

    point operator + (const point &t) const {return point(x+t.x,y+t.y);}
    point operator - (const point &t) const {return point(x-t.x,y-t.y);}
    point operator * (const double t) const {return point(x*t,y*t);}
    point operator / (const double t) const {return point(x/t,y/t);}
    double operator ^ (const point &t) const {return x*t.y-y*t.x;}
    double operator * (const point &t) const {return x*t.x+y*t.y;}

    void print() {printf("%.4lf %.4lf\n",x,y);}

    point ro(double ct)
    {
        double _x,_y;
        _x=x*cos(ct)-sin(ct)*y;
        _y=x*sin(ct)+cos(ct)*y;
        return point(_x,_y);
    }

    inline double dis2(point t) {return (t.x-x)*(t.x-x)+(t.y-y)*(t.y-y);}
    double dis(point t) {return sqrt(dis2(t));}
};

struct circle
{
    point o;
    double r;
    circle() {}
    circle(point _o,double _r):o(_o),r(_r) {}
    bool ins(point t) { return sig(o.dis(t)-r)<0; }
    bool far(circle t) { return sig(o.dis(t.o)-r-t.r)>0; }
    bool onc(point t) { return sig(o.dis(t)-r)==0; }
}C[maxn],CO;

void qie(point o,circle c,pair<point,point> &pp)
{
    double d,f,ct;
    point N;
    d=o.dis(c.o);
    N=(c.o-o)/d;
    ct=asin(c.r/d);
    f=sqrt(d*d-c.r*c.r);
    pp.fi=N.ro(ct)*f + o;
    pp.se=N.ro(-ct)*f + o;
}

void Get(circle a,circle b,pair<point,point> &pp)
{
    double d=a.o.dis(b.o),ct;
    point N;
    N=(b.o-a.o)/d;
    ct=acos((a.r*a.r+d*d-b.r*b.r)/(2.0*a.r*d));
    pp.fi=N.ro(ct)*a.r + a.o;
    pp.se=N.ro(-ct)*a.r + a.o;
}

void On_get(point a,point b,pair<point,point> &pp)
{
    point N;
    N=b-a;
    pp.fi=N.ro(pi/2.0) + a;
    pp.se=N.ro(-pi/2.0) + a;
}

int n;
point O;
double L,v,T;

int pcnt;
pair<double,int> p[maxn<<2];

void add_interval(double L,double R)
{
    if(L<0) L+=2*pi;
    if(R<0) R+=2*pi;

//    cout <<L/pi*180.0 <<" " <<R/pi*180.0 <<endl;

    p[pcnt++]=mk(L,1); p[pcnt++]=mk(R,-1);
    if(L>R) p[pcnt++]=mk(2*pi,-1), p[pcnt++]=mk(0,1);
}

bool spj_check(LL x,LL y,LL _x,LL _y,LL r)
{
    LL dx=x-_x, dy=y-_y;
    return r*r>=dx*dx+dy*dy;
}

void work()
{
    while(~scanf("%lf%lf%lf%lf",&O.x,&O.y,&v,&T))
    {
        L=v*T;
        CO=circle(O,L);
        scanf("%d",&n);
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            double _x,_y,_r; scanf("%lf%lf%lf",&_x,&_y,&_r);
            C[i]=circle(point(_x,_y),_r);

            if(spj_check(O.x,O.y,C[i].o.x,C[i].o.y,C[i].r)) flag=1;
        }

        if(flag)
        {
            puts("1.0000");
            continue;
        }
        pair<point,point> temp;
        pcnt=0;
        for(int i=0;i<n;i++)
        {
            if(CO.far(C[i])) continue;
            qie(O,C[i],temp);
            if(CO.ins(temp.fi)==0) Get(CO,C[i],temp);
            if(C[i].onc(O)) On_get(O,C[i].o,temp);
//            temp.fi.print();
//            temp.se.print();
            temp.fi=temp.fi-O;
            temp.se=temp.se-O;
            add_interval(atan2(temp.se.y,temp.se.x),atan2(temp.fi.y,temp.fi.x));
        }
        p[pcnt++]=mk(0,0); p[pcnt++]=mk(2.0*pi,0);
        sort(p,p+pcnt);
        double tot=0.0;
        int cnt=p[0].se;
        for(int i=1;i<pcnt;i++)
        {
            if(cnt) tot+=p[i].fi-p[i-1].fi;
            cnt+=p[i].se;
        }
        printf("%.12lf\n",tot/(2.0*pi));
    }
}

//--------------end--------------------

//#define yukihana0416
int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}