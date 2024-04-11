#include<iostream>
using namespace std;
const int N=2e5+1,M=1e5+1;
int n;
long long a[N],b[M],k;
int main()
{
	cin>>n;
	for(int i=1;i<=n/2;i++)
		cin>>b[i];
	a[1]=0,a[n]=b[1];
	for(int i=2;i<=n/2;i++)
		k=min(b[i]-a[i-1]*2,a[n-i+2]*2-b[i]),a[i]=(b[i]-k)/2,a[n-i+1]=(b[i]+k)/2;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	return 0;
}