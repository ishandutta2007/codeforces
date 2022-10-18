#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6,I=1e9;
int t,n,m,x,y,b[N],v[N],l[N],d[N],p,A;
vector<int>a[N];
void D(int x,int f)
{
	if(b[x])
		p=min(p,(d[x]+1)/2);
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
			d[a[x][i]]=d[x]+1,l[x]=0,D(a[x][i],x);
	if(d[x]==p)
		v[x]=1,p=I;
}
void S(int x,int f)
{
	if(l[x])
		A=-I;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f)
		{
			if(v[a[x][i]])
			{
				A++;
				continue;
			}
			S(a[x][i],x);
		}
}
signed main()
{
	cin>>t;
	while(t--&&cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			a[i].clear(),b[i]=v[i]=0,l[i]=1;
		while(m--&&cin>>x)
			b[x]=1;
		for(int i=1;i<n;i++)
			cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
		p=I,D(1,0),A=0,S(1,0);
		if(A<0)
			cout<<-1<<'\n';
		else
			cout<<A<<'\n';
	}
	return 0;
}