#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,a[N],f[N],x;
int main()
{
	cin>>n,a[0]=1;
	for(int i=n;i>=1;i--)
		cin>>a[i];
	for(int i=n-1;i>=1;i--)
		a[i]=min(a[i],a[i+1]);
	for(int i=1;i<=n;i++)
		for(long long j=a[i],l=0;j>=1;j%=a[x])
			x=lower_bound(a+1,a+n+1,j)-a-1,f[i]=max(f[i],f[x]+(n-x)*(j-j%a[x]-a[x])+l),l+=(n-x)*(j-j%a[x]);
	cout<<f[n];
	return 0;
}