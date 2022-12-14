#include<bits/stdc++.h>
using namespace std;
const int N=4e5,M=19;
int n,m,k,r,x,y,p[N],q[N],s,t,v[N],g[N],d[N],f[N][M],T;
vector<int>a[N];
int F(int x)
{
	if(p[x]==x)
		return x;
	return p[x]=F(p[x]);
}
void D(int x)
{
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f[x][0])
			f[a[x][i]][0]=x,d[a[x][i]]=d[x]+1,D(a[x][i]);
}
int G(int x,int k)
{
	for(int i=M-1;i>=0;i--)
		if((1<<i)&k)
			x=f[x][i];
	return x;
}
int L(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	x=G(x,d[x]-d[y]);
	if(x==y)
		return x;
	for(int i=M-1;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int W(int x,int y)
{
	if(d[x]-d[L(x,y)]>=k)
		return G(x,k);
	return G(y,d[x]+d[y]-2*d[L(x,y)]-k);
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k>>r,m=n-1;
	while(m--&&cin>>x>>y)
		a[++n].push_back(x),a[x].push_back(n),a[n].push_back(y),a[y].push_back(n);
	for(int i=1;i<=n;i++)
		p[i]=i;
	while(r--&&cin>>x)
		q[++t]=x,v[x]=1;
	while(s<t)
	{
		x=q[++s];
		if(g[x]==k)
			continue;
		for(int i=0;i<a[x].size();i++)
		{
			p[F(x)]=F(a[x][i]);
			if(!v[a[x][i]])
				q[++t]=a[x][i],g[a[x][i]]=g[x]+1,v[a[x][i]]=1;
		}
	}
	D(1);
	for(int i=1;i<M;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	cin>>T;
	while(T--&&cin>>x>>y)
		if(d[x]+d[y]-2*d[L(x,y)]<=2*k||F(W(x,y))==F(W(y,x)))
			cout<<"YES"<<'\n';
		else
			cout<<"NO"<<'\n';
	return 0;
}