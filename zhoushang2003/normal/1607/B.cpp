#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
main()
{
	for(cin>>n;cin>>x>>n;)
	{
		for(int i=n/4*4+1;i<=n;i++)
			x+=(x&1?i:-i);
		cout<<x<<'\n';
	}
}