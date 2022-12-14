#include<bits/stdc++.h>
using namespace std;
const int N=2e5+2,I=1e9;
bool v[N];
int n,m,k,p[N],x,y,X,f[N],g[N],F[N],G[N],A;
vector<int>a[N];
priority_queue<pair<int,int> >q;
bool C(int x,int y)
{
	return f[x]-g[x]<f[y]-g[y];
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	while(m--&&cin>>x>>y)
		a[x].push_back(y),a[y].push_back(x);
	for(int i=1;i<=n;i++)
		f[i]=g[i]=I;
	f[1]=0,q.push(make_pair(0,1));
	while(!q.empty())
	{
		X=q.top().second,q.pop();
		if(v[X])
			continue;
		v[X]=true;
		for(int i=0;i<a[X].size();i++)
			if(f[X]+1<f[a[X][i]])
				f[a[X][i]]=f[X]+1,q.push(make_pair(-f[a[X][i]],a[X][i]));
	}
	for(int i=1;i<=n;i++)
		v[i]=false;
	g[n]=0,q.push(make_pair(0,n));
	while(!q.empty())
	{
		X=q.top().second,q.pop();
		if(v[X])
			continue;
		v[X]=true;
		for(int i=0;i<a[X].size();i++)
			if(g[X]+1<g[a[X][i]])
				g[a[X][i]]=g[X]+1,q.push(make_pair(-g[a[X][i]],a[X][i]));
	}
	sort(p+1,p+k+1,C);
	for(int i=1;i<=k;i++)
		F[i]=max(F[i-1],f[p[i]]);
	for(int i=k;i>=1;i--)
		G[i]=max(G[i+1],g[p[i]]);
	for(int i=1;i<k;i++)
		A=max(A,F[i]+G[i+1]+1);
	cout<<min(A,f[n]);
	return 0;
}