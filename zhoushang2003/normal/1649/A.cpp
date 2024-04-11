#include<bits/stdc++.h>
using namespace std;
int t,n,a[999],l,r;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		l=1,r=n;
		while(l<r&&a[l+1])
			l++;
		while(l<r&&a[r-1])
			r--;
		cout<<r-l<<'\n';
	}
}