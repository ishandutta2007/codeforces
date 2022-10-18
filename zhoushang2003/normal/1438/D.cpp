#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n&1)
	{
		cout<<"YES"<<'\n'<<n-1<<'\n';
		for(int i=1;i<n;i+=2)
			cout<<i<<' '<<i+1<<' '<<n<<'\n';
		for(int i=1;i<n;i+=2)
			cout<<i<<' '<<i+1<<' '<<n<<'\n';
		return 0;
	}
	for(int i=1;i<=n;i++)
		A^=a[i];
	if(A)
	{
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<'\n'<<n-2<<'\n';
	for(int i=1;i<n-1;i+=2)
		cout<<i<<' '<<i+1<<' '<<n-1<<'\n';
	for(int i=1;i<n-1;i+=2)
		cout<<i<<' '<<i+1<<' '<<n-1<<'\n';
	return 0;
}