#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1;
int n,m,a[N],g,x;
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		g=__gcd(g,a[i]-a[i-1]);
	if(g==0)
	{
		while(m--&&cin>>x)
			cout<<a[1]+x<<' ';
		return 0;
	}
	while(m--&&cin>>x)
		cout<<__gcd(a[1]+x,g)<<' ';
	return 0;
}