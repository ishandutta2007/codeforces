#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;
typedef double ld;

inline ld sqr(ld x)
{
	return  x*x;
}
struct PP
{
	ld x,y;
	PP(ld x=0,ld y=0):x(x),y(y) { }
	friend PP operator +(PP a,PP b)
	{
		return PP(a.x+b.x,a.y+b.y);
	}
	friend PP operator -(PP a,PP b)
	{
		return PP(a.x-b.x,a.y-b.y);
	}
	friend PP operator *(PP a,ld b)
	{
		return PP(a.x*b,a.y*b);
	}
	friend PP operator /(PP a,ld b)
	{
		return PP(a.x/b,a.y/b);
	}
	friend ld det(PP a,PP b)
	{
		return a.x*b.y-a.y*b.x;
	}
	friend ld operator *(PP a,PP b)
	{
		return a.x*b.x+a.y*b.y;
	}
	friend ld dist(PP a,PP b)
	{
		return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
	}
	void read()
	{
		double _x,_y;
		scanf("%lf%lf",&_x,&_y);
		x=_x;
		y=_y;
	}
};

const int N=2005;
int n,w,h;
PP p[N];
double Ans=0;

inline ld F(PP a)
{
	double min1=1e30,min2=1e30,d;
	for (int i=1; i<=n; i++)
	{
		d=dist(a,p[i]);
		if (d<min1)
		{
			min2=min1,min1=d;
		}
		else
			min2=min(min2,d);
	}
	if (min2>Ans)
		Ans=max(Ans,min2);
	return min2;
}
inline bool jud(PP p)
{
	return p.x>=0 && p.x<=w && p.y>=0 && p.y<=h;
}
const double PI=acos(-1.0);
inline void SA()
{
	PP a=PP((rand()%1000)/1000.0*(double)w,(rand()%1000)/1000.0*(double)h),b;
	double ans=F(a),cur,delta;
	for (double T=sqrt((double)w*w+(double)h*h); T>1e-15; T*=.995)
	{
		double ang=rand()%100/100.0*2*PI;
		b=a+PP(cos(ang)*T,sin(ang)*T);
		if (!jud(b)) continue;
		cur=F(b);
		delta=cur-ans;
		if (delta>0)
			a=b,ans=cur;
	}
}

int main()
{
	srand(time(0));
	scanf("%d%d%d",&w,&h,&n);
	for (int i=1; i<=n; i++) p[i].read();
	const int Case=10;
	for (int i=1; i<=Case; i++)
		SA();
	printf("%.15lf\n",Ans);
	return 0;
}