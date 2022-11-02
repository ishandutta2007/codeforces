#include<bits/stdc++.h>
#define maxn 100050
#define eps 1E-7
using namespace std;
typedef long long LL;

int n;
LL x[maxn],y[maxn];

void init()
{
	scanf("%d",&n);
	for (int i=1;i<=n;++i)
		scanf("%lld%lld",&x[i],&y[i]);
}

bool judge()
{
	for (int i=2;i<=n;++i)
		if (y[i]*y[1]<0)
			return 0;
	return 1;
}

double sq(double x)
{
	return x*x;
}

double calc(double X)
{
	double r=0;
	for (int i=1;i<=n;++i)
		r=max(r,abs((double)y[i]+sq((double)x[i]-X)/y[i]));
	return r;
}

void solve()
{
	double l=-1E10,r=1E10;
	for (int k=0;k<1000;++k)
	{
		double m1=(2.0*l+r)/3.0,m2=(l+2.0*r)/3.0;
//		printf("%.10lf %.10lf %.10lf %.10lf\n",l,r,m1,m2);
		if (calc(m1)>calc(m2))
			l=m1;
		else
			r=m2;
	}
	printf("%.10lf\n",calc(l)/2);
}

int main()
{
//	freopen("c.in","r",stdin);
	init();
	if (judge())
		solve();
	else
		puts("-1");
	return 0;
}