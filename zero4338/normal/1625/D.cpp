#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e5+5;
int n,k;
int a[maxn];
vector<int>ans;
int haji;
struct trie
{
	static const int maxn=9e6+5;
	#define S(u,i) t[u].son[i]
	struct node{int son[2];vector<int>id;int exi;}t[maxn];int cnt;
	void insert(int x,int id)
	{
		int u=0;
		for(int i=30;i>=0;i--)
		{
			int now=(x>>i)&1;
			if(!S(u,now))S(u,now)=++cnt,t[cnt].exi=id;
			u=S(u,now);
			if(i==haji)t[u].id.push_back(id);
		}
	}
	pair<int,int>query(int u,int dep,int x)
	{
		if(dep==-1)return {0,t[u].exi};
		int now=(x>>dep)&1;
		if(S(u,!now))
		{
			pair<int,int>ret=query(S(u,!now),dep-1,x);ret.first|=(1<<dep);
			return ret;
		}
		else return query(S(u,now),dep-1,x);
	}
	void dfs(int u,int dep)
	{
		if(dep==haji)
		{
			if(S(u,0))assert(t[S(u,0)].id.size());
			if(S(u,1))assert(t[S(u,1)].id.size());
			if(!S(u,0)||!S(u,1))
			{
				if(S(u,0))ans.push_back(t[S(u,0)].id[0]);
				else ans.push_back(t[S(u,1)].id[0]);
				return;
			}
			for(int &i:t[S(u,1)].id)
			{
				pair<int,int>now=query(u,dep,a[i]);
				if(now.first>=k)
				{
					ans.push_back(now.second);
					ans.push_back(i);
					return;
				}
			}
			ans.push_back(t[S(u,0)].id[0]);
			return;
		}
		if(S(u,0))dfs(S(u,0),dep-1);
		if(S(u,1))dfs(S(u,1),dep-1);
	}
}tr;
int main()
{
	n=read();k=read();
	generate_n(a+1,n,read);
	if(k==0)
	{
		printf("%d\n",n);
		for(int i=1;i<=n;i++)printf("%d ",i);putchar('\n');
		return 0;
	}
	for(int i=30;i>=0;i--)if((k>>i)&1){haji=i;break;}
	for(int i=1;i<=n;i++)tr.insert(a[i],i);
	tr.dfs(0,30);
	if(ans.size()==1)puts("-1");
	else
	{
		printf("%lu\n",ans.size());
		for(int &i:ans)printf("%d ",i);putchar('\n');
	}
	return 0;
}