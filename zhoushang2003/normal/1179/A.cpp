#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,q,a[N],A[N],B[N],x;
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		A[i]=a[i],B[i]=a[i+1];
		if(a[i]>a[i+1])
			swap(a[i],a[i+1]);
		a[n+i]=a[i];
	}
	while(q--&&cin>>x)
		if(x<=n)
			cout<<A[x]<<' '<<B[x]<<'\n';
		else
			cout<<a[n+1]<<' '<<a[n+2+(x-2)%(n-1)]<<'\n';
	return 0;
}