#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
long long n,k,m,a[N],s;
double A;
int main()
{
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		s+=a[i];
	A=(double)(s+min(k*n,m))/n;
	for(int i=0;i<min(m,n-1);i++)
		s-=a[i],A=max(A,(double)(s+min(k*(n-i-1),m-i-1))/(n-i-1));
	printf("%.9lf",A);
	return 0;
}