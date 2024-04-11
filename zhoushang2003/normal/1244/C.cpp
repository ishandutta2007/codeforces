#import<bits/stdc++.h>
using namespace std;
#define int long long
int n,p,w,d,x;
main()
{
	cin>>n>>p>>w>>d;
	for(int i=0;i<1e6;i++)
		if(p>=i*d&&(p-i*d)%w==0&&(x=(p-i*d)/w)+i<=n)
			cout<<x<<' '<<i<<' '<<n-x-i,exit(0);
	cout<<-1;
}