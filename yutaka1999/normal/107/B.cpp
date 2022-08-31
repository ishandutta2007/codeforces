#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	int n,m,h;
	scanf("%d %d %d",&n,&m,&h);h--;
	int sum=0,on=0;
	for(int i=0;i<m;i++)
	{
		int a;
		scanf("%d",&a);
		sum+=a;
		if(i==h) on=a;
	}
	if(sum<n)
	{
		puts("-1.0");
		return 0;
	}
	double ret=1;
	for(int i=0;i<on-1;i++) ret*=(double) (sum-n-i)/(sum-i-1);
	printf("%.8f\n",1-ret);
	return 0;
}