#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e2;
int t,n,a[N],g;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),g=0;
		for(int i=1;i<n;i++)
			g=__gcd(g,a[i+1]-a[i]);
		if(!g)
			cout<<-1<<'\n';
		else
			cout<<g<<'\n';
	}
	return 0;
}