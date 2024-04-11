#include<bits/stdc++.h>
using namespace std;
const int N=262144,M=27;
struct S
{
	int v,c[M];
};
int n,m,l,r,t,L,R,z,c[M];
S w[N];
string s;
void B(int k,int l,int r)
{
	if(l==r)
	{
		w[k].c[s[l-1]-'a'+1]=1;
		return;
	}
	int d=(l+r)/2;
	B(2*k,l,d),B(2*k+1,d+1,r);
	for(int i=1;i<M;i++)
		w[k].c[i]=w[2*k].c[i]+w[2*k+1].c[i];
}
void D(int k,int l,int r)
{
	if(w[k].v!=0)
	{
		w[2*k].v=w[2*k+1].v=w[k].v;
		for(int i=1;i<M;i++)
			w[2*k].c[i]=w[2*k+1].c[i]=0;
		w[2*k].c[w[k].v]=(r-l+2)/2,w[2*k+1].c[w[k].v]=(r-l+1)/2;
		w[k].v=0;
	}
}
void U(int k)
{
	for(int i=1;i<M;i++)
		w[k].c[i]=w[2*k].c[i]+w[2*k+1].c[i];
}
void C(int k,int l,int r)
{
	if(L<=l&&r<=R)
	{
		w[k].v=z;
		for(int i=1;i<M;i++)
			w[k].c[i]=0;
		w[k].c[z]=r-l+1;
		return;
	}
	D(k,l,r);
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d);
	if(R>d)
		C(2*k+1,d+1,r); 
	U(k);
}
int Q(int k,int l,int r)
{
	if(L<=l&&r<=R)
		return w[k].c[z];
	D(k,l,r);
	int d=(l+r)/2,A=0;
	if(L<=d)
		A+=Q(2*k,l,d);
	if(R>d)
		A+=Q(2*k+1,d+1,r);
	return A;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	B(1,1,n);
	while(m--&&cin>>l>>r>>t)
	{
		for(int i=1;i<M;i++)
			L=l,R=r,z=i,c[i]=Q(1,1,n);
		if(t==1)
		{
			for(int i=1;i<M;i++)
				if(c[i])
					L=l,R=l+c[i]-1,z=i,C(1,1,n),l=R+1;
			continue;
		}
		for(int i=M-1;i>=1;i--)
			if(c[i])
				L=l,R=l+c[i]-1,z=i,C(1,1,n),l=R+1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<M;j++)
		{
			L=R=i,z=j;
			if(Q(1,1,n))
				cout<<(char)(j+'a'-1);
		}
	return 0;
}