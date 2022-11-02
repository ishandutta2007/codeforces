#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100100;
int n,x;
long long a[N]={};
int main()
{
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;++i)
		scanf("%I64d",&a[i]);
	long long v=*min_element(a+1,a+n+1),s=v*n;
	for(int i=1;i<=n;++i)
		a[i]-=v;
	while(a[x])
	{
		++s,--a[x];
		x=x==1 ? n : x-1;
	}
	a[x]=s;
	for(int i=1;i<=n;++i)
		printf("%I64d%c",a[i]," \n"[i==n]);
	return 0;
}