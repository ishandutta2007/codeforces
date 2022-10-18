#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,l,r,k,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>l>>r>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),A=0;
		for(int i=1;i<=n;i++)
			if(l<=a[i]&&a[i]<=r&&a[i]<=k)
				A++,k-=a[i];
		cout<<A<<'\n'; 
	}
	return 0;
}