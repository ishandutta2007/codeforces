#include<bits/stdc++.h>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=2020;
int n,a[N]={},v[N]={};
int main()
{	
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	copy(a+1,a+n+1,v+1);
	sort(v+1,v+n+1,greater<int>());
	for(int i=1;i<=n;++i)
		cout<<lower_bound(v+1,v+n+1,a[i],greater<int>())-v<<' ';
	cout<<endl;
	return 0;
}