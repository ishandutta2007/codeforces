#include<bits/stdc++.h>
using namespace std;
int n,x;
main()
{
	for(cin>>n;cin>>n;)
	{
		x=1<<__lg(n-1);
		for(int i=x-1;~i;i--)
			cout<<i<<' ';
		for(int i=x;i<n;i++)
			cout<<i<<' ';
		puts("");
	}
}