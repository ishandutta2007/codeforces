#include<bits/stdc++.h>
using namespace std;
long long t,n,a,b;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>a>>b)
		cout<<n%2*a+n/2*min(2*a,b)<<endl;
	return 0;
}