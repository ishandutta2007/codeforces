#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n,a[N];
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<a[0]<<" ";
	for(int i=1;i<=n/2;i++)
		cout<<a[i*2-1]<<" ";
	for(int i=n/2+1;i<n;i++)
		cout<<a[(n-i)*2]<<" ";
	return 0;
}