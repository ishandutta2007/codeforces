#include<iostream>
using namespace std;
const int N=2e5+2,I=1e9+1;
int n,a[N];
long long A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=I;
	for(int i=n;i>=1;i--)
		a[i]=max(0,min(a[i],a[i+1]-1)),A+=a[i];
	cout<<A;
	return 0;
}