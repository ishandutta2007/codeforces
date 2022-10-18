#import<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e7;
int n,l,r,a[N],p[N],d,y;
int C(int x)
{
	for(int i=1;i<=n;i++)
		p[i]=a[i];
	for(int i=n;i>2;i--)
		if(p[i]>=x)
			y=min(a[i],p[i]-x)/3,p[i-1]+=y,p[i-2]+=2*y;
	for(int i=1;i<=n;i++)
		if(p[i]<x)
			return 0;
	return 1;
}
main()
{
	for(cin>>n;cin>>n;)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		l=1,r=1e9;
		while(l<r)
			C(d=(l+r+1)/2)?l=d:r=d-1;
		cout<<l<<'\n';
	}
}