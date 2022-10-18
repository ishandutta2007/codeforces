#include<bits/stdc++.h>
using namespace std;
long long t,n,k,A;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>k)
	{
		A=n%k,n=n/k*k;
		while(n)
			n/=k,A+=n%k+1,n=n/k*k;
		cout<<A<<'\n';
	}
	return 0;
}