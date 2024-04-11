#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1.5e5+5;
int n,m,p,a[maxn];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{vector<pair<int,int>>v;int tag;}t[maxn<<2];
	vector<pair<int,int>>merge(const vector<pair<int,int>>&a,const vector<pair<int,int>>&b)
	{
		vector<pair<int,int>>ret;
		ret=a;
		for(auto &i:b)
		{
			bool flag=false;
			for(auto &j:ret)
				if(i.second==j.second){j.first+=i.first;flag=true;break;}
			if(!flag)ret.push_back(i);
		}
		sort(ret.begin(),ret.end());
		if(ret.size()>=100/p+1)
		{
			for(int i=ret.size()-100/p;i<ret.size();i++)ret[i].first-=ret[ret.size()-100/p-1].first;
			ret.erase(ret.begin(),ret.begin()+ret.size()-100/p);
		}
		return ret;
	}
	void pushdown(int u,int l,int r)
	{
		if(t[u].tag)
		{
			int mid=(l+r)>>1;
			t[L(u)].tag=t[R(u)].tag=t[u].tag;
			t[L(u)].v={{mid-l+1,t[u].tag}};t[R(u)].v={{r-mid,t[u].tag}};
			t[u].tag=0;
		}
	}
	void build(int u=1,int l=1,int r=n)
	{
		if(l==r){t[u].v={{1,a[l]}};return;}
		int mid=(l+r)>>1;
		build(L(u),l,mid);build(R(u),mid+1,r);
		t[u].v=merge(t[L(u)].v,t[R(u)].v);
	}
	
	void change(int nl,int nr,int x,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){t[u].tag=x;t[u].v={{r-l+1,x}};return;}
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(mid>=nl)change(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)change(nl,nr,x,R(u),mid+1,r);
		t[u].v=merge(t[L(u)].v,t[R(u)].v);
	}
	vector<pair<int,int>>query(int nl,int nr,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr)return t[u].v;
		pushdown(u,l,r);
		int mid=(l+r)>>1;
		if(mid>=nr)return query(nl,nr,L(u),l,mid);
		if(mid+1<=nl)return query(nl,nr,R(u),mid+1,r);
		return merge(query(nl,nr,L(u),l,mid),query(nl,nr,R(u),mid+1,r));
		
	}
	#undef L
	#undef R
}tr;
int main()
{
	n=read();m=read();p=read();generate_n(a+1,n,read);
	tr.build();
	while(m--)
	{
		int opt=read(),l=read(),r=read();
		if(opt==1)tr.change(l,r,read());
		else
		{
			vector<pair<int,int>>ans=tr.query(l,r);
			printf("%lu ",ans.size());
			for(auto &i:ans)printf("%d ",i.second);
			putchar('\n');
		}
	}
	return 0;
}