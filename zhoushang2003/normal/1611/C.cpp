#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(a[1]==n||a[n]==n)
		{
			for(int i=n;i;i--)
				cout<<a[i]<<' ';
			cout<<'\n';
		}
		else
			cout<<-1<<'\n';
	}
}