#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,y,z;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>x>>y)
	{
		while(n--&&cin>>z)
			y^=z;
		puts((x+y)&1?"Bob":"Alice");
	}
}