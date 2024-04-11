#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,m,q;
struct per_seg
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int sum,ls,rs;}t[maxn*50];int cnt,rt[maxn];
	int clone(int u){t[++cnt]=t[u];return cnt;}
	int change(int u,int p,int l=1,int r=n)
	{
		u=clone(u);t[u].sum++;
		if(l==r)return u;
		int mid=(l+r)>>1;
		if(mid>=p)L(u)=change(L(u),p,l,mid);
		else R(u)=change(R(u),p,mid+1,r);
		return u;
	}
	int query(int u1,int u2,int nl,int nr,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr)return t[u2].sum-t[u1].sum;
		int mid=(l+r)>>1,ret=0;
		if(mid>=nl)ret+=query(L(u1),L(u2),nl,nr,l,mid);
		if(mid+1<=nr)ret+=query(R(u1),R(u2),nl,nr,mid+1,r);
		return ret;
	}
	#undef L
	#undef R
}tr;
struct graph
{
	vector<int>e[maxn];
	void add(int x,int y){e[x].push_back(y);}
	int faz[18][maxn],dep[maxn],to[18][maxn],in[maxn],out[maxn],tim;
	void getfa(int u,int fa)
	{
		in[u]=++tim;dep[u]=dep[fa]+1;faz[0][u]=fa;
		for(int i=1;(1<<i)<dep[u];i++)faz[i][u]=faz[i-1][faz[i-1][u]];
		for(int &i:e[u])if(i!=fa)getfa(i,u);
		out[u]=tim;
	}
	int lca(int x,int y)
	{
		if(dep[x]<dep[y])swap(x,y);
		for(int i=17;i>=0;i--)if(dep[faz[i][x]]>=dep[y])x=faz[i][x];
		if(x==y)return x;
		for(int i=17;i>=0;i--)if(faz[i][x]!=faz[i][y])x=faz[i][x],y=faz[i][y];
		return faz[0][x];
	}
	vector<int>addp[maxn];
	void getto0(int u,int fa)
	{
		to[0][u]=u;
		for(int &i:e[u])
			if(i!=fa)
			{
				getto0(i,u);
				if(dep[to[0][i]]<dep[to[0][u]])to[0][u]=to[0][i];
			}
		for(int &i:addp[u])if(dep[i]<dep[to[0][u]])to[0][u]=i;
	}
	void getto(int u,int fa)
	{
		for(int i=1;i<=17;i++)to[i][u]=to[i-1][to[i-1][u]];
		for(int &i:e[u])if(i!=fa)getto(i,fa);
	}
	int calc(int x,int y)
	{
		int lf=lca(x,y),ret=0;
		if(x==lf||y==lf)
		{
			if(x==lf)swap(x,y);
			for(int i=17;i>=0;i--)if(dep[to[i][x]]>dep[lf])ret+=1<<i,x=to[i][x];
			if(dep[to[0][x]]>dep[lf])return -1;
			return ret+1;
		}
		for(int i=17;i>=0;i--)if(dep[to[i][x]]>dep[lf])ret+=1<<i,x=to[i][x];
		for(int i=17;i>=0;i--)if(dep[to[i][y]]>dep[lf])ret+=1<<i,y=to[i][y];
		if(dep[to[0][x]]>dep[lf]||dep[to[0][y]]>dep[lf])return -1;
		if(tr.query(tr.rt[in[x]-1],tr.rt[out[x]],in[y],out[y]))return ret+1;
		return ret+2;
	}
}o;
vector<int>to[maxn];
int main()
{
	n=read();
	for(int i=2;i<=n;i++)o.add(read(),i);
	o.getfa(1,0);
	m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		to[o.in[a]].push_back(o.in[b]);
		to[o.in[b]].push_back(o.in[a]);		
		int lf=o.lca(a,b);
		o.addp[a].push_back(lf);
		o.addp[b].push_back(lf);
	}
	o.getto0(1,0);o.getto(1,0);
	for(int i=1;i<=n;i++)
	{
		tr.rt[i]=tr.rt[i-1];
		for(int &j:to[i])tr.rt[i]=tr.change(tr.rt[i],j);
	}
	q=read();
	while(q--)printf("%d\n",o.calc(read(),read()));
	return 0;
}