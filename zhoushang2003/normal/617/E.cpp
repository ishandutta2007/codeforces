#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,M=(1<<20),K=317;
struct S
{
	int l,r,i;
};
long long n,m,k,a[N],s[N],b[N],l,r,c[M],d[M],p,A[N];
S w[N];
bool C(S x,S y)
{
	if((x.l-1)/K!=(y.l-1)/K)
		return (x.l-1)/K<(y.l-1)/K;
	return x.r<y.r;
}
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]^a[i],a[i]=s[i]^k,b[i]=s[i-1];
	for(int i=1;i<=m;i++)
		cin>>w[i].l>>w[i].r,w[i].i=i;
	sort(w+1,w+m+1,C),l=r=1,c[b[1]]++,d[a[1]]++,p+=c[a[1]];
	for(int i=1;i<=m;i++)
	{
		while(r<w[i].r)
			c[b[++r]]++,d[a[r]]++,p+=c[a[r]];
		while(w[i].l<l)
			c[b[--l]]++,d[a[l]]++,p+=d[b[l]];
		while(w[i].r<r)
			p-=c[a[r]],d[a[r]]--,c[b[r--]]--;
		while(l<w[i].l)
			p-=d[b[l]],d[a[l]]--,c[b[l++]]--;
		A[w[i].i]=p;
	}
	for(int i=1;i<=m;i++)
		cout<<A[i]<<'\n';
	return 0;
}