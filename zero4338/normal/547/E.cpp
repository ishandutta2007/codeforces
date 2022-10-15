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
int n,q;
string s[maxn];int ed[maxn];
struct fenwick
{
	int b[maxn],n;
	void init(int _n){n=_n;}
	void add(int p){for(int i=p;i<=n;i+=i&(-i))b[i]++;}
	int query(int p){int ret=0;for(int i=p;i;i-=i&(-i))ret+=b[i];return ret;}
	int query(int l,int r){return query(r)-query(l-1);}
};
struct ACAM
{
	#define S(u,i) t[u].ch[i]
	#define F(u) t[u].fa
	struct node{int ch[26],fa,in,out;}t[maxn];int cnt,tim;fenwick tr;
	int insert(string &s)
	{
		int now=0;
		for(char &c:s)
		{
			if(!S(now,c-'a'))S(now,c-'a')=++cnt;
			now=S(now,c-'a');
		}
		return now;
	}
	void build()
	{
		queue<int>q;
		q.push(0);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=0;i<26;i++)
			{
				if(S(x,i))
				{
					if(x)F(S(x,i))=S(F(x),i);
					q.push(S(x,i));
				}
				else S(x,i)=S(F(x),i);
			}
		}
		vector<vector<int>>e(cnt+1);
		for(int i=1;i<=cnt;i++)e[F(i)].push_back(i);
		function<void(int)>dfs=[&](int u){t[u].in=++tim;for(int &i:e[u])dfs(i);t[u].out=tim;};
		dfs(0);
		tr.init(tim);
	}
	void add(string &s)
	{
		int now=0;
		for(char &c:s){now=S(now,c-'a');tr.add(t[now].in);}
	}
	int query(int u){return tr.query(t[u].in,t[u].out);}
	#undef S
	#undef F
}T;
vector<tuple<int,int,bool>>ask[maxn];
int ans[maxn];
int main()
{
	n=read();q=read();
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)ed[i]=T.insert(s[i]);
	T.build();
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read(),p=read();
		ask[l-1].push_back({i,ed[p],1});
		ask[r].push_back({i,ed[p],0});
	}
	for(int i=1;i<=n;i++)
	{
		T.add(s[i]);
		for(auto&[id,p,typ]:ask[i])ans[id]+=(typ?-1:1)*T.query(p);
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}