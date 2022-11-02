#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010,M=100100;
int n,m,k,l[M]={},r[M]={},d[M]={},d1[M]={},a[N]={};
long long d2[N]={};
int main()
{	
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;++i)
		scanf("%d%d%d",&l[i],&r[i],&d[i]);
	for(int i=1,x,y;i<=k;++i)
	{
		scanf("%d%d",&x,&y);
		++d1[x],--d1[y+1];
	}
	for(int i=1,now=0;i<=m;++i)
	{
		now+=d1[i];
		d2[l[i]]+=(long long)d[i]*now;
		d2[r[i]+1]-=(long long)d[i]*now;
	}
	long long s=0;
	for(int i=1;i<=n;++i)
	{
		s+=d2[i];
		printf("%I64d ",a[i]+s);
	}
	printf("\n");
	return 0;
}