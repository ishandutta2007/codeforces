#include<bits/stdc++.h>
using namespace std;
int t,l,r,n,a[999999],s,g;
int main()
{
	cin>>t;
	while(t--&&cin>>l>>r)
	{
		n=r+1;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1),s=0,g=1;
		while(n%2==0)
			n/=2,g*=2;
		for(int i=1;i<=n;i++)
			s^=a[i*g]^(i*g-1);
		cout<<s<<'\n';
	}
}