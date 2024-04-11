#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define PI 3.1415926535897932384626
#define INF 1e7

using namespace std;
typedef double ld;

struct point
{
    ld x,y;
};
point mp(ld x,ld y)
{
    point ret;
    ret.x=x;ret.y=y;
    return ret;
}
bool comp1(const point&l,const point&r)
{
    return l.x<r.x;
}
bool comp2(const point&l,const point&r)
{
    return l.y<r.y;
}
point in[4];
point rec[4];
ld xx[4],yy[4];

ld razi(ld a)
{
    return a/180*PI;
}
ld ABS(ld d)
{
    return d<0?-d:d;
}
point mazi1(point p,point q,ld x)
{
    return mp(x,(p.y-q.y)/(p.x-q.x)*(x-p.x)+p.y);
}
point mazi2(point p,point q,ld y)
{
    return mp((y-p.y)*(p.x-q.x)/(p.y-q.y)+p.x,y);
}
ld ryo(point x,point y)// <R
{
    return max((ld) 0,ABS(y.y-x.y)*ABS(y.x-x.x)/2);
}
int main()
{
    int ww,hh,aa;
    scanf("%d %d %d",&ww,&hh,&aa);
    ld w=ww,h=hh;
    if(aa==90)
    {
        printf("%.8f\n",min(w,h)*min(w,h));
        return 0;
    }
    if(aa==180||aa==0)
    {
        printf("%.8f\n",w*h);
        return 0;
    }
    else if(aa>90) aa=180-aa;
    ld a=razi((ld)aa);
    for(int i=0;i<4;i++)
    {
        if(i<2) in[i].y=h/2;
        else in[i].y=-h/2;
        if(i>0&&i<3) in[i].x=-w/2;
        else in[i].x=w/2;
        rec[i].x=in[i].x*cos(a)-in[i].y*sin(a);
        rec[i].y=in[i].x*sin(a)+in[i].y*cos(a);
        xx[i]=rec[i].x;
        yy[i]=rec[i].y;
    }
    sort(xx,xx+4);sort(yy,yy+4);
    if(xx[1]<-w/2&&xx[2]>w/2)
    {
        sort(rec,rec+4,comp1);
        printf("%.8f\n",w*ABS(mazi1(rec[1],rec[3],-w/2).y-mazi1(rec[0],rec[2],-w/2).y));
        return 0;
    }
    if(yy[1]<-h/2&&yy[2]>h/2)
    {
        sort(rec,rec+4,comp2);
        printf("%.8f\n",h*ABS(mazi2(rec[1],rec[3],-h/2).x-mazi2(rec[0],rec[2],-h/2).x));
        return 0;
    }
    ld ret=w*h;
    ret-=2*ryo(mazi2(rec[0],rec[1],h/2),mazi1(rec[0],rec[1],-w/2));
    ret-=2*ryo(mazi2(rec[1],rec[2],-h/2),mazi1(rec[1],rec[2],-w/2));
    printf("%.8f\n",ret);
    return 0;
}