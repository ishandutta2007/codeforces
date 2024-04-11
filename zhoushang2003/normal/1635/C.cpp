#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int T,n,a[N],A[N],B[N],C[N],t,v;
signed main()
{
	cin>>T;
	while(T--&&cin>>n)
	{
		t=v=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=n-2;i>=1;i--)
			if(a[i]>a[i+1]-a[n])
				a[i]=a[i+1]-a[n],A[++t]=i,B[t]=i+1,C[t]=n;
		for(int i=1;i<n;i++)
			if(a[i]>a[i+1])
				v=1;
		if(v)
		{
			puts("-1");
			continue;
		}
		cout<<t<<'\n';
		for(int i=1;i<=t;i++)
			cout<<A[i]<<' '<<B[i]<<' '<<C[i]<<'\n';
	}
}