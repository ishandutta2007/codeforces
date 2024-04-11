#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,a[N],r,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		a[i]=abs(a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		while(r<=n&&a[r]<=2*a[i])
			r++;
		A+=r-i-1;
	}
	cout<<A;
	return 0;
}