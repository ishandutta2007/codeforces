#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int t,n,a[N],x,y,k,A;
int main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		x=0,y=2e9;
		for(int i=1;i<n;i++)
		{
			if(a[i]==-1&&a[i+1]!=-1)
				x=max(x,a[i+1]),y=min(y,a[i+1]);
			if(a[i]!=-1&&a[i+1]==-1)
				x=max(x,a[i]),y=min(y,a[i]);
		}
		if(x<y)
		{
			cout<<0<<' '<<0<<'\n';
			continue;
		}
		k=(x+y)/2;
		for(int i=1;i<=n;i++)
			if(a[i]==-1)
				a[i]=k;
		A=0;
		for(int i=1;i<n;i++)
			A=max(A,abs(a[i]-a[i+1]));
		cout<<A<<' '<<k<<'\n';
	}
	return 0;
}