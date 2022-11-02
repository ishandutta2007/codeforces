#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int M=100010;
int n,m,a[M]={};
int main()
{	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
		scanf("%d",&a[i]);
	long long ans=0;
	a[0]=1;
	for(int i=1;i<=m;++i)
		ans+=a[i]>=a[i-1] ? a[i]-a[i-1] : n+a[i]-a[i-1];
	printf("%I64d\n",ans);
	return 0;
}