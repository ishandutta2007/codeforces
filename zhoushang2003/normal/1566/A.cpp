#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,s;
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>s)
		cout<<s/(n-(n-1)/2)<<'\n';
	return 0;
}