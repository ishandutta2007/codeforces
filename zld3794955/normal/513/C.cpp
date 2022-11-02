#include<bits/stdc++.h>
using namespace std;
const int N=8;
int n,l[N]={},r[N]={};
inline double lessp(int l,int r,int p)
{
	if(p<l) return 0;
	if(p>r) return 1;
	return (p-l)*1.0/(r-l+1);
}
inline double calc(int v)
{
	double p1=1;
	for(int i=1;i<=n;++i)
		p1*=lessp(l[i],r[i],v);
	for(int i=1;i<=n;++i)
	{
		double p0=(1-lessp(l[i],r[i],v));
		for(int j=1;j<=n;++j)
			if(i!=j)
				p0*=lessp(l[j],r[j],v);
		p1+=p0;
	}
	return 1-p1;
}
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>l[i]>>r[i];
	int tr=*max_element(r+1,r+n+1);
	double ans=0;
	for(int i=1;i<=tr;++i)
		ans+=calc(i);
	printf("%.10f\n",ans);
	return 0;
}