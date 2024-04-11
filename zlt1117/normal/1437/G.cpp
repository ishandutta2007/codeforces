#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define pb push_back
#define PII pair<int,int>
#define gc getchar()//(p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
using namespace std;
char buf[100000],*p1,*p2;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=gc;}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a<b?b:a;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=6e5+5;
int fa[maxn],len[maxn],tot=1,last=1,sz,p[maxn],son[maxn][26],pos[maxn],dfn[maxn],siz[maxn],tp[maxn],so[maxn],rel[maxn],val[maxn];
char s[maxn];
struct edge
{
	int v,nxt;
	edge(int vv=0,int nn=0){v=vv,nxt=nn;}
}e[maxn<<1];
inline void add(int u,int v)
{
	e[++sz]=edge(v,p[u]);
	p[u]=sz;
}
struct SAM
{
	inline void insert(int c)
	{
		int np=++tot,p=last;
		len[np]=len[p]+1,last=np;
		while(!son[p][c]&&p)son[p][c]=np,p=fa[p];
		if(!p)fa[np]=1;
		else
		{
			int q=son[p][c];
			if(len[q]==len[p]+1)fa[np]=q;
			else
			{
				int nq=++tot;
				len[nq]=len[p]+1;
				fa[nq]=fa[q];
				fa[q]=fa[np]=nq;
				memcpy(son[nq],son[q],sizeof(son[q]));
				while(p&&son[p][c]==q)son[p][c]=nq,p=fa[p];
			}
		}
	}
}sam;
int n,q;
inline void dfs(int u)
{
	if(len[u]==len[fa[u]]&&u!=1)rel[u]=rel[fa[u]];
	else rel[u]=u;
	siz[u]=1;
	REP(u)
	{
		int v=e[i].v;
		if(v==fa[u])continue;
		dfs(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[so[u]])so[u]=v;
	}
}
inline void dfs2(int u,int topf)
{
	dfn[u]=++tot;
	tp[u]=topf;
	if(so[u])dfs2(so[u],topf);
	REP(u)
	{
		int v=e[i].v;
		if(v==fa[u]||v==so[u])continue;
		dfs2(v,v);
	}
}
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	static const int maxn=3e6+5;
	int maxv[maxn];
	inline void pushup(int u){maxv[u]=max(maxv[ls],maxv[rs]);}
	inline void update(int u,int l,int r,int x,int v)
	{
		if(l==r){return maxv[u]=v,void();}
		int mid=(l+r)>>1;
		if(x<=mid)update(ls,l,mid,x,v);
		else update(rs,mid+1,r,x,v);
		pushup(u);
	}
	inline int query(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)return maxv[u];
		int ret=-1e9;
		int mid=(l+r)>>1;
		if(x<=mid)ret=query(ls,l,mid,x,y);
		if(y>mid)ret=max(ret,query(rs,mid+1,r,x,y));
		return ret;
	}
}tree;
inline int Query(int u)
{
	int ret=-1e9;
	while(u)
	{
		ret=max(ret,tree.query(1,1,n,dfn[tp[u]],dfn[u]));
		u=fa[tp[u]];
	}
	return ret;
}
multiset<int>ss[maxn];
int main()
{
	memset(p,-1,sizeof(p));
	n=gi(),q=gi();
	FOR(i,1,n)
	{
		last=1;
		scanf("%s",s+1);
		int len=strlen(s+1);
		FOR(j,1,len)sam.insert(s[j]-'a');
		pos[i]=last;
	}
	FOR(i,2,tot)add(fa[i],i);
	int xx=n;
	n=tot;
	tot=0;
	dfs(1);
	dfs2(1,1);
	FOR(i,2,tot)if(i!=rel[i])ss[rel[i]].insert(0);
	FOR(i,1,tot)tree.update(1,1,tot,i,-1e9);
	FOR(i,1,xx)tree.update(1,1,tot,dfn[rel[pos[i]]],0);
	while(q--)
	{
		int typ=gi();
		if(typ==2)
		{
			scanf("%s",s+1);
			int len1=strlen(s+1);
			int now=1,nowlen=0;
			int ans=-1;
			FOR(i,1,len1)
			{
				while(!son[now][s[i]-'a']&&now)now=fa[now],nowlen=len[now];
				if(now==0){now=1;nowlen=0;continue;}
				nowlen++;
				if(son[now][s[i]-'a'])now=son[now][s[i]-'a'];
				if(nowlen==len[now])ans=max(ans,Query(now));///fa[now]
				else ans=max(ans,Query(fa[now]));
			}
			printf("%d\n",ans);
		}
		else
		{
			int id=gi(),x=gi();
			if(pos[id]!=rel[pos[id]])
			{
				auto it=ss[rel[pos[id]]].find(val[pos[id]]);
				ss[rel[pos[id]]].erase(it);
				ss[rel[pos[id]]].insert(val[pos[id]]=x);
			}
			else val[pos[id]]=x;
			if(ss[rel[pos[id]]].size())
			{
				auto it=ss[rel[pos[id]]].end();
				it--;
				x=max(x,*it);
			}
			tree.update(1,1,n,dfn[rel[pos[id]]],max(x,val[rel[pos[id]]]));
		}
	}
	return 0;
}///