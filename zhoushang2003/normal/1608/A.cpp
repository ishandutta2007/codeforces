#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cout<<i+1<<' ';
		cout<<'\n';
	}
}