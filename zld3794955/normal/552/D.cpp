#include<bits/stdc++.h>
using namespace std;
const int N=2020;
int n,x[N]={},y[N]={};
pair<int,int> d[N];
long long ans=0;
inline int gcd(int a,int b)
{
	return b ? gcd(b,a%b) : a;
}
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>x[i]>>y[i];
	for(int i=1;i<=n;++i)
	{
		int tot=0;
		for(int j=1;j<=n;++j)
		{
			if(j==i)
				continue;
			int a=x[i]-x[j],b=y[i]-y[j];
			if(a<0 || (a==0 && b<0))
				a=-a,b=-b;
			int g=gcd(a,abs(b));
			a/=g,b/=g;
			d[++tot]=make_pair(a,b);
		}
		sort(d+1,d+tot+1);
		int p2=1;
		for(int j=1;j<=tot;j=p2)
		{
			int s=p2;
			p2=upper_bound(d+1,d+tot+1,d[s])-d;
			ans+=(long long)(p2-s)*(p2-s-1)/2;
		}
		//cout<<"ans="<<ans<<endl;
	}
	cout<<(long long)n*(n-1)*(n-2)/6-ans/3<<endl;
	return 0;
}