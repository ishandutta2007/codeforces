#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int k,n,L[N],R[N];

char s[N];

int cnt;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

struct T{
	int l,r,ls,rs;
	pii mn;
	int tag;
}t[N*2+1];

void add(int x,int v)
{
	t[x].mn.fs+=v;
	t[x].tag+=v;
}

void update(int x)
{
	t[x].mn.fs=min(t[t[x].ls].mn.fs,t[t[x].rs].mn.fs);
	t[x].mn.sd=(t[x].mn.fs==t[t[x].ls].mn.fs)*t[t[x].ls].mn.sd+(t[x].mn.fs==t[t[x].rs].mn.fs)*t[t[x].rs].mn.sd;
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

int build(int x,int l,int r)
{
	t[x].l=l,t[x].r=r;
	if(l==r)
	{
		t[x].mn.fs=k;
		for(int j=x;j>1;j>>=1)
			if(s[j>>1]=='?'||((s[j>>1]-'0')==(j&1)))
				t[x].mn.fs--;
		t[x].mn.sd=1;
		return x;
	}
	int mid=(l+r)>>1;
	t[x].ls=x<<1;
	build(t[x].ls,l,mid);
	t[x].rs=x<<1|1;
	build(t[x].rs,mid+1,r);
	update(x);
	return x;
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

int to[N],pos[N];

int main()
{
	scanf("%d",&k);
	n=1<<k;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
		to[i]=i;
	reverse(s+1,s+n);
	reverse(to+1,to+n);
	int tt=1;
	for(int j=0;j<k;j++)
	{
		reverse(s+tt,s+tt+(1<<j));
		reverse(to+tt,to+tt+(1<<j));
		tt+=1<<j;
	}
	for(int i=1;i<=n;i++)
		pos[to[i]]=i;
	build(1,1,n);
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int p;
		char c[2];
		scanf("%d%s",&p,c);
		p=pos[p];
		if(s[p]=='?')
			change(1,t[p].l,t[p].r,1);
		if(s[p]=='1')
			change(1,t[t[p].rs].l,t[t[p].rs].r,1);
		if(s[p]=='0')
			change(1,t[t[p].ls].l,t[t[p].ls].r,1);
		s[p]=c[0];
		if(s[p]=='?')
			change(1,t[p].l,t[p].r,-1);
		if(s[p]=='1')
			change(1,t[t[p].rs].l,t[t[p].rs].r,-1);
		if(s[p]=='0')
			change(1,t[t[p].ls].l,t[t[p].ls].r,-1);
		printf("%d\n",(t[1].mn.fs==0)*t[1].mn.sd);
	}
}