#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],b[N],l,r,p,q;
int C(int x)
{
	p=x-1,q=0;
	for(int i=1;i<=n;i++)
		if(p>=0&&a[i]>=p&&b[i]>=q)
			p--,q++;
	return p<0;
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		l=0,r=n;
		while(l<r)
			if(C((l+r+1)/2))
				l=(l+r+1)/2;
			else
				r=(l+r-1)/2;
		cout<<l<<'\n';
	}
}