#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5,maxm=500;
string s;int q,sqr;
struct SAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[26],fa,len,val;}t[maxm<<1];int cnt,ls;
	void clear(node &a){memset(a.ch,0,sizeof a.ch);a.fa=0;a.len=0;a.val=0;}
	void insert(int x)
	{
		int p=ls,np=ls=++cnt;clear(t[cnt]);t[cnt].val=1;
		L(np)=L(p)+1;
		for(;~p&&!S(p,x);p=F(p))S(p,x)=np;
		if(p==-1)F(np)=0;
		else
		{
			int q=S(p,x);
			if(L(q)==L(p)+1)F(np)=q;
			else
			{
				int nq=++cnt;t[nq]=t[q];t[nq].val=0;
				L(nq)=L(p)+1;F(q)=F(np)=nq;
				for(;~p&&S(p,x)==q;p=F(p))S(p,x)=nq;
			}
		}
	}
	void build(const string &s)
	{
		cnt=0;ls=0;clear(t[0]);F(0)=-1;
		for(const char &c:s)insert(c-'a');
		vector<vector<int>>e(cnt+1);
		for(int i=1;i<=cnt;i++)e[F(i)].push_back(i);
		function<void(int)>dfs=[&](int u){for(int &i:e[u])dfs(i),t[u].val+=t[i].val;};
		dfs(0);
	}
	int query(const string &s)
	{
		int ret=0;
		for(const char &c:s){if(!S(ret,c-'a'))return 0;ret=S(ret,c-'a');}
		return t[ret].val;
	}
	#undef S
	#undef F
	#undef L
}T[maxm];
int calc(const string &s,const string &t)
{
	int ret=0;
	static int nxt[maxn];
	nxt[0]=-1;
	for(int i=1,j=-1;i<t.size();i++)
	{
		while(j>=0&&t[j+1]!=t[i])j=nxt[j];
		if(t[j+1]==t[i])j++;
		nxt[i]=j;
	}
	for(int i=0,j=-1;i<s.size();i++)
	{
		while(j>=0&&(j==t.size()-1||t[j+1]!=s[i]))j=nxt[j];
		if(t[j+1]==s[i])j++;
		if(j==t.size()-1)ret++;
	}
	return ret;
}
int main()
{
	cin>>s;
	sqr=200;
	for(int i=0;i*sqr<s.size();i++)T[i].build(s.substr(i*sqr,sqr));
	q=read();
	while(q--)
	{
		int typ=read();
		if(typ==1)
		{
			int p=read()-1;cin>>s[p];
			T[p/sqr].build(s.substr((p/sqr)*sqr,sqr));
		}
		else
		{
			int l=read()-1,r=read()-1;string t;cin>>t;
			if(t.size()>sqr||l/sqr==r/sqr)printf("%d\n",calc(s.substr(l,r-l+1),t));
			else
			{
				int ret=0;
				for(int i=l/sqr+1;i<r/sqr;i++)ret+=T[i].query(t);
				ret+=calc(s.substr(l,(l/sqr+1)*sqr-l),t);
				ret+=calc(s.substr((r/sqr)*sqr,r-(r/sqr)*sqr+1),t);
				if(t.size()>1)
					for(int i=l/sqr;i<r/sqr;i++)
					{
						string now;
						int nl=0,nr=(i+1)*sqr-1;
						nl=nr-t.size()+2;nl=max(nl,l);
						now+=s.substr(nl,nr-nl+1);
						nl=(i+1)*sqr;nr=nl+t.size()-2;
						nr=min(nr,r);
						now+=s.substr(nl,nr-nl+1);
						ret+=calc(now,t);
					}
				printf("%d\n",ret);
			}
		}
	}
	return 0;
}