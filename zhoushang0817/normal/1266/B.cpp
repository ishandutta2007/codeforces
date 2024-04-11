#include<bits/stdc++.h>
using namespace std;
long long t,x;
int main()
{
	cin>>t;
	while(t--&&cin>>x)
		if(x<14)
			cout<<"NO"<<'\n';
		else if(1<=x%14&&x%14<=6)
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	return 0;
}