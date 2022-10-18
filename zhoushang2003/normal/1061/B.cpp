#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5;
long long n,m,a[N],s,M,l=2;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		M=max(M,a[i]),s+=a[i];
	sort(a,a+n);
	for(int i=1;i<n-1;i++)
		if(a[i]>=l&&l<M)
			l++;
	if(n==1||M==1)
		l--;
	cout<<s-M-n+l; 
	return 0;
}