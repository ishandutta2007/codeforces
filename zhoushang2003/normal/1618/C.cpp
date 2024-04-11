#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],x,y,u,v;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		x=y=u=v=0;
		for(int i=1;i<=n;i+=2)
			x=__gcd(x,a[i]);
		for(int i=2;i<=n;i+=2)
			y=__gcd(y,a[i]);
		for(int i=2;i<=n;i+=2)
			if(a[i]%x==0)
				u=1;
		for(int i=1;i<=n;i+=2)
			if(a[i]%y==0)
				v=1;
		if(!u)
			cout<<x<<'\n';
		else if(!v)
			cout<<y<<'\n';
		else
			cout<<0<<'\n';
	}
	return 0;
}