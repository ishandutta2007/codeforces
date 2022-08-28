#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#define MX 100005

using namespace std;

long double dp[2][MX];
long double vl[MX];
long double logsum[MX];
long double v1,v2;

void make()
{
	logsum[0]=logsum[1]=0.0;
	for(int i=2;i<MX;i++) logsum[i]=logsum[i-1]+log(i);
}
long double per(int n,int k,int i)//nCi*(1/k)^i*(1-1/k)^(n-i)
{
	long double lg=logsum[n]-(logsum[i]+logsum[n-i]);
	lg-=v1*i;
	lg+=v2*(n-i);
	return exp(lg);
}
int main()
{
	make();
	int n,k;
	scanf("%d %d",&n,&k);
	int pos=0;
	dp[pos][1]=1.0;
	vl[0]=0.0;
	for(int i=1;i<=n;i++)
	{
		pos^=1;
		for(int j=1;j<=min(i+1,1000);j++) dp[pos][j]=0.0;
		vl[i]=vl[i-1];
		for(int j=1;j<=min(i,1000);j++)
		{
			dp[pos][j]+=dp[pos^1][j]*(long double) j/(long double) (j+1);
			dp[pos][j+1]+=dp[pos^1][j]*1.0/(long double) (j+1);
			vl[i]+=dp[pos^1][j]*((long double) j/2.0+(long double) j/(long double) (j+1));
		}
	}
	v1=log(k),v2=log(1.0-1.0/(long double) k);
	if(k==1) printf("%.10f\n",(double) vl[n]);
	else
	{
		long double ret=0.0;
		for(int i=0;i<=n;i++)
		{
			ret+=per(n,k,i)*vl[i];
		}
		printf("%.10f\n",(double) (ret*k));
	}
	return 0;
}