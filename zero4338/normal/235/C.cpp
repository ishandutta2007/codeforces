#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e6+5;
string s;
int q;
struct SAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	#define L(u) t[u].len
	struct node{int ch[26],fa,len,val;}t[maxn<<1];int ls,cnt;
	void init(){F(0)=-1;}
	void insert(int x)
	{
		int p=ls,np=ls=++cnt;t[np].val=1;
		L(np)=L(p)+1;
		for(;~p&&!S(p,x);p=F(p))S(p,x)=np;
		if(p==-1)F(np)=0;
		else
		{
			int q=S(p,x);
			if(L(q)==L(p)+1)F(np)=q;
			else
			{
				int nq=++cnt;t[nq]=t[q];t[nq].val=0;L(nq)=L(p)+1;
				F(q)=F(np)=nq;
				for(;~p&&S(p,x)==q;p=F(p))S(p,x)=nq;
			}
		}
	}
	void build()
	{
		static int in[maxn<<1];
		for(int i=1;i<=cnt;i++)in[F(i)]++;
		queue<int>q;
		for(int i=1;i<=cnt;i++)if(!in[i])q.push(i);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			if(~F(x))
			{
				t[F(x)].val+=t[x].val;
				if(!--in[F(x)])q.push(F(x));
			}
		}
	}
	bool vis[maxn<<1];
	int query(string &s)
	{
		int p=0,len=0,ret=0;
		for(int i=0;i<s.size();i++)
		{
			int now=s[i]-'a';
			while(~p&&!S(p,now))p=F(p);
			if(p==-1)p=0,len=0;
			else
			{
				len=min(len+1,L(p)+1);
				p=S(p,now);
			}
		}
		vector<int>tmp;
		if(len>=s.size()&&!vis[p])ret+=t[p].val,vis[p]=1,tmp.push_back(p);
		for(int i=0;i<s.size();i++)
		{
			int now=s[i]-'a';
			while(~p&&!S(p,now))p=F(p);
			if(p==-1)p=0,len=0;
			else
			{
				len=min(len+1,L(p)+1);
				p=S(p,now);
				while(~F(p)&&L(F(p))>=s.size())p=F(p);
				if(len>=s.size()&&!vis[p])ret+=t[p].val,vis[p]=1,tmp.push_back(p);
			}
		}
		for(int &i:tmp)vis[i]=0;
		return ret;
	}
	#undef S
	#undef F
	#undef L
}T;
int main()
{
	cin>>s;T.init();
	for(char &c:s)T.insert(c-'a');T.build();
	q=read();
	while(q--)
	{
		cin>>s;
		printf("%d\n",T.query(s));
	}
	return 0;
}