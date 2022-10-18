#include<bits/stdc++.h>
using namespace std;
#define int long long
struct S
{
	int l,k,i;
};
const int N=1e6+1;
int t,n,m,f[N],c[N],s[N],g[N],A[N],l,r,x,y,z;
vector<int>a[N],p[N];
vector<S>q[N];
void D(int x,int F)
{
	s[++c[f[x]]]++,p[c[f[x]]].push_back(f[x]);
	for(int i=0;i<q[x].size();i++)
	{
		q[x][i].k+=n-s[q[x][i].l];
		if(q[x][i].k>n)
		{
			A[q[x][i].i]=-1;
			continue;
		}
		l=0,r=n;
		while(l<r)
			if(n-s[(l+r+1)/2]>=q[x][i].k)
				r=(l+r-1)/2;
			else
				l=(l+r+1)/2;
		while(c[p[l][g[l]]]!=l)
			g[l]++;
		A[q[x][i].i]=p[l][g[l]];
	}
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=F)
			D(a[x][i],x);
	s[c[f[x]]--]--,p[c[f[x]]].push_back(f[x]);
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			cin>>f[i],a[i].clear(),p[i].clear(),q[i].clear(),c[i]=s[i]=g[i]=0;
		for(int i=2;i<=n;i++)
			cin>>x,a[i].push_back(x),a[x].push_back(i);
		for(int i=1;i<=m;i++)
			cin>>x>>y>>z,q[x].push_back((S){y,z,i});
		s[0]=n,D(1,0);
		for(int i=1;i<=m;i++)
			cout<<A[i]<<' ';
		cout<<'\n';
	}
}