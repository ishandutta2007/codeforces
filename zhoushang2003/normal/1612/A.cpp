#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,x,y;
signed main()
{
	cin>>t;
	while(t--&&cin>>x>>y)
		if((x+y)&1)
			cout<<"-1 -1\n";
		else
			cout<<x/2<<' '<<(y+1)/2<<'\n';
}