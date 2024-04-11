#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,x,c,a[N],A;
signed main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		x=c=A=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			while(a[i]%2==0)
				a[i]/=2,c++;
			A+=a[i],x=max(x,a[i]);
		}
		cout<<A-x+(x<<c)<<'\n';
	}
}