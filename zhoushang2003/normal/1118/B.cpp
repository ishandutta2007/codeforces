#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,a[N],x[N],y[N],A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	x[1]=a[1];
	for(int i=3;i<=n;i+=2)
		x[i]=x[i-2]+a[i];
	for(int i=2;i<=n;i+=2)
		y[i]=y[i-2]+a[i];
	if(x[(n-1)/2*2+1]-x[1]==y[n/2*2])
		A++;
	for(int i=2;i<=n;i++)
		if(x[(i-2)/2*2+1]+y[n/2*2]-y[i/2*2]==y[(i-1)/2*2]+x[(n-1)/2*2+1]-x[(i-1)/2*2+1])
			A++;
	cout<<A;
	return 0;
}