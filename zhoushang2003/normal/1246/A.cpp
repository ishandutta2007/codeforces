#include<bits/stdc++.h>
using namespace std;
int n,p;
int main()
{
	cin>>n>>p;
	for(int i=1;i<=1000000;i++)
		if(n-i*p>=0&&__builtin_popcount(n-i*p)<=i&&n-i*p>=i)
		{
			cout<<i;
			return 0; 
		}
	cout<<-1;
	return 0;
}