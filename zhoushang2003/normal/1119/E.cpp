#include<iostream>
using namespace std;
const int N=3e5+1;
long long n,a[N],s,q[N],t,A;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s+=a[i];
	for(int i=1;i<=n;i++)
		if(a[i]&1)
			a[i]--,s--,q[++t]=i;
	for(int i=n;i>=1;i--)
		while(t&&a[i])
			if(q[t--]<=i)
				a[i]-=2,s-=2,A++;
	cout<<A+s/3;
	return 0;
}