//f[i] >=i,min
#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],b[N],f[N],A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i],f[b[i]]=i;
		for(int i=2*n;i>1;i-=2)
			f[i-2]=min(f[i-2],f[i]);
		A=N;
		for(int i=1;i<=n;i++)
			A=min(A,i+f[a[i]+1]-2);
		cout<<A<<'\n';
	}
	return 0;
}