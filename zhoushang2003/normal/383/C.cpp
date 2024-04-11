#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=524288;
int n,m,h[N],x,y,p[N],d[N],c[N],t,L,R,v[M];
vector<int>a[N];
void D(int k,int f)
{
	p[k]=++x,c[k]=1;
	for(int i=0;i<a[k].size();i++)
		if(a[k][i]!=f)
			d[a[k][i]]=d[k]+1,D(a[k][i],k),c[k]+=c[a[k][i]];
}
void D(int k)
{
	v[2*k]+=v[k];
	v[2*k+1]+=v[k];
	v[k]=0;
}
void C(int k,int l,int r)
{
	if(L<=l&&r<=R)
	{
		v[k]+=x;
		return;
	}
	D(k);
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d);
	if(R>d)
		C(2*k+1,d+1,r);
}
int Q(int k,int l,int r)
{
	if(l==r)
		return v[k];
	D(k);
	int d=(l+r)/2;
	if(p[x]<=d)
		return Q(2*k,l,d);
	return Q(2*k+1,d+1,r);
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].push_back(y),a[y].push_back(x);
	}
	x=0,D(1,0);
	while(m--&&cin>>t>>x)
		if(t==1&&cin>>y)
		{
			if(d[x]&1)
				y=-y;
			L=p[x],R=L+c[x]-1,x=y,C(1,1,n);
		}
		else if(d[x]&1)
			cout<<h[x]-Q(1,1,n)<<'\n';
		else
			cout<<h[x]+Q(1,1,n)<<'\n';
	return 0;
}