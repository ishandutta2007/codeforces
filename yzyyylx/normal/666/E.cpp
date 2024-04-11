#include<bits/stdc++.h>
#define P pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define LG 19
#define N 500100
#define M 50100
using namespace std;

int n,m,Q;
P ans[N];
string S,T[M];

namespace Xds
{
    int tt;
    struct Node
    {
	int ls,rs,mx,pos,yp;
	bool dwn;
	void clear(){dwn=1,mx=0,pos=yp;}
    }node[M<<1];

    void up(int now)
    {
	int L=node[now].ls,R=node[now].rs;
	if(node[L].mx>=node[R].mx)
	{
	    node[now].mx=node[L].mx;
	    node[now].pos=node[L].pos;
	}
	else
	{
	    node[now].mx=node[R].mx;
	    node[now].pos=node[R].pos;
	}
    }

    void down(int now)
    {
	int L=node[now].ls,R=node[now].rs;
	if(node[now].dwn)
	{
	    node[L].clear();
	    node[R].clear();
	    node[now].dwn=0;
	}
    }
    
    void build(int now,int l,int r)
    {
	node[now].yp=l;
	if(l==r)
	{
	    node[now].pos=l;
	    return;
	}
	int mid=((l+r)>>1);
	node[now].ls=++tt;
	build(tt,l,mid);
	node[now].rs=++tt;
	build(tt,mid+1,r);
	up(now);
    }

    void add(int now,int l,int r,int u)
    {
	if(l==r)
	{
	    node[now].mx++;
	    return;
	}
	down(now);
	int mid=((l+r)>>1);
	if(u<=mid) add(node[now].ls,l,mid,u);
	else add(node[now].rs,mid+1,r,u);
	up(now);
    }

    P ask(int now,int l,int r,int u,int v)
    {
	if(u<=l&&r<=v) return mp(node[now].mx,node[now].pos);
	down(now);
	int mid=((l+r)>>1);
	if(v<=mid) return ask(node[now].ls,l,mid,u,v);
	if(mid<u) return ask(node[now].rs,mid+1,r,u,v);
	P p=ask(node[now].ls,l,mid,u,v),q=ask(node[now].rs,mid+1,r,u,v);
	if(p.fi>=q.fi) return p;
	return q;
    }
    
    void clear()
    {
	node[1].clear();
    }
    void init(){build(tt=1,1,m);}
}

namespace SAM
{
    int last,tt,fa[N<<1][20],pos[N<<1],size[N<<1],son[N<<1];
    struct Cz
    {
	int id,pos,l,r;
	bool operator < (const Cz &u) const{if(pos!=u.pos) return pos>u.pos;return l<u.l;}
    };
    struct Node
    {
	int to[26],len;
    }node[N<<1];
    vector<int>to[N<<1];
    vector<Cz>c[N<<1];
    
    void add(int u)
    {
	int p=last,np=++tt;
	last=np;
	node[np].len=node[p].len+1;
	pos[node[np].len]=tt;
	for(;p&&!node[p].to[u];p=fa[p][0]) node[p].to[u]=np;
	if(!p)
	{
	    fa[np][0]=1;
	    return;
	}
	int q=node[p].to[u];
	if(node[q].len==node[p].len+1)
	{
	    fa[np][0]=q;
	    return;
	}
	int nq=++tt;
	node[nq].len=node[p].len+1;
	fa[nq][0]=fa[q][0];
	memcpy(node[nq].to,node[q].to,sizeof(node[q].to));
	fa[np][0]=fa[q][0]=nq;
	for(;node[p].to[u]==q;p=fa[p][0]) node[p].to[u]=nq;
    }
    
    void pre()
    {
	int i,j;
	for(i=1;i<=LG;i++)
	{
	    for(j=1;j<=tt;j++)
	    {
		fa[j][i]=fa[fa[j][i-1]][i-1];
	    }
	}
    }
    void pre2()
    {
	int i;
	for(i=1;i<=tt;i++)
	{
	    sort(c[i].begin(),c[i].end());
	    if(i>1) to[fa[i][0]].push_back(i);
	}
    }
    int get(int u,int v)
    {
	int i;
	for(i=LG;i>=0;i--) if(node[fa[u][i]].len>=v) u=fa[u][i];
	return u;
    }
    void in(int u)
    {
	int i,t,now,l;
	now=1,l=0;
	for(i=0;i<T[u].size();i++)
	{
	    t=T[u][i]-'a';
	    if(!node[now].to[t])
	    {
		for(;now!=1&&!node[now].to[t];now=fa[now][0]);
		l=node[now].len;
	    }
	    if(node[now].to[t])
	    {
		now=node[now].to[t];
		l++;
	    }
	    Cz cz;
	    cz.l=cz.r=0;
	    cz.pos=l,cz.id=u;
//	    cerr<<" "<<now<<endl;
	    c[now].push_back(cz);
	    size[now]++;
	}
    }
    void in(int w,int u,int v,int p,int q)
    {
	int i,t;
	t=get(pos[q],q-p+1);
	Cz cz;
	cz.pos=q-p+1;
	cz.id=w;
	cz.l=u;
	cz.r=v;
	c[t].push_back(cz);
    }
    void gs(int now)
    {
	int i,t,mx=-1;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    gs(t);
	    size[now]+=size[t];
	    if(size[t]>mx)
	    {
		son[now]=t;
		mx=size[t];
	    }
	}
    }
    void Dfs(int now)
    {
	int i,j,t;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    Dfs(t);
	}
	for(i=0;i<c[now].size();i++) if(!c[now][i].l) Xds::add(1,1,m,c[now][i].id);
    }
    void dfs(int now)
    {
	int i,t;
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    if(son[now]==t) continue;
	    dfs(t);
	}
	Xds::clear();
	if(son[now]) dfs(son[now]);
	for(i=0;i<to[now].size();i++)
	{
	    t=to[now][i];
	    if(son[now]==t) continue;
	    Dfs(t);
	}
	for(i=0;i<c[now].size();i++)
	{
	    Cz cz=c[now][i];
	    if(!cz.l) Xds::add(1,1,m,cz.id);
	    else ans[cz.id]=Xds::ask(1,1,m,cz.l,cz.r);
	}
    }
    void work()
    {
	gs(1);
	dfs(1);
    }
    void init(){last=tt=1;}
}

int main()
{
    SAM::init();
    int i,j,p,q,l,r,now,t;
    cin>>S>>m;
    for(i=0;i<S.size();i++) SAM::add(S[i]-'a');
    SAM::pre();
    for(i=1;i<=m;i++)
    {
        cin>>T[i];
	SAM::in(i);
    }
    cin>>Q;
    for(i=1;i<=Q;i++)
    {
	scanf("%d%d%d%d",&l,&r,&p,&q);
	SAM::in(i,l,r,p,q);
    }
    Xds::init();
    SAM::pre2();
    SAM::work();
    for(i=1;i<=Q;i++) printf("%d %d\n",ans[i].se,ans[i].fi);
}