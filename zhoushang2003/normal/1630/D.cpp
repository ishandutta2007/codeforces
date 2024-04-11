#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int t,n,m,a[N],x,c,A,B,g;
signed main()
{
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		A=B=g=0;
		for(int i=1;i<=m;i++)
			cin>>x,g=__gcd(g,x);
		for(int i=1;i<=g;i++)
		{
			c=0,x=1e9;
			for(int j=i;j<=n;j+=g)
				A+=abs(a[j]),B+=abs(a[j]),x=min(x,abs(a[j])),c+=a[j]<0;
			if(c&1)
				A-=2*x;
			else
				B-=2*x;
		}
		cout<<max(A,B)<<'\n';
	}
}