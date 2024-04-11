#import<bits/stdc++.h>
using namespace std;
const int N=2e6;
int n,a[N],A[N],f[N],g[N],u;
main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		f[i]=max(a[i],a[i+1]),g[i]=max(min(a[i],a[i-1]),min(a[i],a[i+1])),u=max(u,a[i]);
	A[1]=n&1?g[n/2+1]:f[n/2];
	for(int i=2;i<n;i++)
		A[i]=max(A[i-2],(n+i)&1?max(f[(n+1-i)/2],f[(n+i)/2]):max(g[(n+2-i)/2],g[(n+1+i)/2]));
	for(int i=1;i<n;i++)
		cout<<A[i]<<' ';
	cout<<u;
}