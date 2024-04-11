#include<bits/stdc++.h>
using namespace std;
const long long N=3e5+1,M=1048576,I=1e18;
struct S
{
	int l,r;
	long long m,v;
};
long long n,m,k,t,L,R,A=-I,x,a[N],p[N],q[N];
S w[M];
long long B(int k,int l,int r)
{
	w[k].l=l,w[k].r=r;
	if(l==r)
		return w[k].m=a[l];
	return w[k].m=B(2*k,l,(l+r)/2)+B(2*k+1,(l+r)/2+1,r);
}
void D(int k)
{
	w[2*k].v+=w[k].v;
	w[2*k].m+=w[k].v;
	w[2*k+1].v+=w[k].v;
	w[2*k+1].m+=w[k].v;
	w[k].v=0;
}
void C(int k,int l,int r)
{
	if(L<=l&&r<=R)
	{
		w[k].m+=x;
		w[k].v+=x;
		return;
	}
	D(k);
	int d=(l+r)/2;
	if(L<=d)
		C(2*k,l,d);
	if(R>d)
		C(2*k+1,d+1,r);
	w[k].m=max(w[2*k].m,w[2*k+1].m);
}
long long Q(int k,int l,int r)
{
	if(L<=l&&r<=R)
		return w[k].m;
	D(k);
	long long A=-I;
	int d=(l+r)/2;
	if(L<=d)
		A=Q(2*k,l,d);
	if(R>d)
		A=max(A,Q(2*k+1,d+1,r));
	return A;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>q[i];
	B(1,1,n);
	for(int i=1;i<=n;i++)
		a[p[i]]=i;
	cout<<n<<' ';
	t=n,L=1,R=a[t],x=1,C(1,1,n);
	for(int i=1;i<n;i++)
	{
		L=1,R=q[i],x=-1,C(1,1,n);
		while(true)
		{
			L=1,R=n;
			if(Q(1,1,n)>0)
				break;
			L=1,R=a[--t],x=1,C(1,1,n);
		}
		cout<<t<<' ';
	}
	return 0;
}