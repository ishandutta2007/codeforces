#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,M=17;
int n,x,y,c[N],f[N][M],d[N],m,z;
vector<int>a[N];
void D(int k)
{
	c[k]=1;
	for(int i=0;i<a[k].size();i++)
		if(a[k][i]!=f[k][0])
			f[a[k][i]][0]=k,d[a[k][i]]=d[k]+1,D(a[k][i]),c[k]+=c[a[k][i]];
}
int L(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	for(int i=M-1;i>=0;i--)
		if(d[x]-(1<<i)>=d[y])
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=M-1;i>=0;i--)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
int S(int x,int y)
{
	for(int i=M-1;i>=0;i--)
		if((y>>i)&1)
			x=f[x][i];
	return x;
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].push_back(y),a[y].push_back(x);
	}
	D(1);
	for(int i=1;i<M;i++)
		for(int j=1;j<=n;j++)
			f[j][i]=f[f[j][i-1]][i-1];
	cin>>m;
	while(m--&&cin>>x>>y)
	{
		if((d[x]+d[y])&1)
		{
			cout<<0<<'\n';
			continue;
		}
		z=L(x,y);
		if(d[x]==d[y])
		{
			x=S(x,d[x]-d[z]-1),y=S(y,d[y]-d[z]-1);
			cout<<n-c[x]-c[y]<<'\n';
			continue;
		}
		if(d[x]<d[y])
			swap(x,y);
		x=S(x,(d[x]+d[y]-2*d[z])/2-1);
		cout<<c[f[x][0]]-c[x]<<'\n';
	}
	return 0;
}