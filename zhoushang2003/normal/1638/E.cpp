#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e6;
int n,m,s[N],c[N],v[N],u[N],x,y,z;
string o;
void D(int k)
{
	v[2*k]+=v[k],v[2*k+1]+=v[k],v[k]=0;
	if(u[k])
		c[2*k]=c[2*k+1]=c[k],u[2*k]=u[2*k+1]=1;
}
void U(int k)
{
	c[k]=c[2*k],u[k]=u[2*k]&&u[2*k+1]&&c[2*k]==c[2*k+1];
}
void C(int k,int l,int r,int L,int R,int x)
{
	if(L<=l&&r<=R&&u[k])
	{
		v[k]+=s[c[k]]-s[x],c[k]=x;
		return;
	}
	D(k);
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d,L,R,x);
	if(R>d)
		C(2*k+1,d+1,r,L,R,x); 
	U(k);
}
int Q(int k,int l,int r,int x)
{
	if(l==r)
		return v[k]+s[c[k]];
	D(k);
	int d=(l+r)/2;
	return x<=d?Q(2*k,l,d,x):Q(2*k+1,d+1,r,x); 
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n>>m,u[1]=c[1]=1;
	while(m--&&cin>>o>>x)
		if(o[0]=='C'&&cin>>y>>z)
			C(1,1,n,x,y,z);
		else if(o[0]=='A'&&cin>>y)
			s[x]+=y;
		else
			cout<<Q(1,1,n,x)<<'\n';
}