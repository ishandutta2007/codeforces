#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,a[N],A;
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		A=0;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=2;i<n;i++)
			if(a[i-1]<a[i]&&a[i]>a[i+1])
				a[i+1]=max(a[i],a[i+2]),A++;
		cout<<A<<'\n';
		for(int i=1;i<=n;i++)
			cout<<a[i]<<' ';
		cout<<'\n';
	}
}