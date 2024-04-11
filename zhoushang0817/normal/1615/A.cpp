#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,a[N],s,x;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		s=0;
		for(int i=1;i<=n;i++)
			cin>>x,s+=x;
		if(s%n==0)
			cout<<"0\n";
		else
			cout<<"1\n";
	}
}