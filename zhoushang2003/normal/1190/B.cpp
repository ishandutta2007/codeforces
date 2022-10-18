#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
long long n,a[N],c,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
		if(a[i]==a[i+1])
			c++;
	if(c>1||(a[1]==0&&a[2]==0))
	{
		cout<<"cslnb";
		return 0;
	}
	for(int i=2;i<n;i++)
		if(a[i]==a[i+1]&&a[i-1]==a[i]-1)
		{
			cout<<"cslnb";
			return 0;
		}
	for(int i=1;i<=n;i++)
		A+=a[i]-(i-1);
	if(A&1)
	{
		cout<<"sjfnb";
		return 0;
	}
	cout<<"cslnb";
	return 0;
}