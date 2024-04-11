#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3e5+1;
int n,q,x,a[N],p[N];
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>=1;i--)
		p[a[i]]=i;
	while(q--&&cin>>x)
	{
		cout<<p[x]<<' ';
		for(int i=p[x];i>1;i--)
		{
			swap(a[i],a[i-1]);
			if(p[a[i]]==i-1)
				p[a[i]]++;
		}
		p[x]=1;
	}
	return 0;
}