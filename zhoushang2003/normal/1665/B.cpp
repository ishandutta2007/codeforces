#import<bits/stdc++.h>
using namespace std;
int n,u,x;
main()
{
	for(cin>>n;cin>>n;)
	{
		map<int,int>p;
		for(int i=1;i<=n;i++)
			cin>>x,u=max(u,++p[x]);
		cout<<n-u+__lg((n-1)/u)+(n!=u)<<'\n',u=0;
	}
}