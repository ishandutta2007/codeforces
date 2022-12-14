#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
		cout<<n*(n+1)/2-(n-m)%(m+1)*((n-m)/(m+1)+1)*((n-m)/(m+1)+2)/2-(m+1-(n-m)%(m+1))*((n-m)/(m+1))*((n-m)/(m+1)+1)/2<<'\n';
	return 0;
}