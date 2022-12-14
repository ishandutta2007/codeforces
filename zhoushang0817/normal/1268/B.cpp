#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
long long n,a[N],A[2];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		A[i%2]+=a[i]/2,A[1-i%2]+=(a[i]+1)/2;
	cout<<min(A[0],A[1]);
	return 0;
}