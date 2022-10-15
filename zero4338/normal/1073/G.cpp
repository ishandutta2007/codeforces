#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,q;
char s[maxn];
struct SAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[26],fa,len;}t[maxn<<1];int cnt,ls,ed[maxn];
	void init(){F(0)=-1;}
	void insert(int x,int num)
	{
		int p=ls,np=ls=++cnt;ed[num]=cnt;
		L(np)=L(p)+1;
		for(;~p&&!S(p,x);p=F(p))S(p,x)=np;
		if(p==-1)F(np)=0;
		else
		{
			int q=S(p,x);
			if(L(q)==L(p)+1)F(np)=q;
			else
			{
				int nq=++cnt;t[nq]=t[q];
				L(nq)=L(p)+1;F(np)=F(q)=nq;
				for(;~p&&S(p,x)==q;p=F(p))S(p,x)=nq;
			}
		}
	}
	vector<int>e[maxn<<1];
	void add(int x,int y){e[x].push_back(y);}
	int dfn[maxn<<1],tim,eu[maxn<<2],st[21][maxn<<2],dep[maxn<<1];
	void dfs(int u)
	{
		eu[dfn[u]=++tim]=u;
		for(int &i:e[u])dep[i]=dep[u]+1,dfs(i),eu[++tim]=u;
	}
	int mind(int &x,int &y){return dep[x]<dep[y]?x:y;}
	void prework()
	{
		for(int i=1;i<=tim;i++)st[0][i]=eu[i];
		for(int i=1;(1<<i)<=tim;i++)
			for(int j=1;j+(1<<i)-1<=tim;j++)
				st[i][j]=mind(st[i-1][j],st[i-1][j+(1<<(i-1))]);
	}
	void build()
	{
		for(int i=1;i<=cnt;i++)add(F(i),i);
		dfs(0);prework();
	}
	int lca(int x,int y)
	{
		x=dfn[x];y=dfn[y];
		if(x>y)swap(x,y);int k=log2(y-x+1);
		return mind(st[k][x],st[k][y-(1<<k)+1]);
	}
	#undef S
	#undef F
	#undef L
}o;
struct vtree
{
	vector<int>e[maxn<<1];int val[maxn<<1];
	void add(int x,int y){e[x].push_back(y);}
	ll dfs(int u)
	{
		ll ret=0;if(val[u]>1)ret+=o.t[u].len;
		for(int &i:e[u])
		{
			ret+=dfs(i);
			ret+=(ll)val[u]*val[i]*o.t[u].len;
			val[u]+=val[i];
		}
		return ret;
	}
	ll query(vector<int>p)
	{
		for(int &i:p)i=o.ed[i];
		sort(p.begin(),p.end(),[](int &i,int &j){return o.dfn[i]<o.dfn[j];});
		for(int &i:p)val[i]++;
		p.resize(unique(p.begin(),p.end())-p.begin());
		static int sta[maxn<<1],top;
		sta[top=1]=0;
		vector<int>tmp;
		for(int &i:p)
		{
			int fa=o.lca(i,sta[top]);tmp.push_back(fa);
			if(fa!=sta[top])
			{
				while(o.dfn[fa]<o.dfn[sta[top-1]])add(sta[top-1],sta[top]),top--;
				if(o.dfn[fa]>o.dfn[sta[top-1]])add(fa,sta[top]),sta[top]=fa;
				else add(sta[top-1],sta[top]),top--;
			}
			sta[++top]=i;
		}
		for(int i=1;i<=top-1;i++)add(sta[i],sta[i+1]);
		ll ret=dfs(0);
		for(int &i:p)e[i].clear(),val[i]=0;
		for(int &i:tmp)e[i].clear(),val[i]=0;
		e[0].clear();val[0]=0;
		return ret;
	}
}v;
int main()
{
	n=read();q=read();scanf("%s",s+1);
	o.init();
	for(int i=n;i>=1;i--)o.insert(s[i]-'a',i);o.build();
	while(q--)
	{
		ll ret=0;
		vector<int>a,b;
		a.resize(read());b.resize(read());
		generate(a.begin(),a.end(),read);generate(b.begin(),b.end(),read);
		ret-=v.query(a)+v.query(b);
		for(int &i:b)a.push_back(i);
		ret+=v.query(a);
		printf("%lld\n",ret);
	}
	return 0;
}