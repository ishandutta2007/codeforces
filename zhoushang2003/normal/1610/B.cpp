#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],A,B,l,r;
int C(int x)
{
	l=1,r=n;
	while(l<r)
	{
		while(l<n&&a[l]==x)
			l++;
		while(r>1&&a[r]==x)
			r--;
		if(l>r)
			return 1;
		if(a[l]!=a[r])
			return 0;
		l++,r--;
	}
	return 1;
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		l=1,r=n,A=B=0;
		while(l<r)
			if(a[l]!=a[r])
			{
				A=a[l],B=a[r];
				break;
			}
			else
				l++,r--;
		if(C(A)||C(B))
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}