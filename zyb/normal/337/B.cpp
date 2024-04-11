#include<stdio.h>
using namespace std;
inline int gcd(int o,int p)
{
	if (o%p==0)
	return p;
	return gcd(p,o%p);
}
int n,m,x,y;
int main()
{
	scanf("%d%d%d%d",&n,&m,&x,&y);
	double nn=n*1.0,mm=m*1.0,xx=x*1.0,yy=y*1.0;
	if (nn/mm>xx/yy)
	{
		int dd=gcd(n,x);
		int gbs=n*x/dd;
		int bs=gbs/n,bs1=gbs/x;
		m=m*bs;
		y=y*bs1;
		int ans=y-m;
		int yy=gcd(ans,y);
		printf("%d/%d",ans/yy,y/yy);
	}
	else
	{
		int dd=gcd(m,y);
		int gbs=m*y/dd;
		int bs=gbs/m,bs1=gbs/y;
		n=n*bs;
		x=x*bs1;
		int ans=x-n;
		int yy=gcd(ans,x);
		printf("%d/%d",ans/yy,x/yy);
	}
}