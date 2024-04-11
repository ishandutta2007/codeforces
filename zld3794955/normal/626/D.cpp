#include<bits/stdc++.h>
using namespace std;
const int N=2020,V=10100;
int n,a[N]={};
long long tot[V]={},sum[V]={};
int main()
{	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	//n=2000;
	//for(int i=1;i<=n;++i)
	//	a[i]=i;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			++tot[abs(a[i]-a[j])];
	copy(tot,tot+V,sum);
	for(int i=5000;i>=0;--i)
		sum[i]+=sum[i+1];
	long long ans=0;
	double f=2.0/n/(n-1);
	for(int i=1;i<=5000;++i)
		for(int j=1;j<=5000;++j)
			ans+=tot[i]*tot[j]*sum[i+j+1];
	//cout<<"ans="<<ans<<endl;
	printf("%.10f\n",ans*f*f*f);
	return 0;
}