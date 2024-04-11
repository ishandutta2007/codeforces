#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int cnt;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

struct T{
	int ls,rs,l,r;
	pii mn;
	int tag;
}t[N*2+1];

void update(int x)
{
	t[x].mn=min(t[t[x].ls].mn,t[t[x].rs].mn);
}

void pushdown(int x)
{
	if(t[x].tag)
	{
		t[t[x].ls].mn.fs+=t[x].tag;
		t[t[x].ls].tag+=t[x].tag;
		t[t[x].rs].mn.fs+=t[x].tag;
		t[t[x].rs].tag+=t[x].tag;
		t[x].tag=0;
	}
}

int n,a[N];

int build(int l,int r)
{
	int x=++cnt;
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].mn=mp(l-a[l]>=0?l-a[l]:1e9,l);
		return x;
	}
	int mid=(t[x].l+t[x].r)>>1;
	t[x].ls=build(l,mid);
	t[x].rs=build(mid+1,r);
	update(x);
	return x;
}

void change(int x,int l,int r,int v)
{
	if(l<=t[x].l&&t[x].r<=r)
	{
		t[x].mn.fs+=v;
		t[x].tag+=v;
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

pii query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].mn;
	int mid=(t[x].l+t[x].r)>>1;
	pii ret=mp(1e9,1e9);
	if(l<=mid)
		ret=min(ret,query(t[x].ls,l,r));
	if(r>mid)
		ret=min(ret,query(t[x].rs,l,r));
	update(x);
	return ret;
}

int c[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int v)
{
	while(x<=n)
	{
		c[x]+=v;
		x+=lowbit(x);
	}
}

int qsum(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

int q;

vector<pii>v[N];

int ans[N];

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	build(1,n);
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x+1].push_back(mp(n-y,i));
	}
	for(int i=n;i>=1;i--)
	{
		pii tmp=query(1,i,n);
		while(tmp.fs<=0)
		{
			add(tmp.sd,1);
			change(1,tmp.sd,n,-1);
			change(1,tmp.sd,tmp.sd,1e9);
			tmp=query(1,i,n);
		}
		for(auto x:v[i])
			ans[x.sd]=qsum(x.fs);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
}