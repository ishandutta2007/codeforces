#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1,M=2e6;
long long n,m,a[M],c[M],A,t;
int main()
{
	cin>>n>>m;
	if(n==1)
	{
	    cout<<0;
	    return 0;
	}
	for(int i=1;i<=m;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		c[i+N]=1;
	A=n,t=n-1,a[m+1]=-5e5;
	for(int i=1;i<=m+1;i++)
		A+=t-c[a[i]-i+N],c[a[i]-i-1+N]+=c[a[i]-i+N],c[a[i]-i+N]=0,t-=c[n-i+N];
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
		c[i]=1;
	t=n-1,a[m+1]=1e6;
	for(int i=1;i<=m+1;i++)
		A+=t-c[a[i]+i],c[a[i]+i+1]+=c[a[i]+i],c[a[i]+i]=0,t-=c[i+1];
	cout<<A;
	return 0;
}