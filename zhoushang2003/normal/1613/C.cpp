#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3,I=1e18;
int t,n,h,a[N],l,r,A;
int C(int x)
{
	A=x;
	for(int i=1;i<n;i++)
		A+=min(x,a[i+1]-a[i]);
	return A>=h;
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>h)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		l=1,r=I;
		while(l<r)
			if(C((l+r)/2))
				r=(l+r)/2;
			else
				l=(l+r)/2+1;
		cout<<l<<'\n';
	}
}