#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1;
bool v[N];
int n,m,q,x,y,f[N],g[N],d[N],t;
vector<int>a[N];
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
void D(int k)
{
	f[k]=x;
	for(int i=0;i<a[k].size();i++)
		if(!f[a[k][i]])
			D(a[k][i]),g[x]=max(g[x],d[k]+d[a[k][i]]+1),d[k]=max(d[k],d[a[k][i]]+1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>q;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=n;i++)
		if(!f[i])
			x=i,D(i);
	while(q--&&cin>>t>>x)
		if(t==1)
			cout<<g[F(x)]<<'\n';
		else
		{
			cin>>y;
			x=F(x),y=F(y);
			if(x!=y)
				f[y]=x,g[x]=max(max(g[x],g[y]),(g[x]+1)/2+(g[y]+1)/2+1);
		}
	return 0;
}