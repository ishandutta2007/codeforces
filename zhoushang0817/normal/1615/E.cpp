#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6;
int n,k,x,y,o=1e18,p[N],z[N],s,f[N],d[N],v[N],u[N],I[N],c,A,q[N];
vector<int>a[N];
void W(int k)
{
	v[2*k]+=v[k],v[2*k+1]+=v[k],u[2*k]+=v[k],u[2*k+1]+=v[k],v[k]=0;
}
void U(int k)
{
	if(u[2*k]>u[2*k+1])
		u[k]=u[2*k],I[k]=I[2*k];
	else
		u[k]=u[2*k+1],I[k]=I[2*k+1];
}
void C(int k,int l,int r,int L,int R,int x)
{
	if(l==r)
		I[k]=l;
	if(L<=l&&r<=R)
	{
		v[k]+=x,u[k]+=x;
		return;
	}
	W(k);
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d,L,R,x);
	if(R>d)
		C(2*k+1,d+1,r,L,R,x);
	U(k);
}
int Q(int k,int l,int r,int L)
{
	if(l==r)
		return u[k];
	W(k);
	int d=(l+r)/2;
	if(L<=d)
		return Q(2*k,l,d,L);
	else
		return Q(2*k+1,d+1,r,L);
	U(k);
}
void D(int x)
{
	p[x]=++c,q[c]=x,z[x]=1;
	for(int i=0;i<a[x].size();i++)
		if(a[x][i]!=f[x])
			f[a[x][i]]=x,d[a[x][i]]=d[x]+1,D(a[x][i]),z[x]+=z[a[x][i]];
	if(z[x]==1)
		s++,C(1,1,n,p[x],p[x],d[x]);
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
	d[1]=1,D(1);
	if(k>=s)
	{
		s=min(k,n/2);
		cout<<s*(n-s);
		return 0;
	}
	for(int i=1;i<=k;i++)
	{
		x=q[I[1]],y=I[1],A--;
		while(Q(1,1,n,y))
			C(1,1,n,p[x],p[x]+z[x]-1,-1),x=f[x],A++;
	}
	for(int i=0;i<=n-A-k;i++)
		o=min(o,(n-k-i)*(k-i));
	cout<<o;
}