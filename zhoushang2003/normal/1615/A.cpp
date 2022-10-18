#include<bits/stdc++.h>
using namespace std;
#define int long long
int t,n,x,s;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>x,s+=x;
		cout<<(s%n==0?"0\n":"1\n"),s=0;
	}
}