#include<bits/stdc++.h>
using namespace std;
const int N=3e5;
int n;
long long a[N],A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n/2;i++)
		A+=(a[i]+a[n-i-1])*(a[i]+a[n-i-1]);
	cout<<A;
	return 0;
}