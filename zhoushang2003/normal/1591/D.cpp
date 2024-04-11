#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],p[N],A,x,y,z;
void S(int l,int r)
{
	if(l==r)
		return;
	int d=(l+r)/2;
	S(l,d),S(d+1,r),x=z=l,y=d+1;
	while(x<=d&&y<=r)
		if(a[x]>a[y])
			p[z++]=a[y++],A+=d-x+1;
		else
			p[z++]=a[x++];
	while(x<=d)
		p[z++]=a[x++];
	while(y<=r)
		p[z++]=a[y++];
	for(int i=l;i<=r;i++)
		a[i]=p[i];
	
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		A=0,S(1,n);
		for(int i=1;i<n;i++)
			if(a[i]==a[i+1])
				A=0;
		if(A&1)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
}