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
const int maxn=1.2e5+5;
int n,p[maxn],q;
vector<pair<int,int>>ask[maxn];ll ans[maxn];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mival,minum,addtag,timtag;ll val;}t[maxn<<2];
	void build(int u=1,int l=1,int r=n)
	{
		t[u].mival=l;t[u].minum=1;
		if(l==r)return;
		int mid=(l+r)>>1;
		build(L(u),l,mid);build(R(u),mid+1,r);
	}
	void pushdown(int u)
	{
		if(t[u].addtag)
		{
			t[L(u)].mival+=t[u].addtag;t[L(u)].addtag+=t[u].addtag;
			t[R(u)].mival+=t[u].addtag;t[R(u)].addtag+=t[u].addtag;
			t[u].addtag=0;
		}
		if(t[u].timtag)
		{
			if(t[L(u)].mival==t[u].mival)
			{
				t[L(u)].val+=(ll)t[L(u)].minum*t[u].timtag;
				t[L(u)].timtag+=t[u].timtag;
			}
			if(t[R(u)].mival==t[u].mival)
			{
				t[R(u)].val+=(ll)t[R(u)].minum*t[u].timtag;
				t[R(u)].timtag+=t[u].timtag;
			}
			t[u].timtag=0;
		}
	}
	void update(int u)
	{
		t[u].mival=min(t[L(u)].mival,t[R(u)].mival);
		t[u].minum=0;
		if(t[L(u)].mival==t[u].mival)t[u].minum+=t[L(u)].minum;
		if(t[R(u)].mival==t[u].mival)t[u].minum+=t[R(u)].minum;
	}
	void change(int nl,int nr,int x,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){t[u].mival+=x;t[u].addtag+=x;return;}
		int mid=(l+r)>>1;pushdown(u);
		if(mid>=nl)change(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)change(nl,nr,x,R(u),mid+1,r);
		update(u);return;
	}
	void addtim(int nl,int nr,int x,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr){t[u].val+=(ll)t[u].minum*x;t[u].timtag+=x;return;}	
		int mid=(l+r)>>1;pushdown(u);
		if(mid>=nl)addtim(nl,nr,x,L(u),l,mid);
		if(mid+1<=nr)addtim(nl,nr,x,R(u),mid+1,r);
		update(u);return;
	}
	ll query(int nl,int nr,int u=1,int l=1,int r=n)
	{
		if(l>=nl&&r<=nr)return t[u].val;
		ll ret=0;int mid=(l+r)>>1;pushdown(u);
		if(mid>=nl)ret+=query(nl,nr,L(u),l,mid);
		if(mid+1<=nr)ret+=query(nl,nr,R(u),mid+1,r);
		return ret;
	}
	#undef L
	#undef R
}tr;
int main()
{
	generate_n(p+1,n=read(),read);
	q=read();
	for(int i=1;i<=q;i++){int l=read(),r=read();ask[r].push_back({l,i});}
	stack<int>s1,s2;
	tr.build();
	for(int i=1;i<=n;i++)
	{
		tr.change(1,n,-1);
		while(!s1.empty()&&p[s1.top()]<p[i])
		{
			int ls=s1.top(),del=p[i]-p[s1.top()];
			s1.pop();
			tr.change(s1.empty()?1:s1.top()+1,ls,del);
		}
		s1.push(i);
		while(!s2.empty()&&p[s2.top()]>p[i])
		{
			int ls=s2.top(),del=p[s2.top()]-p[i];
			s2.pop();
			tr.change(s2.empty()?1:s2.top()+1,ls,del);
		}
		s2.push(i);
		tr.addtim(1,n,1);
		for(auto &j:ask[i])ans[j.second]=tr.query(j.first,i);
	}
	for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
	return 0;
}