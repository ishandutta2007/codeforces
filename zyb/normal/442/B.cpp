#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int i,j,m,n,p,k;
double a[105];
int main()
{
	scanf("%d",&n);
	for (i=1;i<=n;++i) scanf("%lf",&a[i]);
	sort(a+1,a+n+1);
	double ans=0.,sum=1.,f=0.;
	for (i=n;i;--i)
	{
		   f=f*(1.-a[i])+sum*a[i];
		   ans=max(ans,f);
		   sum*=(1-a[i]);
	}
	printf("%.10lf\n",ans);
}