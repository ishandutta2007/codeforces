#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		if(n==1)
		{
			cout<<-1<<'\n';
			continue;
		}
		for(int i=3;i<=n;i++)
			cout<<3;
		cout<<23<<'\n';
	}
	return 0;
}