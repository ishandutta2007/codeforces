#include<bits/stdc++.h>
using namespace std;
const int N=2e6+1,I=1e9;
struct S
{
	int m,n;
};
int n,a[N],x,y,l,r;
S w[N];
void U(int k)
{
	w[k].m=max(w[2*k].m,w[2*k+1].m),w[k].n=min(w[2*k].n,w[2*k+1].n);
}
void F(int k,int l,int r)
{
	if(l==r)
	{
		w[k].m=w[k].n=y;
		return;
	}
	int d=(l+r)/2;
	if(x<=d)
		F(2*k,l,d);
	else
		F(2*k+1,d+1,r);
	U(k);
}
int P(int x,int y,int k,int l,int r)
{
	if(x<=l&&r<=y)
		return w[k].m;
	int d=(l+r)/2,A=0;
	if(x<=d)
		A=max(A,P(x,y,2*k,l,d));
	if(y>d)
		A=max(A,P(x,y,2*k+1,d+1,r));
	return A;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	x=y=a[1];
	for(int i=2;i<=n;i++)
		x=max(x,a[i]),y=min(y,a[i]);
	if(x<=2*y)
	{
		for(int i=1;i<=n;i++)
			cout<<-1<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++)
		x=i,y=a[i],F(1,1,3*n),x+=n,a[x]=a[i],F(1,1,3*n),x+=n,a[x]=a[i],F(1,1,3*n);
	l=1,r=1;
	while(l<=n)
	{
		if(r<l)
			r=l;
		while(2*a[r+1]>=P(l,r,1,1,3*n))
			r++;
		cout<<r-l+1<<" ";
		l++;
	}
	return 0;
}