#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
long long n,k;
int main()
{
	scanf("%lld%lld",&n,&k);
	printf("%lld\n",(6*n-1)*k);
	for(int i=0;i<n;++i)
	{
		long long a1=6*i+1;
		long long a2=6*i+2;
		long long a3=6*i+3;
		long long a4=6*i+5;
		printf("%lld %lld %lld %lld\n",a1*k,a2*k,a3*k,a4*k);
	}
}