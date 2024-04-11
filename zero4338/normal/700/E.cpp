#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n;
char s[maxn];
struct per_seg
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int ls,rs,sum;}t[maxn*100];int cnt,rt[maxn];
	int clone(int u){t[++cnt]=t[u];return cnt;}
	int change(int u,int p,int x,int l=1,int r=2*n)
	{
		u=clone(u);
		t[u].sum+=x;
		if(l==r)return u;
		int mid=(l+r)>>1;
		if(mid>=p)L(u)=change(L(u),p,x,l,mid);
		else R(u)=change(R(u),p,x,mid+1,r);
		return u;
	}
	bool judge(int u1,int u2,int nl,int nr,int l=1,int r=2*n)
	{
		if(l>=nl&&r<=nr)return t[u2].sum-t[u1].sum;
		int mid=(l+r)>>1;
		if(mid>=nl&&judge(L(u1),L(u2),nl,nr,l,mid))return true;
		if(mid+1<=nr&&judge(R(u1),R(u2),nl,nr,mid+1,r))return true;
		return false;
	}
	#undef L
	#undef R
}tr;
struct SAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[26],fa,len,ep;}t[maxn<<1];int cnt,ls,ed[maxn];
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
		for(int i=1;i<=n;i++)tr.rt[i]=tr.change(tr.rt[i-1],in[ed[i]],1);
		for(int i=1;i<=n;i++)
		{
			int now=ed[i];
			while(~now&&!t[now].ep){t[now].ep=i;now=F(now);}
		}
	}
	int f[maxn<<1];
	int faz[21][maxn<<1];
	bool judge(int u,int l,int r){return tr.judge(tr.rt[l-1],tr.rt[r],in[u],out[u]);}
	void getans(int u,int fa)
	{
		faz[0][u]=fa;
		for(int i=1;i<21;i++)faz[i][u]=faz[i-1][faz[i-1][u]];
		int lst=u;
		for(int i=20;i>=0;i--)
			if(!judge(faz[i][lst],t[u].ep-L(u)+L(faz[i][lst]),t[u].ep-1))lst=faz[i][lst];
		lst=faz[0][lst];
		if(judge(lst,t[u].ep-L(u)+L(lst),t[u].ep-1))f[u]=f[lst]+1;
		if(u)f[u]=max(f[u],1);
		for(int &i:e[u])getans(i,u);
	}
	int calc()
	{
		int ret=0;
		getans(0,0);
		for(int i=1;i<=cnt;i++)ret=max(ret,f[i]);
		return ret;
	}
	#undef S
	#undef F
	#undef L
}T;
int main()
{
	n=read();scanf("%s",s+1);
	T.init();for(int i=1;i<=n;i++)T.insert(s[i]-'a',i);T.build();
	printf("%d\n",T.calc());
	return 0;
}