#import<bits/stdc++.h>
using namespace std;
#define int long long
#define I 2*k
#define J 2*k+1
#define d (l+r)/2
const int N=1e6;
int n,m,x,y,z,o,u[N],s[N],h[N];
void U(int k)
{
	u[k]=min(u[I],u[J]),s[k]=s[I]+s[J];
}
void V(int k,int l,int r)
{
	if(h[k])
		h[I]=h[J]=h[k],u[I]=u[J]=h[k],s[I]=(d-l+1)*h[k],s[J]=(r-d)*h[k],h[k]=0;
}
void C(int k,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R)
	{
		h[k]=u[k]=x,s[k]=(r-l+1)*x;
		return;
	}
	V(k,l,r);
	if(L<=d)
		C(I,l,d,L,R,x);
	if(R>d)
		C(J,d+1,r,L,R,x);
	U(k);
}
int P(int k,int l,int r,int x)
{
	if(l==r)
		return l+(u[k]>x);
	V(k,l,r);
	return u[I]<x?P(I,l,d,x):P(J,d+1,r,x);
}
int Q(int k,int l,int r,int L,int &x)
{
	if(r<L||x<u[k])
		return 0;
	if(l>=L&&x>=s[k])
	{
		x-=s[k];
		return r-l+1;
	}
	V(k,l,r);
	int A=0;
	if(L<=d)
		A=Q(I,l,d,L,x);
	return A+Q(J,d+1,r,L,x);
}
main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>x,C(1,1,n,i,i,x);
	while(m--&&cin>>o>>x>>y)
		if(o==1)
		{
			z=P(1,1,n,y);
			if(z<=x)
				C(1,1,n,z,x,y);
		}
		else
			cout<<Q(1,1,n,x,y)<<'\n';
}