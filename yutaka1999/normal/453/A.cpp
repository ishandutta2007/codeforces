#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

double mpow(double d,int t)
{
	if(t==0) return 1.0;
	double ret=mpow(d,t/2);
	ret=ret*ret;
	if(t%2==1) ret=ret*d;
	return ret;
}
int main()
{
	int m,n;
	scanf("%d %d",&m,&n);
	double ret=0;
	for(int i=1;i<=m;i++)
	{
		double p=mpow((double) i/(double) m,n)-mpow((double) (i-1)/(double) m,n);
		ret+=p*i;
	}
	printf("%.8f\n",ret);
	return 0;
}