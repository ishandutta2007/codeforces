#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=1e5+5,maxm=3e5+5;
int n,m,a[maxn],num[maxn],cnt;
vector<pair<int,int>>ask[maxn];
int ans[maxm];
struct segment
{
	#define L(u) u<<1
	#define R(u) u<<1|1
	struct node{int mx;}t[maxn<<2];
	void change(int p,int x,int u=1,int l=1,int r=cnt)
	{
		if(l==r){t[u].mx=x;return;}
		int mid=(l+r)>>1;
		if(mid>=p)change(p,x,L(u),l,mid);
		else change(p,x,R(u),mid+1,r);
		t[u].mx=max(t[L(u)].mx,t[R(u)].mx);
	}
	int query(int nl,int nr,int u=1,int l=1,int r=cnt)
	{
		if(l>=nl&&r<=nr)return t[u].mx;
		int mid=(l+r)>>1,ret=0;
		if(mid>=nl)ret=max(ret,query(nl,nr,L(u),l,mid));
		if(mid+1<=nr)ret=max(ret,query(nl,nr,R(u),mid+1,r));
		return ret;
	}
	#undef L
	#undef R
}tr0;
struct fenwick
{
	int b[maxn];
	fenwick(){memset(b,0x3f,sizeof b);}
	void change(int p,int x){for(int i=p;i;i-=i&(-i))b[i]=min(b[i],x);}
	int query(int p)
	{
		int ret=1e9;
		for(int i=p;i<=n;i+=i&(-i))ret=min(ret,b[i]);
		return ret;
	}
}tr1;
int main()
{
	generate_n(a+1,n=read(),read);
	m=read();for(int i=1;i<=m;i++){int l=read(),r=read();ask[r].push_back({l,i});}
	memcpy(num,a,sizeof(int)*(n+1));cnt=n;
	sort(num+1,num+cnt+1);cnt=unique(num+1,num+cnt+1)-(num+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(num+1,num+cnt+1,a[i])-num;
	for(int i=1;i<=n;i++)
	{
		int del=1e9;
		while(true)
		{
			int pos=tr0.query(a[i],upper_bound(num+1,num+cnt+1,num[a[i]]+del)-num-1);
			if(pos==0)break;
			tr1.change(pos,num[a[pos]]-num[a[i]]);
			if(!del)break;
			del=(num[a[pos]]-num[a[i]])/2;
		}
		del=1e9;
		while(true)
		{
			int pos=tr0.query(lower_bound(num+1,num+cnt+1,num[a[i]]-del)-num,a[i]);
			if(pos==0)break;
			tr1.change(pos,num[a[i]]-num[a[pos]]);
			if(!del)break;
			del=(num[a[i]]-num[a[pos]])/2;
		}
		for(auto &j:ask[i])ans[j.second]=tr1.query(j.first);
		tr0.change(a[i],i);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}