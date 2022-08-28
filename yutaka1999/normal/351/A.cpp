#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#define SIZE 4005
#define EPS 1e-9

using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	int pl=0,sum=0;
	for(int i=0;i<2*n;i++)
	{
		double d;
		scanf("%lf",&d);
		d+=EPS;d*=1000;
		int v=(int) floor(d);
		v%=1000;
		sum+=v;
		if(v!=0) pl++;
	}
	if(pl<=n)
	{
		if(sum>=pl*1000)
		{
			double ret=(double) (sum-pl*1000)/1000.0;
			printf("%.3f\n",ret);
		}
		else
		{
			double a=(double) (sum%1000)/1000.0;
			double b=(double) (1000-sum%1000)/1000.0;
			printf("%.3f\n",min(a,b));
		}
	}
	else
	{
		int l=pl-n,r=n;
		// l<=can<=r
		if(r*1000<=sum)
		{
			double ret=(double) (sum-r*1000)/1000.0;
			printf("%.3f\n",ret);
		}
		else if(l*1000<=sum)
		{
			double a=(double) (sum%1000)/1000.0;
			double b=(double) (1000-sum%1000)/1000.0;
			printf("%.3f\n",min(a,b));
		}
		else
		{
			double ret=(double) (l*1000-sum)/1000.0;
			printf("%.3f\n",ret);
		}
	}
	return 0;
}