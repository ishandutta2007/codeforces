#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
long long n,m,k,a[N],A;
int main()
{
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	cout<<m/(k+1)*(k*a[n-1]+a[n-2])+m%(k+1)*a[n-1];
	return 0;
}