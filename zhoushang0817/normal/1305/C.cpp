#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=1e3;
long long n,m,p[N],a[M],A=1,t;
long long P(long long a,long long b)
{
	t=1;
	while(b)
	{
		if(b&1)
			(t*=a)%=m;
		(a*=a)%=m,b/=2; 
	}
	return t;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	if(n>m)
	{
		cout<<0;
		return 0;
	}
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
			(A*=P((p[i]-j)%m,a[j]))%=m;
		a[p[i]%m]++;
	}
	cout<<A;
	return 0;
}