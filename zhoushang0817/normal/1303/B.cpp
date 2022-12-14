#include<bits/stdc++.h>
using namespace std;
long long t,n,g,b;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>g>>b)
		cout<<max(n,(n-1)/2/g*(g+b)+(n-1)/2%g+1)<<'\n';
	return 0;
}