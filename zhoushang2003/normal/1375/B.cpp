#include<bits/stdc++.h>
using namespace std;
int t,n,m,x,v;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		v=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				cin>>x;
				if(x>4-(i==1)-(i==n)-(j==1)-(j==m))
					v=0;
			}
		if(!v)
		{
			cout<<"NO"<<'\n';
			continue;
		}
		cout<<"YES"<<'\n';
		for(int i=1;i<=n;i++,cout<<'\n')
			for(int j=1;j<=m;j++)
				cout<<4-(i==1)-(i==n)-(j==1)-(j==m)<<' ';
		cout<<'\n';
	}
	return 0;
}