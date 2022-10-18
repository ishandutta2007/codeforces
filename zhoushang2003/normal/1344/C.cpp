#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m,x,y,c[N],q[N],s,t,f[N],g[N],A;
vector<int>a[N],b[N];
int main()
{
	cin>>n>>m;
	while(m--&&cin>>x>>y)
		a[x].push_back(y),b[y].push_back(x),c[y]++;
	for(int i=1;i<=n;i++)
		if(!c[i])
			q[++t]=i;
	while(s<t)
	{
		x=q[++s];
		for(int i=0;i<a[x].size();i++)
		{
			c[a[x][i]]--;
			if(!c[a[x][i]])
				q[++t]=a[x][i];
		}
	}
	if(t<n)
	{
		cout<<-1;
		return 0;
	}
	for(int i=1;i<=n;i++)
		f[i]=g[i]=i;
	for(int i=n;i>=1;i--)
		for(int j=0;j<a[q[i]].size();j++)
			f[q[i]]=min(f[q[i]],f[a[q[i]][j]]);
	for(int i=1;i<=n;i++)
		for(int j=0;j<b[q[i]].size();j++)
			g[q[i]]=min(g[q[i]],g[b[q[i]][j]]);
	for(int i=1;i<=n;i++)
		if(f[i]==i&&g[i]==i)
			A++;
	cout<<A<<'\n';
	for(int i=1;i<=n;i++)
		if(f[i]==i&&g[i]==i)
			cout<<'A';
		else
			cout<<'E';
	return 0;
}