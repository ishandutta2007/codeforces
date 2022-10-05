#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define eps 0.000000000001
#define inf 100000000000000000
using namespace std;
int n,ans=0,die[1200];
double x[1200],y[1200],k[1200],x00,y00;

int main()
{
	scanf("%d%lf%lf",&n,&x00,&y00);
	for (int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		x[i]-=x00;y[i]-=y00;
		if (x[i]==0)
			k[i]=inf;
		else
			k[i]=y[i]/x[i];
	}
	for (int i=1;i<=n;i++)
	{
		if (die[i]) continue;
		ans++;
		for (int j=i+1;j<=n;j++)
			if (abs(k[i]-k[j])<eps)
				die[j]=1;
	}
	printf("%d",ans);
}