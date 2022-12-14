#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
bool v;
int t,n,x,a[N],p;
int main()
{
	cin>>t;
	while(t--&&cin>>n>>x)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		v=false;
		for(int i=1;i<=n;i++)
			if(a[i]==x)
				v=true;
		if(v)
		{
			cout<<1<<'\n';
			continue;
		}
		p=0;
		for(int i=1;i<=n;i++)
			p=max(p,a[i]);
		cout<<max(2,(x-1)/p+1)<<'\n';
	}
	return 0;
}