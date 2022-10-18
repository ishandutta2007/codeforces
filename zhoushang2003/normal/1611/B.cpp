#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,m;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
		if(n*3<=m)
			cout<<n<<'\n';
		else if(m*3<=n)
			cout<<m<<'\n';
		else
			cout<<(n+m)/4<<'\n';
}