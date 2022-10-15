#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<cstdlib>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const int maxm=26;
int n;
ll ans;
char s[maxn];
struct SAM
{
	#define S(u,i) t[u].ch[i]
	#define SS(u) t[u].ch
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[maxm],fa,len,siz,ed;}t[maxn<<1];
	int cnt,las,pos[maxn];
	void clear(){cnt=las=0;F(0)=-1;memset(SS(0),0,sizeof SS(0));}
	void insert(int x,int id=0)
	{
		int p=las,np=las=++cnt;t[np].ed=id;pos[id]=np;
		memset(SS(cnt),0,sizeof SS(cnt));
		L(np)=L(p)+1;
		for(;~p&&!S(p,x);p=F(p))S(p,x)=np;
		if(p==-1)F(np)=0;
		else
		{
			int q=S(p,x);
			if(L(q)==L(p)+1)F(np)=q;
			else
			{
				int nq=++cnt;t[nq]=t[q];t[nq].ed=0;
				L(nq)=L(p)+1;
				F(q)=F(np)=nq;
				for(;~p&&S(p,x)==q;p=F(p))S(p,x)=nq;
			}
		}
	}
	void calc(){for(int i=1;i<=cnt;i++)ans+=L(i)-L(F(i));}
}S,T;
struct graph1
{
	int val[maxn<<1];
	int head[maxn<<1],ver[maxn<<1],nxt[maxn<<1],tot;
	void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
	int dfn[maxn<<1],eu[maxn<<1],tim,top[maxn<<1],son[maxn<<1],siz[maxn<<1],fa[maxn<<1],dep[maxn<<1];
	void getson(int u,int f)
	{
		fa[u]=f;dep[u]=dep[f]+1;siz[u]=1;
		for(int i=head[u];i;i=nxt[i])
		{
			getson(ver[i],u);
			siz[u]+=siz[ver[i]];
			if(siz[ver[i]]>siz[son[u]])son[u]=ver[i];
		}
	}
	void getroad(int u,int ance)
	{
		dfn[u]=++tim;eu[tim]=u;top[u]=ance;
		if(son[u])getroad(son[u],ance);
		for(int i=head[u];i;i=nxt[i])if(ver[i]!=son[u])getroad(ver[i],ver[i]);
	}
	void build()
	{
		for(int i=1;i<=T.cnt;i++)add(T.F(i),i);
		for(int i=1;i<=T.cnt;i++)val[i]=T.L(i);
		getson(0,0);
		getroad(0,0);	
	}
	int lca(int x,int y)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]])swap(x,y);
			x=fa[top[x]];
		}
		return dep[x]<dep[y]?x:y;
	}
}r;
struct graph2
{
	int head[maxn<<1],ver[maxn<<1],nxt[maxn<<1],tot;
	void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
	void build(){for(int i=1;i<=S.cnt;i++)add(S.F(i),i);}
	set<int>endpos[maxn<<1];ll g[maxn<<1];
	void getans(int u,int f)
	{
		for(int i=head[u];i;i=nxt[i])getans(ver[i],u);
		if(!u)return;
		if(S.t[u].ed&&T.pos[S.t[u].ed+2])endpos[u].insert(r.dfn[T.pos[S.t[u].ed+2]]),g[u]+=r.val[T.pos[S.t[u].ed+2]];
		for(int i=head[u];i;i=nxt[i])
		{
			if(endpos[ver[i]].size()>endpos[u].size()){swap(endpos[ver[i]],endpos[u]);swap(g[u],g[ver[i]]);}
			for(int j:endpos[ver[i]])
			{
				endpos[u].insert(j);
				auto it=endpos[u].find(j);
				g[u]+=r.val[r.eu[j]];
				if(endpos[u].size()==1)continue;
				if(it==endpos[u].begin())
				{
					it++;
					g[u]-=r.val[r.lca(r.eu[j],r.eu[*it])];
				}
				else if(it==--endpos[u].end())
				{
					it--;
					g[u]-=r.val[r.lca(r.eu[j],r.eu[*it])];
				}
				else
				{
					auto nxt=it,pre=it;
					nxt--;pre++;
					g[u]+=r.val[r.lca(r.eu[*nxt],r.eu[*pre])];
					g[u]-=r.val[r.lca(r.eu[j],r.eu[*pre])];
					g[u]-=r.val[r.lca(r.eu[j],r.eu[*nxt])];
				}
			}
		}
		ans+=(ll)(S.L(u)-S.L(S.F(u)))*g[u];
	}	
}o;
int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	S.clear();for(int i=1;i<=n;i++)S.insert(s[i]-'a');S.calc();
	S.clear();for(int i=1;i<=n-1;i++)S.insert(s[i]-'a');S.calc();
	S.clear();for(int i=2;i<=n;i++)S.insert(s[i]-'a');S.calc();
	ans+=2;
	T.clear();for(int i=n;i>=1;i--)T.insert(s[i]-'a',i);
	S.clear();for(int i=1;i<=n;i++)S.insert(s[i]-'a',i);
	o.build();r.build();
	o.getans(0,0);
	printf("%lld",ans);
	return 0;
}