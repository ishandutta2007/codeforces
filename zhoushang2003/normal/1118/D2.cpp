#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
long long n,m,a[N],s,l,r,q[N],t,c;
bool C(int k)
{
	t=c=0;
	for(int i=1;i<=n%k;i++)
		for(int j=1;j<=n/k;j++)
			q[t++]=j;
	for(int i=1;i<=k-n%k;i++)
		for(int j=1;j<n/k;j++)
			q[t++]=j;
	if(t>0)
		sort(q,q+t);
	for(int i=1;i<=t;i++)
		c+=min(a[i],q[t-i]);
	if(s-c>=m)
		return true;
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		s+=a[i];
	l=1,r=n;
	while(l<r)
		if(C((l+r)/2))
			r=(l+r)/2;
		else
			l=(l+r)/2+1;
	if(C(l))
		cout<<l;
	else
		cout<<-1;
	return 0;
}