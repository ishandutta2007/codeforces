#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
int n,m;
int main()
{	
	cin>>n>>m;
	for(int i=1;i<=n%m;++i)
		cout<<(n+m-1)/m<<' ';
	for(int i=n%m+1;i<=m;++i)
		cout<<n/m<<' ';
	cout<<endl;
	return 0;
}