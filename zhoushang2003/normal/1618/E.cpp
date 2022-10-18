#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,b[N],a[N],s,v;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		s=v=0;
		for(int i=1;i<=n;i++)
			cin>>b[i],s+=b[i];
		if(s%(n*(n+1)/2)!=0)
		{
			cout<<"NO\n";
			continue;
		}
		s/=n*(n+1)/2;
		for(int i=1;i<=n;i++)
			a[i%n+1]=b[i%n+1]-b[i];
		for(int i=1;i<=n;i++)
			if(s<=a[i]||(s-a[i])%n!=0)
				v=1;
		if(v)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
			cout<<(s-a[i])/n<<' ';
		cout<<'\n';
	}
	return 0;
}