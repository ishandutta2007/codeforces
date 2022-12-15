#include<bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	cin>>n>>m;
	if(m==1)
	{
		if(n==1)
			cout<<0;
		else
			for(int i=1;i<=n;i++)
				cout<<i+1<<'\n';
		return 0; 
	}
	for(int i=1;i<=n;i++,cout<<'\n')
		for(int j=1;j<=m;j++)
			cout<<i*(n+j)<<' ';
	return 0;
}