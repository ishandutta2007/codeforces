#include<bits/stdc++.h>
typedef unsigned int ui;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
mt19937 rnd(0);
const int maxn=2e5+5;
int n,k;
pair<int,int>p[maxn];
int ans[maxn];
struct fhq_treap
{
	#define L(u) t[u].ls
	#define R(u) t[u].rs
	struct node{int ls,rs,val,cnt,id,tag1,tag2;ui rval;}t[maxn];int cnt,rt;// tag 1 val tag2 cnt
	int newnode(int val,int id){t[++cnt].val=val;t[cnt].id=id;t[cnt].rval=rnd();return cnt;}
	void pushdown(int u)
	{
		if(t[u].tag1)
		{
			t[L(u)].val+=t[u].tag1;
			t[L(u)].tag1+=t[u].tag1;
			t[R(u)].val+=t[u].tag1;
			t[R(u)].tag1+=t[u].tag1;
			t[u].tag1=0;
		}
		if(t[u].tag2)
		{
			t[L(u)].cnt+=t[u].tag2;
			t[L(u)].tag2+=t[u].tag2;
			t[R(u)].cnt+=t[u].tag2;
			t[R(u)].tag2+=t[u].tag2;
			t[u].tag2=0;
		}
	}
	void split(int u,int val,int &x,int &y)
	{
		if(!u)x=y=0;
		else
		{
			pushdown(u);
			if(t[u].val<=val)x=u,split(R(u),val,R(u),y);
			else y=u,split(L(u),val,x,L(u));
		}
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x|y;pushdown(x);pushdown(y);
		if(t[x].rval<t[y].rval){R(x)=merge(R(x),y);return x;}
		else {L(y)=merge(x,L(y));return y;}
	}
	void insert(int &u,int val,int id)
	{
		int l,r;split(u,val,l,r);
		u=merge(merge(l,newnode(val,id)),r);
	}
	void insert(int &u,int num)
	{
		int l,r;split(u,t[num].val,l,r);
		u=merge(merge(l,num),r);
	}
	void dfs(int u,vector<int>&ret)
	{
		ret.push_back(u);
		pushdown(u);
		if(L(u))dfs(L(u),ret);
		if(R(u))dfs(R(u),ret);
	}
	void calc(int val)
	{
		int x,y,z;
		split(rt,val-1,x,y);
		split(y,2*val-1,y,z);
		vector<int>p;dfs(y,p);
		for(int &i:p)
		{
			t[i].cnt++;t[i].val-=val;L(i)=R(i)=0;
			insert(x,i);
		}
		t[z].tag1-=val;t[z].tag2++;t[z].val-=val;t[z].cnt++;
		rt=merge(x,z);
	}
	void getans(int u)
	{
		ans[t[u].id]=t[u].cnt;
		pushdown(u);
		if(L(u))getans(L(u));
		if(R(u))getans(R(u));
	}
}tr;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)p[i].first=read(),p[i].second=read();
	k=read();for(int i=1;i<=k;i++)tr.insert(tr.rt,read(),i);
	sort(p+1,p+n+1,[](pair<int,int>&i,pair<int,int>&j){return (i.second!=j.second)?i.second>j.second:i.first<j.first;});
	for(int i=1;i<=n;i++)tr.calc(p[i].first);
	tr.getans(tr.rt);
	for(int i=1;i<=k;i++)printf("%d ",ans[i]);putchar('\n');
	return 0;
}