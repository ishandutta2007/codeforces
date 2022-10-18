#include<bits/stdc++.h>
using namespace std;
const int N=101,M=2901;
vector<int>a[N],b[N],g[M];
int n,m,x,y,c,v[M],p[M],A;
bool D(int k)
{
	v[k]=true;
	for(int i=0;i<g[k].size();i++)
		if(!p[g[k][i]]||(!v[p[g[k][i]]]&&D(p[g[k][i]])))
		{
			p[g[k][i]]=k;
			return true;
		}
	return false;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=2;j*j<=x;j++)
			while(x%j==0)
				a[i].push_back(j),b[i].push_back(++c),x/=j;
		if(x>1)
			a[i].push_back(x),b[i].push_back(++c);
	}
	while(m--&&cin>>x>>y)
	{
		if(x%2==0)
			swap(x,y);
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++)
				if(a[x][i]==a[y][j])
					g[b[x][i]].push_back(b[y][j]);
	}
	for(int i=1;i<=c;i++)
	{
		memset(v,false,sizeof(v));
		if(D(i))
			A++;
	}
	cout<<A;
	return 0;
}