#include<iostream>
using namespace std;
const int N=2e5+1,M=524288;
struct S
{
	long long v,x;
};
int n,m,t,L,R;
long long a[N],x,y;
S w[M];
long long B(int k,int l,int r)
{
	if(l==r)
		return w[k].x=a[l];
	B(2*k,l,(l+r)/2),B(2*k+1,(l+r)/2+1,r);
}
void D(int k)
{
	w[2*k].v=max(w[2*k].v,w[k].v);
	w[2*k+1].v=max(w[2*k+1].v,w[k].v);
	w[k].v=0;
}
void C(int k,int l,int r)
{
	if(L<=l&&r<=R)
	{
		w[k].v=max(w[k].v,x);
		return;
	}
	D(k);
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d);
	if(R>d)
		C(2*k+1,d+1,r);
}
void W(int k,int l,int r)
{
	if(l==r)
	{
		w[k].v=0,w[k].x=y;
		return;
	}
	D(k);
	int d=(l+r)/2;
	if(L<=d)
		W(2*k,l,d);
	if(R>d)
		W(2*k+1,d+1,r);
}
long long Q(int k,int l,int r)
{
	if(L<=l&&r<=R)
		return max(w[k].v,w[k].x);
	D(k);
	int d=(l+r)/2;
	if(L<=d)
		return Q(2*k,l,d);
	return Q(2*k+1,d+1,r);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	B(1,1,n);
	while(m--&&cin>>t>>x)
		if(t==1&&cin>>y)
			L=x,R=x,W(1,1,n);
		else
			L=1,R=n,C(1,1,n);
	for(int i=1;i<=n;i++)
	{
		L=i,R=i;
		cout<<Q(1,1,n)<<" ";
	}
	return 0;
}