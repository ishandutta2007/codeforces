#include<iostream>
using namespace std;
const int N=2e5+1;
int n,a[N],s[N],A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	A=s[n];
	for(int i=n-1;i>1;i--)
		A=max(A,s[i]-A);
	cout<<A;
	return 0;
}