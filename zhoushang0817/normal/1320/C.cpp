#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+1,M=524288,I=1e18;
struct S
{
	int l,r;
	long long m,v;
};
struct T
{
	int x,y,z;
};
long long n,m,k,t,L,R,A=-I,x,a[N];
pair<int,int>p[N],q[N];
S w[M];
T r[N];
bool E(T x,T y)
{
	return x.x<y.x;
}
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
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=1;i<=m;i++)
		cin>>q[i].first>>q[i].second;
	B(1,1,m);
	for(int i=1;i<=k;i++)
		cin>>r[i].x>>r[i].y>>r[i].z;
	sort(p+1,p+n+1),sort(q+1,q+m+1),sort(r+1,r+k+1,E),t=1;
	for(int i=1;i<=m;i++)
		L=R=i,x=-q[i].second,C(1,1,m);
	for(int i=1;i<=n;i++)
	{
		while(t<=k&&r[t].x<p[i].first)
		{
			L=1,R=m;
			while(L<R)
				if(q[(L+R)/2].first>r[t].y)
					R=(L+R)/2;
				else
					L=(L+R)/2+1;
			if(q[L].first>r[t].y)
				R=m,x=r[t].z,C(1,1,m);
			t++;
		}
		L=1,R=m,A=max(A,Q(1,1,m)-p[i].second);
	}
	cout<<A;
	return 0;
}