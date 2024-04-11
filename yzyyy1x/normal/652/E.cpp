#include<bits/stdc++.h>
using namespace std;
const int N =3e5+10;
int tot=-1,num=0,from[3*N],hd[3*N],nxt[3*N],to[3*N],idx[N],dep[N],sz[N],fa[N],fly[N],a,b;
int n,m,rev[N];
bool ans=0,tr[3*N],line[N],vis[N];
vector<int>ha;
void add(int u,int v)
{
	nxt[++tot]=hd[u],from[tot]=u,to[tot]=v,hd[u]=tot;
	nxt[++tot]=hd[v],from[tot]=v,to[tot]=u,hd[v]=tot;
}
void dfs(int pos,int dp,int f,int ff)
{
	++num,idx[pos]=num,vis[pos]=1,dep[pos]=dp,sz[pos]=1,fa[pos]=f;
	for(int i=hd[pos];i!=-1;i=nxt[i])
	{
		if(!vis[to[i]])
		{
			tr[i]=1,dfs(to[i],dp+1,pos,i);
			sz[pos]+=sz[to[i]];
		}
	}
}
void doit(int x)
{
	if(vis[x])return;
	vis[x]=line[x]=1;
	doit(fly[x]);
}
void get(int y)
{
	doit(y);
	while(y!=a)
		y=fa[y],doit(y);
	doit(a);
}
void ddfs(int pos,int nw)
{
	fly[pos]=nw;
	if(dep[nw]<dep[pos])fly[pos]=pos;
	for(int i=hd[pos];i!=-1;i=nxt[i])
	{
		if(!tr[i])
		{
			if(dep[to[i]]>dep[fly[pos]])fly[pos]=to[i];
		}
	}
	for(int i=hd[pos];i!=-1;i=nxt[i])
	{
		if(tr[i])
		{
			ddfs(to[i],fly[pos]);
		}
	}
}
void Dfs(int pos)
{
	for(int i=hd[pos];i!=-1;i=nxt[i])
	{
		if(tr[i])
		{
			Dfs(to[i]);
			line[pos]|=line[to[i]];
		}
	}
}
int main()
{
	int u,v,op;
	memset(nxt,-1,sizeof nxt);
	memset(hd,-1,sizeof hd);
	memset(vis,0,sizeof vis);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&op);
		add(u,v);if(op==1)ha.push_back(i*2-2);
	}
	scanf("%d%d",&a,&b);
	bool ffff=0;
	lb:;
	dfs(a,1,-1,-1);memset(vis,0,sizeof vis);ddfs(a,0);
	get(b);Dfs(a);
	for(int i=0;i<ha.size();i++)
	{
		if(tr[ha[i]])
		{
			if(line[to[ha[i]]]){puts("YES");return 0;}
		}
		else if(tr[ha[i]^1])
		{
			if(line[from[ha[i]]]){puts("YES");return 0;}
		}
		else
		{
			if(line[to[ha[i]]]||line[from[ha[i]]]){puts("YES");return 0;}
		}		
	}
	if(!ffff)
	{
		ffff=1;
		memset(vis,0,sizeof vis);
		memset(fa,0,sizeof fa);
		memset(tr,0,sizeof tr);
		memset(line,0,sizeof line);
		memset(fly,0,sizeof fly);
		num=0;swap(a,b);
		goto lb;
	}
	puts("NO");
}