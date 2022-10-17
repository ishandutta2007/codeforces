#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=2e5+1e3+7;

int n,q,a[N];

int cnt;

struct T{
	int l,r,ls,rs;
	int tag,mx,mn,sum;
}t[N*2+1];

void update(int x)
{
	t[x].mx=t[t[x].ls].mx;
	t[x].mn=t[t[x].rs].mn;
	t[x].sum=(t[t[x].ls].sum+t[t[x].rs].sum);
}

void cmax(int x,int v)
{
	assert(v>=t[x].mx);
	t[x].mx=v;
	t[x].tag=v;
	t[x].sum=(t[x].r-t[x].l+1)*v;
	t[x].mn=v;
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		cmax(t[x].ls,t[x].tag);
		cmax(t[x].rs,t[x].tag);
		t[x].tag=0;
	}
}

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].sum=t[x].mx=t[x].mn=a[l];
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int p,int v)
{
	if(t[x].mn>=v||!x)
		return;
	if(t[x].r<=p)
	{
		if(t[x].mx<=v)
			cmax(x,v);
		else
		{
			pushdown(x);
			change(t[x].ls,p,v);
			change(t[x].rs,p,v);
			update(x);
		}
		return;
	}
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	change(t[x].ls,p,v);
	if(p>mid)
		change(t[x].rs,p,v);
	update(x);
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

pii operator +(pii a,pii b)
{
	return mp(a.fs+b.fs,a.sd+b.sd);
}

pii query(int x,int p,int v)
{
	if(t[x].mn>v||!x)
		return mp(0,0);
	if(t[x].l>=p)
	{
		if(t[x].sum<=v)
			return mp(t[x].sum,t[x].r-t[x].l+1);
		else if(t[x].l==t[x].r)
			return mp(0,0);
	}
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	pii ret=mp(0,0);
	if(p<=mid)
		ret=query(t[x].ls,p,v);
	v-=ret.fs;
	if(v)
		ret=ret+query(t[x].rs,p,v);
	return ret;
}

signed main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	build(1,n);
	while(q--)
	{
		int op,x,y;
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1)
			change(1,x,y);
		else
			printf("%lld\n",query(1,x,y).sd);
	}
}