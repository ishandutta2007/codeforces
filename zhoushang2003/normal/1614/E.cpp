#include<bits/stdc++.h>
using namespace std;
const int N=4e7,I=1e9,D=1e9+1;
int n,x,m,s[N],u[N],v[N],f[N],c=1,w=1,l,r,A;
void U(int k)
{
	if(!u[k])
		u[k]=++c;
	if(!v[k])
		v[k]=++c;
	s[u[k]]+=s[k],s[v[k]]+=s[k],f[u[k]]+=s[k],f[v[k]]+=s[k],s[k]=0;
}
void C(int &k,int l,int r,int L,int R,int x)
{
	if(L>R)
		return;
	if(!k)
		k=++c;
	if(L<=l&&r<=R)
	{
		s[k]+=x,f[k]+=x;
		return;
	}
	U(k);
	int d=(l+r)/2;
	if(d>=L)
		C(u[k],l,d,L,R,x);
	if(d<R)
		C(v[k],d+1,r,L,R,x);
	f[k]=f[u[k]];
}
int Q(int k,int l,int r,int L)
{
	if(l==r)
		return s[k]+l;
	U(k);
	int A=0,d=(l+r)/2;
	if(d>=L)
		return Q(u[k],l,d,L);
	else
		return Q(v[k],d+1,r,L);
}
int F(int k,int l,int r,int x)
{
	if(l==r)
		return l-(f[k]+l>x);
	U(k);
	int d=(l+r)/2;
	if(f[v[k]]+d+1>x)
		return F(u[k],l,d,x);
	else
		return F(v[k],d+1,r,x);
}
int main()
{
	cin>>n;
	while(n--&&cin>>x>>m)
	{
		C(w,0,I,0,F(1,0,I,x-1),1),C(w,0,I,F(1,0,I,x)+1,I,-1);
		while(m--&&cin>>x)
		{
			(x+=A)%=D,A=Q(1,0,I,x);
			cout<<A<<'\n';
		}
	}
	return 0;
}