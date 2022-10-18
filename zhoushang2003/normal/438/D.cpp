#include<bits/stdc++.h>
using namespace std;
const int N=262144;
struct S
{
	long long m,s;
};
int n,m,t,x,y,z;
S w[N];
void U(int k)
{
	w[k].m=max(w[2*k].m,w[2*k+1].m),w[k].s=w[2*k].s+w[2*k+1].s;
}
void F(int k,int l,int r)
{
	if(l==r)
	{
		w[k].m=w[k].s=y;
		return;
	}
	int d=(l+r)/2;
	if(x<=d)
		F(2*k,l,d);
	else
		F(2*k+1,d+1,r);
	U(k);
}
void C(int k,int l,int r)
{
	if(w[k].m<z)
		return;
	if(l==r)
	{
		w[k].m%=z,w[k].s=w[k].m;
		return;
	}
	int d=(l+r)/2;
	if(x<=d)
		C(2*k,l,d);
	if(y>d)
		C(2*k+1,d+1,r);
	U(k);
}
long long Q(int k,int l,int r)
{
	if(x<=l&&r<=y)
		return w[k].s;
	int d=(l+r)/2;
	long long A=0;
	if(x<=d)
		A+=Q(2*k,l,d);
	if(y>d)
		A+=Q(2*k+1,d+1,r);
	return A;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>y;
		x=i,F(1,1,n); 
	}
	while(m--&&cin>>t>>x>>y)
		if(t==1)
			cout<<Q(1,1,n)<<'\n';
		else if(t==2&&cin>>z)
			C(1,1,n);
		else
			F(1,1,n);
	return 0;
}