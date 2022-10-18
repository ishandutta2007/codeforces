#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,a[N],b[N],p[N],M,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n;i++)
		p[a[i]]=i;
	for(int i=1;i<=n;i++)
		b[i]=p[b[i]];
	M=b[n];
	for(int i=n-1;i>=1;i--)
	{
		if(b[i]>M)
			A++;
		M=min(M,b[i]);
	}
	cout<<A;
	return 0;
}