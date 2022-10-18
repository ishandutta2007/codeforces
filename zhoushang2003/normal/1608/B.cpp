#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6;
int t,n,x,y,a[N];
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>x>>y)
	{
		if(abs(x-y)>1||x+y>n-2)
		{
			cout<<-1<<'\n';
			continue;
		}
		for(int i=1;i<=n;i+=2)
			a[i]=i/2+1;
		for(int i=2;i<=n;i+=2)
			a[i]=n-i/2+1;
		if(x<y)
			for(int i=1;i<=n;i++)
				a[i]=n-a[i]+1;
		if(x>y)
			for(int i=x+y+1;i<=n;i++)
				a[i]=-a[i];
		sort(a+x+y+2,a+n+1);
		for(int i=1;i<=n;i++)
			cout<<abs(a[i])<<' ';
		cout<<'\n';
	}
}