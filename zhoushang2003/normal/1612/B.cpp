#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,a,b;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>a>>b)
	{
		if(a==n/2+1&&b==n/2)
		{
			for(int i=1;i<=n;i++)
				cout<<n-i+1<<' ';
			puts("");
			continue;
		}
		if(a>n/2||b<=n/2)
		{
			puts("-1");
			continue;
		}
		cout<<a<<' ';
		for(int i=n;i;i--)
			if(i!=a&&i!=b)
				cout<<i<<' ';
		cout<<b<<'\n';
	}
}