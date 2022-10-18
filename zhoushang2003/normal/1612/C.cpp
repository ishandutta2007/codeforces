#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,k,n,l,r;
int C(int x)
{
	if(x<=k)
		return x*(x+1)/2>=n;
	return k*(k+1)/2+(3*k-x-1)*(x-k)/2>=n;
}
signed main()
{
	cin>>t;
	while(t--&&cin>>k>>n)
	{
		l=0,r=2*k-2;
		while(l<r)
			if(C((l+r+1)/2))
				r=(l+r-1)/2;
			else
				l=(l+r+1)/2;
		cout<<l+1<<'\n';
	}
}