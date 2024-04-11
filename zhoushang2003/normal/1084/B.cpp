#include<iostream>
using namespace std;
const int N=1e3;
const long long I=1e18;
int n;
long long s,a[N],l=-1,r=I,c;
bool C(long long k)
{
	c=0;
	for(int i=0;i<n;i++)
		if(a[i]>k)
			c+=a[i]-k;
	return c>=s;
}
int main()
{
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		r=min(r,a[i]);
	while(l<r)
		if(C((l+r+1)/2))
			l=(l+r+1)/2;
		else
			r=(l+r-1)/2;
	cout<<l;
	return 0;
}