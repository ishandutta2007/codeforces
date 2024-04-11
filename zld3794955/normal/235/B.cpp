#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=100010;
int n;
double p[N]={},ans=0,l[N]={},r[N]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf",p+i);
	for(int i=1;i<=n;++i)
		l[i]=(l[i-1]+1)*p[i];
	for(int i=n;i>=1;--i)
		r[i]=(r[i+1]+1)*p[i];
	ans+=accumulate(l+1,l+n+1,0.0);
	ans+=accumulate(r+1,r+n+1,0.0);
	ans-=accumulate(p+1,p+n+1,0.0);
	printf("%.15f\n",ans);
	return 0;
}