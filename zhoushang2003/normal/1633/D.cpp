#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1,M=2e3;
int g[M],n,k,a[N],x,f[N];
main()
{
	for(int i=2;i<M;i++)
		g[i]=N;
	for(int i=1;i<M;i++)
		for(int j=1;j<M;j++)
			if(i+i/j<M)
				g[i+i/j]=min(g[i+i/j],g[i]+1);
	for(cin>>n;cin>>n>>k;)
	{
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			cin>>x;
			for(int j=N-1;j>=g[a[i]];j--)
				f[j]=max(f[j],f[j-g[a[i]]]+x);
		}
		cout<<f[k]<<'\n';
	}
}