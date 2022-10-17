#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=1e5+1e2+7;

int cnt=1,head[N];

struct Edge{
	int ne,to,w;
}edg[N*2+1];

void build(int u,int v,int w)
{
	++cnt;
	edg[cnt].to=v;
	edg[cnt].ne=head[u];
	head[u]=cnt;
	edg[cnt].w=w;
	++cnt;
	edg[cnt].to=u;
	edg[cnt].ne=head[v];
	head[v]=cnt;
	edg[cnt].w=0;
}

int n;

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

map<pii,int>w,id;

vector<pii>v[4];

int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

queue<int>q;

int d[N];

int S,T;

bool bfs()
{
	fill(d+S,d+T+1,-1);
	d[S]=0;
	q.push(S);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
		{
			int v=edg[tmp].to;
			if(d[v]!=-1||!edg[tmp].w)
				continue;
			d[v]=d[x]+1;
			q.push(v);
		}
	}
	return d[T]!=-1;
}

int dinic(int x,int mn)
{
	if(x==T||!mn)
		return mn;
	int flow=0,tmpf;
	for(int tmp=head[x];tmp;tmp=edg[tmp].ne)
	{
		int v=edg[tmp].to;
		if(d[v]==d[x]+1&&(tmpf=dinic(v,min(mn,edg[tmp].w)))>0)
		{
			flow+=tmpf;
			mn-=tmpf;
			edg[tmp].w-=tmpf;
			edg[tmp^1].w+=tmpf;
		}
		if(!mn)
			break;
	}
	if(!mn)
		d[x]=-1;
	return flow;
}

signed main()
{
	scanf("%lld",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x,y,val;
		scanf("%lld%lld",&x,&y);
		scanf("%lld",&val);
		w[mp(x,y)]=val;
		build(i,i+n,w[mp(x,y)]);
		sum+=w[mp(x,y)];
		id[mp(x,y)]=i;
		v[(abs(x)&1)+((abs(y)&1)<<1)].push_back(mp(x,y));
	}
	S=0,T=n*2+1;
	for(auto p:v[1])//1->0
	{
		int x=p.fs,y=p.sd;
		build(S,id[mp(x,y)],1e13);
		int tx,ty;
		tx=x-1,ty=y;
		if(id.find(mp(tx,ty))!=id.end())
			build(id[mp(x,y)]+n,id[mp(tx,ty)],1e13);
		tx=x+1,ty=y;
		if(id.find(mp(tx,ty))!=id.end())
			build(id[mp(x,y)]+n,id[mp(tx,ty)],1e13);
	}
	
	for(auto p:v[0])//0->2
	{
		int x=p.fs,y=p.sd;
		int tx,ty;
		tx=x,ty=y-1;
		if(id.find(mp(tx,ty))!=id.end())
			build(id[mp(x,y)]+n,id[mp(tx,ty)],1e13);
		tx=x,ty=y+1;
		if(id.find(mp(tx,ty))!=id.end())
			build(id[mp(x,y)]+n,id[mp(tx,ty)],1e13);
	}
	
	for(auto p:v[2])//2->3
	{
		int x=p.fs,y=p.sd;
		int tx,ty;
		tx=x-1,ty=y;
		if(id.find(mp(tx,ty))!=id.end())
			build(id[mp(x,y)]+n,id[mp(tx,ty)],1e13);
		tx=x+1,ty=y;
		if(id.find(mp(tx,ty))!=id.end())
			build(id[mp(x,y)]+n,id[mp(tx,ty)],1e13);
	}
	
	for(auto p:v[3])
	{
		int x=p.fs,y=p.sd;
		build(id[mp(x,y)]+n,T,1e13);
	}
	while(bfs())
		sum-=dinic(S,1e13);
	printf("%lld\n",sum);
}