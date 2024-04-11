#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
int t,n,a[N];
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		if(a[1]>a[n])
			cout<<"NO"<<'\n';
		else
			cout<<"YES"<<'\n';
	}
	return 0;
}