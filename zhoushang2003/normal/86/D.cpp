#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1,M=1e6+1,K=448;
struct S
{
	int l,r,i;
};
long long n,m,a[N],l,r,p,c[M],A[N];
S w[N];
bool C(S x,S y)
{
	if((x.l-1)/K!=(y.l-1)/K)
		return (x.l-1)/K<(y.l-1)/K;
	return x.r<y.r;
}
void R(int k)
{
	p+=(2*c[a[k]]+1)*a[k],c[a[k]]++;
}
void W(int k)
{
	c[a[k]]--,p-=(2*c[a[k]]+1)*a[k];
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>w[i].l>>w[i].r,w[i].i=i;
	sort(w+1,w+m+1,C),l=r=1,R(1);
	for(int i=1;i<=m;i++)
	{
		while(r<w[i].r)
			R(++r);
		while(w[i].l<l)
			R(--l);
		while(w[i].r<r)
			W(r--);
		while(l<w[i].l)
			W(l++);
		A[w[i].i]=p;
	}
	for(int i=1;i<=m;i++)
		cout<<A[i]<<'\n';
	return 0;
}