#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1,K=317;
struct S
{
	int l,r,i;
};
long long n,h[N],x,y,p[N],C,c[N],f[N],l,r,s[N],M,A[N];
S w[N];
vector<int>a[N];
bool E(S x,S y)
{
	if((x.l-1)/K!=(y.l-1)/K)
		return (x.l-1)/K<(y.l-1)/K;
	return x.r<y.r;
}
void D(int k,int f)
{
	p[k]=++C,c[k]=1;
	for(int i=0;i<a[k].size();i++)
		if(a[k][i]!=f)
			D(a[k][i],k),c[k]+=c[a[k][i]];
}
void R(int k)
{
	s[f[c[k]]]-=c[k],f[c[k]]++,M=max(M,f[c[k]]),s[f[c[k]]]+=c[k];
}
void W(int k)
{
	s[f[c[k]]]-=c[k];
	if(f[c[k]]==M&&!s[f[c[k]]])
		M--;
	f[c[k]]--,s[f[c[k]]]+=c[k];
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].push_back(y),a[y].push_back(x);
	}
	D(1,0);
	for(int i=1;i<=n;i++)
		w[i].l=p[i],w[i].r=p[i]+c[i]-1,w[i].i=i;
	sort(w+1,w+n+1,E);
	for(int i=1;i<=n;i++)
		c[p[i]]=h[i];
	l=r=1,R(1);
	for(int i=1;i<=n;i++)
	{
		while(l>w[i].l)
			R(--l);
		while(r<w[i].r)
			R(++r);
		while(l<w[i].l)
			W(l++);
		while(r>w[i].r)
			W(r--);
		A[w[i].i]=s[M];
	}
	for(int i=1;i<=n;i++)
		cout<<A[i]<<" ";
	return 0;
}