#import<bits/stdc++.h>
using namespace std;
int n,m;
main()
{
	for(cin>>n;cin>>n>>m;)
		cout<<((n==1||m==1)&&n+m>3?-1:n+m-2+abs(n-m)/2*2)<<'\n';
}