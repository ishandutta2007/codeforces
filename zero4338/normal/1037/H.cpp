#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5;
int n,q;
string s;
struct per_seg
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int ls,rs,sum;}t[maxn*20];int cnt,rt[maxn];
	int clone(int u){t[++cnt]=t[u];return cnt;}
	int change(int u,int p,int x,int l,int r)
	{
		u=clone(u);t[u].sum+=x;		
		if(l==r)return u;
		int mid=(l+r)>>1;
		if(mid>=p)L(u)=change(L(u),p,x,l,mid);
		else R(u)=change(R(u),p,x,mid+1,r);
		return u;
	}
	bool check(int u1,int u2,int nl,int nr,int l,int r)
	{
		if(l>=nl&&r<=nr)return t[u2].sum-t[u1].sum;
		int mid=(l+r)>>1;
		if(mid>=nl&&check(L(u1),L(u2),nl,nr,l,mid))return true;
		if(mid+1<=nr&&check(R(u1),R(u2),nl,nr,mid+1,r))return true;
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
				L(nq)=L(p)+1;F(np)=F(q)=nq;
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
	bool check(int l,int r,int p){return tr.check(tr.rt[l-1],tr.rt[r],in[p],out[p],1,cnt+1);}
	void query(int l,int r,string &s)
	{
		int ret=-1;char nc=0;
		int p=0;
		for(int i=0;i<=s.size();i++)
		{
			int now;
			if(i!=s.size())now=s[i];
			else now='a'-1;
			for(int j=now-'a'+1;j<26;j++)
			{
				if(S(p,j)&&check(l+i,r,S(p,j)))
				{
					ret=i;nc=j+'a';
					break;
				}
			}
			if(i==s.size())break;
			if(!S(p,s[i]-'a')||!check(l+i,r,S(p,s[i]-'a')))break;
			p=S(p,s[i]-'a');
		}
		if(ret==-1)puts("-1");
		else {for(int i=0;i<ret;i++)putchar(s[i]);putchar(nc);putchar('\n');}
	}
	#undef S
	#undef F
	#undef L
}T;
int main()
{
	cin>>s;n=s.size();
	T.init();
	for(int i=0;i<n;i++)T.insert(s[i]-'a',i+1);
	T.build();
	for(int i=1;i<=n;i++)tr.rt[i]=tr.change(tr.rt[i-1],T.in[T.ed[i]],1,1,T.cnt+1);
	q=read();
	while(q--){int l=read(),r=read();cin>>s;T.query(l,r,s);}
	return 0;
}