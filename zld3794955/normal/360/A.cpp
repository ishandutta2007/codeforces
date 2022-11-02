#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=5050,M=5050,Inf=500000000;
int n,m,t[M]={},l[M]={},r[M]={},d[M]={};
long long a[N]={},b[N]={};
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=m;++i)
		cin>>t[i]>>l[i]>>r[i]>>d[i];
	fill(a+1,a+n+1,Inf);
	for(int i=m;i>=1;--i)
	{
		if(t[i]==1)
			for(int j=l[i];j<=r[i];++j)
				a[j]-=d[i];
		else
			for(int j=l[i];j<=r[i];++j)
				a[j]=min<long long>(a[j],d[i]);
	}
	copy(a+1,a+n+1,b+1);
	for(int i=1;i<=m;++i)
	{
		if(t[i]==1)
			for(int j=l[i];j<=r[i];++j)
				b[j]+=d[i];
		else
		{
			long long v=-Inf;
			for(int j=l[i];j<=r[i];++j)
				v=max(v,b[j]);
			if(v!=d[i])
			{
				puts("NO");
				return 0;
			}
		}
	}
	puts("YES");
	for(int i=1;i<=n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	return 0;
}