#include<bits/stdc++.h>
using namespace std;
const int M=5e3+1,K=3e6+2;
char A[K];
int k,m,l[M],r[M],L[M],R[M],t,f[K],g[K],q[K],Q[K],T,x,X,c;
string s;
int F(int x)
{
	if(f[x]==x)
		return x;
	return f[x]=F(f[x]);
}
int G(int x)
{
	if(g[x]==x)
		return x;
	return g[x]=G(g[x]);
}
int main()
{
	cin>>s>>k>>m;
	for(int i=1;i<=m;i++)
		cin>>l[i]>>r[i];
	t=k;
	for(int i=m;i>=1;i--)
	{
		L[i]=r[i]+1;
		R[i]=L[i]+r[i]-l[i];
		if(L[i]>t)
		{
			L[i]=R[i]=0;
			continue;
		}
		R[i]=min(R[i],t);
		t-=R[i]-L[i]+1;
	}
	for(int i=1;i<=k+1;i++)
		f[i]=g[i]=i;
	for(int i=m;i>=1;i--)
	{
		if(L[i]==0)
			continue;
		x=l[i],X=L[i];
		for(int j=i+1;j<=m;j++)
		{
			if(r[j]<x)
				x+=R[j]-L[j]+1;
			if(r[j]<X)
				X+=R[j]-L[j]+1;
		}
		t=T=0;
		for(int j=1;j<=min(r[i]-l[i]+1,2*(R[i]-L[i]+1));j++)
			x=F(x),q[++t]=x,x++;
		for(int j=2;j<=t;j+=2)
			Q[++T]=q[j];
		for(int j=1;j<=t;j+=2)
			Q[++T]=q[j];
		for(int j=1;j<=(R[i]-L[i]+1);j++)
			X=F(X),g[X]=Q[j],f[X]=X+1,X++;
	}
	for(int i=1;i<=k;i++)
		if(G(i)==i)
			A[i]=s[c++];
	for(int i=1;i<=k;i++)
		cout<<A[G(i)];
	return 0;
}