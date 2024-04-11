#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,T=100;
int n,x0,y0,x[N]={},y[N]={};
double calc(double a,int i)
{
	double x1=x[i]*a+x[i+1]*(1-a);
	double y1=y[i]*a+y[i+1]*(1-a);
	return sqrt(x1*x1+y1*y1);
}
int main()
{	
	scanf("%d%d%d",&n,&x0,&y0);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",x+i,y+i);
		x[i]-=x0,y[i]-=y0;
	}
	x[n+1]=x[1],y[n+1]=y[1];
	double r1=1e+64,r2=0;
	for(int i=1;i<=n;++i)
		r2=max(r2,sqrt(x[i]*1.0*x[i]+y[i]*1.0*y[i]));
	for(int i=1;i<=n;++i)
	{
		double l=0,r=1;
		for(int t=1;t<=T;++t)
		{
			double mid1=(l+l+r)/3,mid2=(l+r+r)/3;
			if(calc(mid1,i)<calc(mid2,i))
				r=mid2;
			else
				l=mid1;
		}
		r1=min(r1,calc(l,i));
	}
	printf("%.18f\n",pi*r2*r2-pi*r1*r1);
	return 0;
}