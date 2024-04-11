#include<bits/stdc++.h>
using namespace std;
const int M=1048577;
long long n,x,s,a[2][M],A;
int main()
{
	cin>>n,a[0][0]++;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		s^=x,a[i&1][s]++;
	}
	for(int i=0;i<M;i++)
		A+=a[0][i]*(a[0][i]-1)/2+a[1][i]*(a[1][i]-1)/2;
	cout<<A;
	return 0;
}