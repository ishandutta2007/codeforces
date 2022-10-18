#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,k;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
		if(k==n-1)
		{
			if(n==4)
				cout<<-1<<'\n';
			else
			{
				cout<<1<<' '<<n-1<<'\n'<<0<<' '<<n-2<<'\n';
				for(int i=2;i<n/2-2;i++)
					cout<<i<<' '<<n-i-1<<'\n';
				cout<<n/2-2<<' '<<n/2-1<<'\n'<<n/2<<' '<<n/2+1<<'\n';
			}
			continue;
		}
		else
		{
			cout<<k<<' '<<n-1<<'\n';
			for(int i=1;i<n/2;i++)
				if(i!=k&&i!=n-k-1)
					cout<<i<<' '<<n-i-1<<'\n';
			if(k)
				cout<<0<<' '<<n-k-1<<'\n';
		}
}