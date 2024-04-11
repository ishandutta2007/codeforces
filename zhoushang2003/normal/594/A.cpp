#include<bits/stdc++.h>
using namespace std;
int n,a[200001],A=1e9;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n/2;i++)
		A=min(A,a[i+n/2]-a[i]);
	cout<<A;
	return 0;
}