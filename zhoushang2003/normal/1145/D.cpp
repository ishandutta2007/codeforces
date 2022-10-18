#include<iostream>
using namespace std;
int n,a[11],A=33;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		A=min(A,a[i]);
	cout<<(a[2]^A)+2;
	return 0;
}