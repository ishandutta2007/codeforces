#include<bits/stdc++.h>
using namespace std;
int t,n,x,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		A=0;
		while(n--&&cin>>x)
			A|=x;
		cout<<A<<'\n';
	}
}