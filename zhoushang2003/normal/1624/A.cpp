#import<bits/stdc++.h>
using namespace std;
int n,a[9999];
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		cout<<a[n]-a[1]<<'\n';
	}
}