#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],b[N],p,q;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		p=q=0;
		for(int i=1;i<=n;i++)
			cin>>a[i],p=max(p,a[i]);
		for(int i=1;i<=n;i++)
			cin>>b[i],p=max(p,b[i]),q=max(q,min(a[i],b[i]));
		cout<<p*q<<'\n';
	}
}