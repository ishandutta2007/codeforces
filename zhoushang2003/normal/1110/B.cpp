#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m,k,a[N],A;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=n-1;i>0;i--)
		a[i]=a[i]-a[i-1]-1;
	if(n>1)
		sort(a+1,a+n);
	for(int i=1;i<=n-k;i++)
		A+=a[i];
	cout<<A+n;
	return 0;
}