#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
char c[N];
int n,m,f[N],o[N],u[N],v[N],b[N],z[N],q[N],t,x,A[N],C;
vector<int>a[N];
int F(int x)
{
	return f[x]==x?x:f[x]=F(f[x]);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
		cin>>o[i]>>u[i]>>v[i],f[F(u[i])]=F(v[i]+n),f[F(u[i]+n)]=F(v[i]);
	for(int i=1;i<=n;i++)
		if(b[F(i)])
			c[i]='L';
		else
			c[i]='R',b[F(i+n)]=1;
	for(int i=1;i<=m;i++)
		if(c[u[i]]==c[v[i]])
			puts("NO"),exit(0);
		else if((o[i]==1)^(c[u[i]]=='L'))
			a[v[i]].push_back(u[i]),z[u[i]]++;
		else
			a[u[i]].push_back(v[i]),z[v[i]]++;
	for(int i=1;i<=n;i++)
		if(!z[i])
			q[++t]=i,A[i]=++C;
	while(t)
	{
		x=q[t--];
		for(int i=0;i<a[x].size();i++)
			if(!--z[a[x][i]])
				q[++t]=a[x][i],A[a[x][i]]=++C;
	}
	if(C!=n)
		puts("NO"),exit(0);
	puts("YES");
	for(int i=1;i<=n;i++)
		cout<<c[i]<<' '<<A[i]<<'\n';
}