#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e5;
int n,A[N],C;
long long a[N],p[N],s,x,y;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		p[i]=a[i];
	sort(p,p+n);
	for(int i=0;i<n;i++)
		s+=p[i];
	if(s-p[n-1]==p[n-2]*2)
		x=p[n-1];
	if(s-2*p[n-1]!=p[n-1])
		y=s-2*p[n-1];
	for(int i=0;i<n;i++)
		if(a[i]==x||a[i]==y)
			A[C++]=i+1;
	cout<<C<<endl;
	for(int i=0;i<C;i++)
		cout<<A[i]<<" ";
	return 0;
}