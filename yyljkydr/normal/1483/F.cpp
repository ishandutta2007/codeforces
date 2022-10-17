#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int n;

vector<int>s[N];

char t[N];

int trie[N][26],fail[N],tot,dep[N],tag[N],to[N];

void ins(vector<int>&s)
{
	int x=0;
	for(int i=0;i<s.size();i++)
	{
		if(trie[x][s[i]]==-1)
		{
			trie[x][s[i]]=++tot;
			dep[trie[x][s[i]]]=dep[x]+1;
			for(int j=0;j<26;j++)
				trie[tot][j]=-1;
		}
		x=trie[x][s[i]];
	}
	tag[x]=1;
}

queue<int>q;

vector<int>g[N];

void getfail()
{
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
		g[fail[i]].push_back(i);
}

int dc,st[N],ed[N];

void dfs(int x)
{
	st[x]=++dc;
	if(tag[x])
		to[x]=x;
	else
		to[x]=to[fail[x]];
	for(auto v:g[x])
		dfs(v);
	ed[x]=dc;
}

int c[N];

int lowbit(int x)
{
	return x&-x;
}

void add(int x,int v)
{
	while(x<=tot+1)
	{
		c[x]+=v;
		x+=lowbit(x);
	}
}

int query(int x)
{
	int ret=0;
	while(x)
	{
		ret+=c[x];
		x-=lowbit(x);
	}
	return ret;
}

map<int,int>vis;

vector<int>nd,ok;

int main()
{
	for(int i=0;i<26;i++)
		trie[0][i]=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",t);
		int len=strlen(t);
		for(int j=0;j<len;j++)
			s[i].push_back(t[j]-'a');
		ins(s[i]);
	}
	getfail();
	dfs(0);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=0;
		nd.clear();
		for(int j=0;j<s[i].size();j++)
		{
			x=trie[x][s[i][j]];
			nd.push_back(x);
			add(st[x],1);
		}
		to[x]=to[fail[x]];
		int mn=1e9;
		reverse(nd.begin(),nd.end());
		vis.clear();
		ok.clear();
		for(auto p:nd)
		{
			int q=to[p];
			if(!q)
				continue;
			if(dep[p]-dep[q]+1>=mn)
				continue;
			if(!vis[q])
				ok.push_back(q);
			vis[q]++;
			mn=min(mn,dep[p]-dep[q]+1);
		}
		to[x]=x;
		for(auto p:ok)
			if(query(ed[p])-query(st[p]-1)==vis[p])
				ans++;
		for(auto p:nd)
			add(st[p],-1);
	}
	printf("%d\n",ans);
}