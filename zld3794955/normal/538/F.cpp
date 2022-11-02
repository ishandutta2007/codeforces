#include<bits/stdc++.h>
using namespace std;
const int N=200020,D=40,L=0,R=1;
struct node
{
	int p,s[2];
}t[N*D]={};
int tot=0;
inline int get(int p,int s1,int s2)
{
	t[++tot]={p,{s1,s2}};
	return tot;
}
int make_tree(int l,int r)
{
	if(l==r)
		return get(0,0,0);
	else
		return get(0,make_tree(l,(l+r)>>1),make_tree((l+r+2)>>1,r));
}
int add(int l,int r,int k,int pos)
{
	if(l==r)
		return get(t[k].p+1,0,0);
	else
	{
		int s1=t[k].s[L],s2=t[k].s[R],mid=(l+r)>>1;
		if(mid>=pos)
			return get(t[s1].p+t[s2].p+1,add(l,mid,s1,pos),s2);
		else
			return get(t[s1].p+t[s2].p+1,s1,add(mid+1,r,s2,pos));
	}
}
int n,q,a[N]={},b[N]={},pos=0,root[N]={};
void init()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),b[i]=a[i];
	sort(b+1,b+n+1);
	root[0]=make_tree(1,n);
	for(int i=1;i<=n;++i)
	{
		a[i]=lower_bound(b+1,b+n+1,a[i])-b;
		root[i]=add(1,n,root[i-1],a[i]);
	}
}
int query(int l,int r,int k1,int k2,int pos)
{
	if(l==r)
		return (pos==l)*(t[k2].p-t[k1].p);
	int mid=(l+r)>>1;
	if(pos<=mid)
		return query(l,mid,t[k1].s[L],t[k2].s[L],pos);
	else
		return query(mid+1,r,t[k1].s[R],t[k2].s[R],pos)+t[t[k2].s[L]].p-t[t[k1].s[L]].p;
}
void work()
{
	for(int k=1;k<n;++k)
	{
		int l=2,r=k+1,p=1,s=0;
		while(l<=n)
		{
			r=min(r,n);
			s+=query(1,n,root[l-1],root[r],a[p]-1);
			l+=k,r+=k,++p;
		}
		cout<<s<<' ';
	}
	cout<<endl;
}
int main()
{	
	init();
	work();
	return 0;
}