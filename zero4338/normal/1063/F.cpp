#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e5+5;
int n;
char s[maxn];
int ans;
int f[maxn];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mx;}t[maxn<<3];
	void change(int p,int x,int u=1,int l=1,int r=n*2)
	{
		t[u].mx=max(t[u].mx,x);
		if(l==r)return;
		int mid=(l+r)>>1;
		if(mid>=p)change(p,x,L(u),l,mid);
		else change(p,x,R(u),mid+1,r);
	}
	int query(int nl,int nr,int u=1,int l=1,int r=n*2)
	{
		if(l>=nl&&r<=nr)return t[u].mx;
		int ret=0,mid=(l+r)>>1;
		if(mid>=nl)ret=max(ret,query(nl,nr,L(u),l,mid));
		if(mid+1<=nr)ret=max(ret,query(nl,nr,R(u),mid+1,r));
		return ret;
	}
	#undef L
	#undef R
}tr;
struct SAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[26],fa,len;}t[maxn<<1];int cnt,ls,ed[maxn];
	void init(){F(0)=-1;}
	void insert(int x,int num)
	{
		int p=ls,np=ls=++cnt;ed[num]=np;
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
				L(nq)=L(p)+1;F(q)=F(np)=nq;
				for(;~p&&S(p,x)==q;p=F(p))S(p,x)=nq;
			}
		}
	}
	vector<int>e[maxn<<1];
	void add(int x,int y){e[x].push_back(y);}
	int in[maxn<<1],out[maxn<<1],tim;
	void dfs(int u)
	{
		in[u]=++tim;
		for(int &i:e[u])dfs(i);
		out[u]=tim;
	}
	void build()
	{
		for(int i=1;i<=cnt;i++)add(F(i),i);
		dfs(0);
	}
	void update(int pos){tr.change(in[ed[pos]],f[pos]);}
	bool check(int p,int val){return min(L(p),tr.query(in[p],out[p]))>=val;}
}T;
int main()
{
	n=read();scanf("%s",s+1);
	T.init();for(int i=n;i>=1;i--)T.insert(s[i]-'a',i);T.build();
	int p=n,pos=0;f[n]=1;
	for(int i=n-1;i>=1;i--)
	{
		while(!T.check(pos,p-i)&&!T.check(T.F(T.S(pos,s[i]-'a')),p-i)&&!T.check(T.S(pos,s[i]-'a'),p-i))
		{
			T.update(p--);
			while(~T.F(pos)&&T.L(T.F(pos))>=p-i)pos=T.F(pos);
		}
		pos=T.S(pos,s[i]-'a');
		f[i]=p-i+1;
	}
	for(int i=1;i<=n;i++)ans=max(ans,f[i]);
	printf("%d\n",ans);
	return 0;
}