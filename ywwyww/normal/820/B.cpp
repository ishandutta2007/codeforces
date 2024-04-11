#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	double ans1=1000000000ll;
	int ans2;
	double p=360./n/2;
	for(i=1;i<=n-2;i++)
		if(fabs(p*i-k)<fabs(k-ans1))
		{
			ans1=p*i;
			ans2=i;
		}
	printf("2 1 %d\n",ans2+2);
	return 0;
}