#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1.2e7,M=3e5,D=998244353,I=1e9;
int n,a[M],s[N],u[N],v[N],f[N],g[N],c,r,x;
void U(int k,int l,int r)
{
	if(!u[k])
		u[k]=++c,g[k]=1;
	if(!v[k])
		v[k]=++c,g[k]=1;
	int d=(l+r)/2;
	(s[u[k]]*=g[k])%=D,(s[v[k]]*=g[k])%=D,(g[u[k]]*=g[k])%=D,(g[v[k]]*=g[k])%=D,(f[u[k]]*=g[k])%=D,(f[v[k]]*=g[k])%=D,g[k]=1,(s[u[k]]+=f[k]*(d-l+1))%=D,(s[v[k]]*=f[k]*(r-d))%=D,(f[u[k]]+=f[k])%=D,(f[v[k]]+=f[k])%=D,f[k]=0;
}
void C(int &k,int l,int r,int L,int R,int x,int t)
{
	if(!k)
		k=++c,g[k]=1;
	if(L<=l&&r<=R)
	{
		if(t==1)
		{
			(s[k]+=x*(r-l+1))%=D;
			if(l!=r)
				U(k,l,r);
			(f[k]+=x)%=D;
		}
		else
		{
			(s[k]*=x)%=D;
			if(l!=r)
				U(k,l,r);
			(g[k]*=x)%=D;
		}
		return;
	}
	U(k,l,r);
	int d=(l+r)/2;
	if(d>=L)
		C(u[k],l,d,L,R,x,t);
	if(d<R)
		C(v[k],d+1,r,L,R,x,t);
	s[k]=(s[u[k]]+s[v[k]])%D;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	C(r,1,I,1,a[1],1,1);
	for(int i=2;i<=n;i++)
		x=s[1],C(r,1,I,1,a[i],-1,2),C(r,1,I,1,a[i],x,1),C(r,1,I,a[i]+1,I,0,2);
	cout<<(s[1]+D)%D;
}