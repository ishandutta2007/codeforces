#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,k,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),A=0;
		for(int i=1;i<=n-2*k;i++)
			A+=a[i];
		for(int i=1;i<=k;i++)
			A+=(a[n-2*k+i]==a[n-k+i]);
		cout<<A<<'\n';
	}
	return 0;
}