#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
double ans;
int n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		ans+=(double)1/(double)(i);
	}
	printf("%.10lf",ans);
	return 0;
}