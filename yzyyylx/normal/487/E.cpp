#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define INF 0x3f3f3f3f
#define N 200100
using namespace std;

int n,m,Q,first[N],num[N],dfn[N],low[N],sta[N],bj[N],top[N],sn[N],fa[N],in[N],deep[N],tp,bb=1,tt,yn;
bool vis[N];
char str[2];
struct Bn
{
	int to,next;
}bn[N<<1];
struct Node
{
	int ls,rs,mn;
}node[N<<1];
struct Pq
{
	priority_queue<int,vector<int>,greater<int> >a,b;
	void push(int u){a.push(u);}
	void del(int u){b.push(u);}
	int top(){for(;!b.empty()&&a.top()==b.top();) a.pop(),b.pop();return a.top();}
}pq[N];
vector<int>son[N];

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void dfs(int now)
{
	int p,q,t;
	low[now]=dfn[now]=++tt;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		q=p>>1;
		if(vis[q]) continue;
		vis[q]=1;
		sta[++tp]=q;
		if(dfn[bn[p].to]) low[now]=min(low[now],dfn[bn[p].to]);
		else
		{
			dfs(bn[p].to);
			low[now]=min(low[now],low[bn[p].to]);
			if(low[bn[p].to]>=dfn[now])
			{
				++n;
				for(;;tp--)
				{
					t=bn[sta[tp]<<1].to;
					if(bj[t]!=n)
					{
						son[n].push_back(t);
						son[t].push_back(n);
						bj[t]=n;
					}
					t=bn[(sta[tp]<<1)+1].to;
					if(bj[t]!=n)
					{
						son[n].push_back(t);
						son[t].push_back(n);
						bj[t]=n;
					}
					if(sta[tp]==q) break;
				}
				tp--;
			}
		}
	}
}

int Dfs(int now,int last)
{
	int i,j,res=1,mx=0,t;
	if(now>yn) num[now]=INF;
	for(i=0;i<son[now].size();i++)
	{
		if(son[now][i]==last) continue;
		if(now>yn)
		{
//			if(now==7) cout<<"'"<<num[son[now][i]]<<"' ";
			pq[now-yn].push(num[son[now][i]]);
		}
		deep[son[now][i]]=deep[now]+1;
		fa[son[now][i]]=now;
		res+=t=Dfs(son[now][i],now);
		if(t>mx)
		{
			mx=t;
			sn[now]=son[now][i];
		}
	}
	if(now>yn) num[now]=pq[now-yn].top();
	return res;
}

void D2(int now,int last)
{
	int i,j;
	in[now]=++tt,dfn[tt]=now;
	if(sn[now])
	{
		top[sn[now]]=top[now];
		D2(sn[now],now);
	}
	else return;
	for(i=0;i<son[now].size();i++)
	{
		if(son[now][i]==last || son[now][i]==sn[now]) continue;
		top[son[now][i]]=son[now][i];
		D2(son[now][i],now);
	}
}

void build(int now,int l,int r)
{
	if(l==r)
	{
		node[now].mn=num[dfn[l]];
		return;
	}
	int mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
	node[now].mn=min(node[node[now].ls].mn,node[node[now].rs].mn);
}

int ask(int now,int l,int r,int u,int v)
{
	if(u==l&&v==r) return node[now].mn;
	int mid=((l+r)>>1),res=INF;
	if(u<=mid) res=min(res,ask(node[now].ls,l,mid,u,min(mid,v)));
	if(mid<v) res=min(res,ask(node[now].rs,mid+1,r,max(mid+1,u),v));
	return res;
}

void chg(int now,int l,int r,int u,int v)
{
	if(l==r)
	{
		node[now].mn=v;
		return;
	}
	int mid=((l+r)>>1);
	if(u<=mid) chg(node[now].ls,l,mid,u,v);
	else chg(node[now].rs,mid+1,r,u,v);
	node[now].mn=min(node[node[now].ls].mn,node[node[now].rs].mn);
}

inline int work(int u,int v)
{
	int res=INF;
	for(;top[u]!=top[v];)
	{
		if(deep[top[u]]<deep[top[v]]) swap(u,v);
		res=min(res,ask(1,1,n,in[top[u]],in[u]));
		u=fa[top[u]];
	}
	if(deep[u]<deep[v]) swap(u,v);
	res=min(res,ask(1,1,n,in[v],in[u]));
	if(v>yn) res=min(res,num[fa[v]]);
	return res;
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,p,q,t;
	cin>>n>>m>>Q;
	yn=n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&p,&q);
		add(p,q),add(q,p);
	}
	deep[1]=top[1]=1;
	dfs(1);
	/*
	puts("");
	for(i=1;i<=n;i++)
	{
		for(j=0;j<son[i].size();j++)
		{
			cout<<i<<' '<<son[i][j]<<endl;
		}
	}
	return 0;
	//*/
	tt=0;
	Dfs(1,-1);
	D2(1,-1);
//	for(i=1;i<=n;i++) cout<<num[i]<<' ';return 0;
	
	build(tt=1,1,n);
	for(i=1;i<=Q;i++)
	{
		scanf("%s",str);
		if(str[0]=='A')
		{
			scanf("%d%d",&p,&q);
			printf("%d\n",work(p,q));
		}
		else
		{
			scanf("%d%d",&p,&q);
			t=fa[p]-yn;
			if(fa[p]) pq[t].del(num[p]);
			num[p]=q,chg(1,1,n,in[p],q);
			if(fa[p])
			{
				pq[t].push(q);
				if(pq[t].top()!=num[fa[p]])
				{
					chg(1,1,n,in[fa[p]],num[fa[p]]=pq[t].top());
				}
			}
		}
	}
}