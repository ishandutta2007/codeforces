#include<bits/stdc++.h>
using namespace std;
int t,x,y,z;
int main()
{
	cin>>t;
	while(t--&&cin>>x>>y>>z)
	{
		if(x==y)
		{
			if(x<z)
			{
				cout<<"NO"<<'\n';
				continue;
			}
			cout<<"YES"<<'\n'<<x<<' '<<1<<' '<<z<<'\n';
			continue;
		}
		else if(x==z)
		{
			if(x<y)
			{
				cout<<"NO"<<'\n';
				continue;
			}
			cout<<"YES"<<'\n'<<1<<' '<<x<<' '<<y<<'\n';
			continue;
		}
		else if(y==z)
		{
			if(y<x)
			{
				cout<<"NO"<<'\n';
				continue;
			}
			cout<<"YES"<<'\n'<<x<<' '<<1<<' '<<y<<'\n';
			continue;
		}
		cout<<"NO"<<'\n';
	}
	return 0;
}