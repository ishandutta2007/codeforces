#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int n,q;

vector<int>s[N];

int trie[N][26],fail[N],tot,tag[N],pos[N];

multiset<int>ms[N];

void ins(vector<int>&s,int p)
{
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		if(trie[x][s[i]]==-1)
		{
			trie[x][s[i]]=++tot;
			for(int j=0;j<26;j++)
				trie[tot][j]=-1;
		}
		x=trie[x][s[i]];
	}
	tag[x]=1;
	pos[p]=x+1;
	ms[x+1].insert(0);
}


vector<int>g[N];

void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)
		if(trie[0][i]!=-1)
			fail[trie[0][i]]=0,q.push(trie[0][i]);
		else
			trie[0][i]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=0;i<26;i++)
			if(trie[x][i]==-1)
				trie[x][i]=trie[fail[x]][i];
			else
				fail[trie[x][i]]=trie[fail[x]][i],q.push(trie[x][i]);
	}
	for(int i=1;i<=tot;i++)
		g[fail[i]+1].push_back(i+1);
}

int dc,st[N],ed[N],top[N],dep[N],fa[N],sz[N],son[N],has[N];

void dfs1(int x)
{
	sz[x]=1;
	has[x]|=tag[x-1];
	for(auto v:g[x])
	{
		has[v]|=has[x];
		dfs1(v);
		sz[x]+=sz[v];
		dep[v]=dep[x]+1;
		fa[v]=x;
		if(sz[v]>sz[son[x]])
			son[x]=v;
	}
}

void dfs2(int x)
{
	st[x]=ed[x]=++dc;
	if(!son[x])
		return;
	int v=son[x];
	top[v]=top[x];
	dfs2(v);
	for(auto v:g[x])
	{
		if(v==son[x])
			continue;
		top[v]=v;
		dfs2(v);
	}
	ed[x]=dc;
}

int cnt;

struct T{
	int ls,rs,l,r;
	int mx;
}t[N*2+1];

void update(int x)
{
	t[x].mx=max(t[t[x].ls].mx,t[t[x].rs].mx);
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
	update(x);
	return x;
}	

void change(int x,int p,int v)
{
	if(t[x].l==t[x].r)
	{
		t[x].mx=v;
		return;
	}
	int mid=(t[x].l+t[x].r)>>1;
	if(p<=mid)
		change(t[x].ls,p,v);
	else
		change(t[x].rs,p,v);
	update(x);
}

int query(int x,int l,int r)
{
	if(l<=t[x].l&&t[x].r<=r)
		return t[x].mx;
	int mid=(t[x].l+t[x].r)>>1;
	int ret=0;
	if(l<=mid)
		ret=max(ret,query(t[x].ls,l,r));
	if(r>mid)
		ret=max(ret,query(t[x].rs,l,r));
	return ret;
}

int qmx(int x)
{
	int ret=0;
	while(x)
	{
		ret=max(ret,query(1,st[top[x]],st[x]));
		x=fa[top[x]];
	}
	return ret;
}

int Ask(char *s)
{
	int len=strlen(s);
	int x=0,ret=0,hs=0;
	for(int i=0;i<len;i++)
	{
		x=trie[x][s[i]-'a'];
		ret=max(ret,qmx(x+1));
		hs|=has[x+1];
	}
	return hs?ret:-1;
}

int val[N];

int main()
{
	for(int i=0;i<26;i++)
		trie[0][i]=-1;
	scanf("%d%d",&n,&q);
	char t[N];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t);
		int len=strlen(t);
		for(int j=0;j<len;j++)
			s[i].push_back(t[j]-'a');
		ins(s[i],i);
	}
	getfail();
	dfs1(1);
	top[1]=1;
	dfs2(1);
	build(1,tot+1);
	while(q--)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			ms[pos[x]].erase(ms[pos[x]].find(val[x]));
			val[x]=y;
			ms[pos[x]].insert(val[x]);
			y=*ms[pos[x]].rbegin();
			change(1,st[pos[x]],y);
		}
		else
		{
			scanf("%s",t);
			printf("%d\n",Ask(t));
		}
	}
}