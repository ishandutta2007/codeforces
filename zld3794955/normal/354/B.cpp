#include<bits/stdc++.h>
using namespace std;
const int N=22,S=1<<20,C=26,Inf=1<<30;
int n,a[N+N][C]={};
unordered_map<int,int> f[N+N],g[N+N];
char ch[N][N]={};
void init()
{
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>(ch[i]+1);
	for(int i=1;i<=n+n-1;++i)
		for(int x=1;x<=i;++x)
		{
			int y=i-x+1;
			if(n<x || y<=0 || n<y)
				continue;
			a[i][ch[x][y]-'a']|=1<<x;
		}
}
int calc(int d,int s,int t)
{
	if(d==n+n)
		return 0;
	if(t)
	{
		if(g[d].count(s))
			return g[d][s];
		g[d][s]=Inf;
		for(int c=0;c<26;++c)
		{
			int v=c==0 ? 1 : c==1 ? -1 : 0;
			int ns=(s&a[d][c]) | ((s<<1)&a[d][c]);
			if(ns)
				g[d][s]=min(calc(d+1,ns,!t)+v,g[d][s]);
		}
		return g[d][s];
	}
	else
	{
		if(f[d].count(s))
			return f[d][s];
		f[d][s]=-Inf;
		for(int c=0;c<26;++c)
		{
			int v=c==0 ? 1 : c==1 ? -1 : 0;
			int ns=(s&a[d][c]) | ((s<<1)&a[d][c]);
			if(ns)
				f[d][s]=max(calc(d+1,ns,!t)+v,f[d][s]);
		}
		return f[d][s];
	}
}
void work()
{
	calc(1,2,0);
	puts(f[1][2]>0 ? "FIRST" : f[1][2]==0 ? "DRAW" : "SECOND");
}
int main()
{	
	init();
	work();
	return 0;
}