#include<stdio.h>
#include<cmath>
#include<algorithm>
#define inf 100000000.0
#define eps 0.0000001
#define gg(x,y,x1,y1) sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1))
#define S(a,b,c,p) sqrt(p*(p-a)*(p-b)*(p-c))
using namespace std;
double ans,a[100005],bb[100005];
int i,j,n,l;
inline double getk(double x,double x1,double y,double y1)
{
	if (x-x1==0)
	return inf;
	return (y-y1)/(x-x1);
}
inline double getb(double x,double y,double k)
{
	return y-(k*x);
}
inline bool check(double x,double y,double k,double b,double xx)
{
	if (k==inf)
	{
		if (x<xx)
		return true;
		else 
		return false;
	}
	double y1=x*k+b;
	if (y>y1)
	return true;
	else
	return false;
}
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	scanf("%lf%lf",&a[i],&bb[i]);
	for (i=1;i<=n;i++)
	for (j=i+1;j<=n;j++)
	{
		double k=getk(a[i],a[j],bb[i],bb[j]);
		double b;
		if (a[j]==0||bb[j]==0)
		b=getb(a[i],bb[i],k);
		else
		b=getb(a[j],bb[j],k);
		double lmax=0,rmax=0;
		for (l=1;l<=n;l++)
		{
			if (l==i||l==j)
			continue;
			if (check(a[l],bb[l],k,b,a[i]))
			{
				double aa=gg(a[i],bb[i],a[j],bb[j]);
				double b1=gg(a[i],bb[i],a[l],bb[l]);
				double cc=gg(a[j],bb[j],a[l],bb[l]);
				lmax=max(lmax,S(aa,b1,cc,(aa+b1+cc)/2.0));
			}
			else
			{
				double aa=gg(a[i],bb[i],a[j],bb[j]);
				double b1=gg(a[i],bb[i],a[l],bb[l]);
				double cc=gg(a[j],bb[j],a[l],bb[l]);
				rmax=max(rmax,S(aa,b1,cc,(aa+b1+cc)/2.0));
			}
		}
		if (rmax>=eps&&lmax>=eps)
		ans=max(ans,rmax+lmax); 
	}
	printf("%.10lf",ans);

}