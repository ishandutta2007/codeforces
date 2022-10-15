#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int n,k,q;
int a[maxn];
vector<int>p[maxn];
int getp(int pos)
{
	int it=lower_bound(p[a[pos]].begin(),p[a[pos]].end(),pos)-p[a[pos]].begin();
	if(it>=k)return p[a[pos]][it-k]+1;
	return 1;
}
struct per_seg
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int ls,rs,tag;}t[maxn*50];int rt[maxn],cnt;
	int clone(int u){t[++cnt]=t[u];return cnt;}
	int change(int u,int nl,int nr,int l=1,int r=n)
	{
		u=clone(u);
		if(l>=nl&&r<=nr){t[u].tag++;return u;}
		int mid=(l+r)>>1;
		if(mid>=nl)L(u)=change(L(u),nl,nr,l,mid);
		if(mid+1<=nr)R(u)=change(R(u),nl,nr,mid+1,r);
		return u;
	}
	int query(int u,int p,int l=1,int r=n)
	{
		if(l==r)return t[u].tag;
		int mid=(l+r)>>1;
		if(mid>=p)return query(L(u),p,l,mid)+t[u].tag;
		else return query(R(u),p,mid+1,r)+t[u].tag;
	}
}tr;
int main()
{
	n=read();k=read();
	generate_n(a+1,n,read);
	for(int i=1;i<=n;i++)p[a[i]].push_back(i);
	for(int i=1;i<=n;i++)tr.rt[i]=tr.change(tr.rt[i-1],getp(i),i);
	q=read();int lans=0;
	while(q--)
	{
		int x=(read()+lans)%n+1,y=(read()+lans)%n+1;
		if(x>y)swap(x,y);
		printf("%d\n",lans=tr.query(tr.rt[y],x));
	}
	return 0;
}