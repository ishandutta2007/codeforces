#include<iostream>
#include<cstdio>
using namespace std;
const double eps=1e-8;
int n,m,x[202000]={},y[202000]={},p[202000]={},q[202000]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&x[i],&y[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
		scanf("%d%d",&p[i],&q[i]);
	p[m+1]=p[1];
	q[m+1]=q[1];
}
inline double get_dir(double x1,double y1,double x2,double y2,double x3,double y3)
{
	return (x2-x1)*(y3-y1)-(x3-x1)*(y2-y1);
}
inline double get_dis(double x1,double y1,int i,double r)
{
	double x2=p[i]*(1-r)+p[i+1]*r;
	double y2=q[i]*(1-r)+q[i+1]*r;
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
void work()
{
	long long sx=0,sy=0,s=0;
	for(int i=1;i<=n;++i)
		sx+=x[i],sy+=y[i],s+=(long long)x[i]*x[i]+(long long)y[i]*y[i];
	double a=(double)sx/n,b=(double)sy/n,c=(double)s/n-a*a-b*b;
	bool in=true;
	for(int i=1;i<=m;++i)
		if(get_dir(p[i],q[i],p[i+1],q[i+1],a,b)>0)
		{
			in=false;
			break;
		}
	if(in)
		printf("%.12f\n",c*n);
	else
	{
		double k=1e+64;
		for(int i=1;i<=m;++i)
		{
			double l=0,r=1;
			while(r-l>eps)
			{
				double mid1=(l+l+r)/3;
				double mid2=(l+r+r)/3;
				if(get_dis(a,b,i,mid1)<get_dis(a,b,i,mid2))
					r=mid2;
				else
					l=mid1;
			}
			k=min(k,get_dis(a,b,i,l));
		}
		k+=c;
		printf("%.12f\n",k*n);
	}
}
int main()
{	
	init();
	work();
	return 0;
}