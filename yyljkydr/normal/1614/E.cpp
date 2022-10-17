#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+1;

struct T{
	int l,r,ls,rs;
	int tag,mx;
}t[N*201+1];

int tot;

void update(int x)
{
	t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
}

void pushdown(int x)
{
	assert(t[x].l!=t[x].r);
	if(t[x].ls)
	{
		t[t[x].ls].tag+=t[x].tag;
		t[t[x].ls].mx+=t[x].tag;
	}
	else
	{
		t[x].ls=++tot;
		t[t[x].ls].l=t[x].l;
		t[t[x].ls].r=(t[x].l+t[x].r)>>1;
		t[t[x].ls].mx=t[x].tag+t[t[x].ls].r;
		t[t[x].ls].tag=t[x].tag;
	}
	if(t[x].rs)
	{
		t[t[x].rs].tag+=t[x].tag;
		t[t[x].rs].mx+=t[x].tag;
	}
	else
	{
		t[x].rs=++tot;
		t[t[x].rs].l=((t[x].l+t[x].r)>>1)+1;
		t[t[x].rs].r=t[x].r;
		t[t[x].rs].mx=t[x].tag+t[t[x].rs].r;
		t[t[x].rs].tag=t[x].tag;
	}
	t[x].tag=0;
}

void add(int &x,int l,int r,int L,int R,int v)
{
	if(L>R)
		return;
	if(!x)
	{
		x=++tot;
		t[x].l=l,t[x].r=r;
		t[x].mx=t[x].r;
	}
	assert(t[x].l==l&&t[x].r==r);
	if(L<=l&&r<=R)
	{
		t[x].tag+=v;
		t[x].mx+=v;
		return;
	}
	pushdown(x);
	int mid=(l+r)>>1;
	if(L<=mid)
		add(t[x].ls,l,mid,L,R,v);
	if(R>mid)
		add(t[x].rs,mid+1,r,L,R,v);
	update(x);
}

int qry(int x,int p)
{
	if(t[x].l==t[x].r)
		return t[x].mx;
	pushdown(x);
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)
		return qry(t[x].ls,p);
	else
		return qry(t[x].rs,p);
}

int qpr(int x,int s)
{
	if(t[x].l==t[x].r)
		return t[x].l;
	pushdown(x);
	if(t[t[x].ls].mx>=s)
		return qpr(t[x].ls,s);
	else
		return qpr(t[x].rs,s);
}

int n,s[N];

int main()
{
	scanf("%d",&n);
	int ans=0,rt=0;
	add(rt,0,1e9,0,1e9,0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
		int mx=qry(rt,1e9);
		if(mx>s[i])
			add(rt,0,1e9,qpr(rt,s[i]+1),1e9,-1),--mx;
		if(qry(rt,0)<s[i])
		{
			int p;
			if(s[i]>mx)
				p=1e9;
			else
				p=qpr(rt,s[i])-1;
			add(rt,0,1e9,0,p,1);
		}
		int k;
		scanf("%d",&k);
		while(k--)
		{
			int x;
			scanf("%d",&x);
			x=(x+ans)%P;
			ans=qry(rt,x);
			printf("%d\n",ans);
		}
	}
	assert(tot<N*201+1);
}