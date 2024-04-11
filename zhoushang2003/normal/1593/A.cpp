#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,a,b,c;
signed main()
{
	cin>>t;
	while(t--&&cin>>a>>b>>c)
		cout<<max(0ll,max(b,c)+1-a)<<' '<<max(0ll,max(a,c)+1-b)<<' '<<max(0ll,max(a,b)+1-c)<<'\n'; 
	return 0;
}