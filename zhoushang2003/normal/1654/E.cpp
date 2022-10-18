#include<bits/stdc++.h>
using namespace std;
const int N=5e7;
int n,a[N],c[2*N],A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=-400;i<=400;i++)
	{
		for(int j=1;j<=n;j++)
			A=max(A,++c[a[j]+j*i+N]);
		for(int j=1;j<=n;j++)
			c[a[j]+j*i+N]=0; 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=min(i+400,n);j++)
			if((a[j]-a[i])%(j-i)==0)
				A=max(A,++c[(a[j]-a[i])/(j-i)+N]+1);
		for(int j=i+1;j<=min(i+400,n);j++)
			c[(a[j]-a[i])/(j-i)+N]=0;
	}
	cout<<n-A;
}