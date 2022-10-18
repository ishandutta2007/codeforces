#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int t,n,x,f[N],g[N],w[N],A;
vector<int>a[N];
void D(int x,int f)
{
	w[x]=g[x]-g[f],A=min(A,w[x]);
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			D(a[x][i],x);
}
int main()
{
	cin>>t;
	while(t--&&cin>>n)
	{
		for(int i=1;i<=n;i++)
			a[i].clear();
		for(int i=1;i<=n;i++)
			cin>>x,a[i].push_back(x),a[x].push_back(i);
		for(int i=1;i<=n;i++)
			cin>>f[i],g[f[i]]=i;
		w[f[1]]=A=0,D(f[1],f[1]);
		if(A<0)
			cout<<-1<<'\n';
		else
		{
			for(int i=1;i<=n;i++)
				cout<<w[i]<<' ';
			cout<<'\n';
		}
	}
	return 0;
}