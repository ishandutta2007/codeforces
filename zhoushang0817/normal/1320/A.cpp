#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=6e5+2;
long long n,a[N],c[M],A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[a[i]-i+N]+=a[i];
	}
	for(int i=1;i<=M;i++)
		A=max(A,c[i]);
	cout<<A;
	return 0;
}