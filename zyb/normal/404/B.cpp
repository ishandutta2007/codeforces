#include<stdio.h>
#include<algorithm>
using namespace std;
int i,j,k,l,s,m,n,f;
double nx,ny,x,y;
inline void check(double p)
{
	double s=0;
	int o;
	int b=1;
	while (b)
	{
		b=0;
		if (nx>p)
		{
			b=1;
			s=(nx-p);
			nx=p;
			if (f==1)
			ny+=s;
			else
			ny-=s;
			f=f%4+1;
		}
		if (nx<0)
		{
			b=1;
			s=-nx;
			nx=0;
			if (f==1)
			ny+=s;
			else
			ny-=s;
			f=f%4+1;
		}
		if (ny>p)
		{
			b=1;
			s=ny-p;
			ny=p;
			if (f==4)
			nx+=s;
			else
			nx-=s;
			f=f%4+1;
		}
		if (ny<0)
		{
			b=1;
			s=-ny;
			ny=0;
			if (f==4)
			nx+=s;
			else
			nx-=s;
			f=f%4+1;
		}
	}
}
int main()
{
	scanf("%lf%lf",&x,&y);
	scanf("%d",&n);
	while (y>=4*x)
	y-=4*x;
	f=1;
	while (n)
	{
		if (f==1)
		nx+=y;
		else
		if (f==2)
		ny+=y;
		else
		if (f==3)
		nx-=y;
		else
		if (f==4)
		ny-=y;
 		check(x);
		printf("%lf %lf\n",nx,ny);
		n--;
	}
}