#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=4e4+1e3+7;

int cnt;

struct T{
	int ls,rs,l,r;
	int mn,tag;
}t[N*2+1];

void add(int x,int v)
{
	t[x].mn+=v;
	t[x].tag+=v;
}

void update(int x)
{
	t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		add(t[x].ls,t[x].tag);
		add(t[x].rs,t[x].tag);
		t[x].tag=0;
	}
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
		return x;
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	return x;
}

int f[N];

void rb(int x)
{
	t[x].tag=0;
	t[x].mn=1e14;
	if(t[x].l==t[x].r)
	{
		t[x].mn=f[t[x].l-1];
		return;
	}
	rb(t[x].ls);
	rb(t[x].rs);
	update(x);
}

void change(int x,int l,int r,int v)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		add(x,v);
		return;
	}
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(l<=mid)
		change(t[x].ls,l,r,v);
	if(r>mid)
		change(t[x].rs,l,r,v);
	update(x);
}

int query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].mn;
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	int ret=1e14;
	if(l<=mid)
		ret=min(ret,query(t[x].ls,l,r));
	if(r>mid)
		ret=min(ret,query(t[x].rs,l,r));
	return ret;
}

int n,k,a[N],lst[N],vis[N];

signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		lst[i]=vis[a[i]];
		vis[a[i]]=i;
	}
	build(1,n);
	for(int i=1;i<=n;i++)
		f[i]=1e14;
	for(int i=1;i<=k;i++)
	{
		rb(1);
		for(int j=1;j<=n;j++)
		{
			if(lst[j])
				change(1,1,lst[j],j-lst[j]);
			if(j>=i)
				f[j]=query(1,1,j);
		}
	}
	printf("%lld\n",f[n]);
}