#include<iostream>
#include<cstdio>
#define db double
#define N 100100
using namespace std;

int n;
db ans,now,last;

int main()
{
	int i,j;
	db p;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lf",&p);
		now=now*p+p*last;
		ans+=p+now*2;
		last=p;
	}
	printf("%.10f",ans);
}