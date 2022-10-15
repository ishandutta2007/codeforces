#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll read()
{
	ll ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
const int maxn=1e7;
const int maxm=5e4+5;
int n,m;
bool ans[maxm];
struct dsu
{
	int fa[maxn];
	int get(int x){return x==fa[x]?x:fa[x]=get(fa[x]);}
	void merge(int x,int y){if(!x||!y||x==y)return;fa[get(x)]=get(y);}
	bool check(int x,int y){return get(x)==get(y);}
}S;
struct trie
{
	#define S(u,i) t[u].son[i]
	struct node{int son[2];bool full;ll val,dep;}t[maxn];int cnt=1;
	int get(int u,int dep,ll val,int to=-1)
	{
		if(!u)return 0;
		if(dep==to)return u;
		if(t[u].full)return u;
		else return get(S(u,(val>>dep)&1),dep-1,val,to);
	}
	void merge(int x,int u)
	{
		if(!u)return;
		S.merge(x,u);
		if(t[u].full)return;
		if(S(u,0))merge(x,S(u,0));
		if(S(u,1))merge(x,S(u,1));
		if(t[S(u,0)].full&&t[S(u,1)].full)t[u].full=1;
	}
	void update(int u,ll val,int dep){for(int i=n-1;i>dep;i--)merge(u,get(1,n-1,val^(1ll<<i),dep));}
	void cover(int u,int dep,ll l,ll r)
	{
		t[u].dep=dep;
		if(l>r)return;
		if(t[u].full)return;
		if(r-l==(1ll<<(dep+1))-1){t[u].full=1;update(u,t[u].val,dep);return;}
		ll mid=t[u].val+(1ll<<dep);
		if(r<mid)
		{
			if(!S(u,0)){S(u,0)=++cnt;t[S(u,0)].val=t[u].val;S.fa[cnt]=cnt;}
			cover(S(u,0),dep-1,l,r);
		}
		else if(l>=mid)
		{
			if(!S(u,1)){S(u,1)=++cnt;t[S(u,1)].val=t[u].val+(1ll<<dep);S.fa[cnt]=cnt;}
			cover(S(u,1),dep-1,l,r);
		}
		else
		{
			if(!S(u,0)){S(u,0)=++cnt;t[S(u,0)].val=t[u].val;S.fa[cnt]=cnt;}
			cover(S(u,0),dep-1,l,mid-1);
			if(!S(u,1)){S(u,1)=++cnt;t[S(u,1)].val=t[u].val+(1ll<<dep);S.fa[cnt]=cnt;}
			cover(S(u,1),dep-1,mid,r);
		}
		if(t[S(u,0)].full&&t[S(u,1)].full)
		{
			S.merge(u,S(u,0));S.merge(u,S(u,1));
			t[u].full=1;
		}
	}
	bool query(ll x,ll y){x=get(1,n-1,x);y=get(1,n-1,y);
	return S.check(x,y);}
}tr;
struct operation{bool typ;ll x,y;}op[maxm];
pair<ll,ll>tmp[maxm];int cnt;
int main()
{
	n=read();m=read();
	int ls=0,lp=0;
	for(int i=1;i<=m;i++)
	{
		char opt[10];scanf("%s",opt+1);
		if(opt[1]=='b')op[i].typ=1;op[i].x=read();op[i].y=read();
		if(op[i].typ)tmp[++cnt]=make_pair(op[i].x,op[i].y);
		else ls=cnt,lp=i;
	}
	S.fa[1]=1;
	sort(tmp+1,tmp+ls+1);
	tr.cover(1,n-1,0,tmp[1].first-1);
	for(int i=1;i<=ls-1;i++)tr.cover(1,n-1,tmp[i].second+1,tmp[i+1].first-1);
	tr.cover(1,n-1,tmp[ls].second+1,(1ll<<n)-1);
	cnt=0;
	for(int i=lp;i>=1;i--)
	{
		if(op[i].typ){tr.cover(1,n-1,op[i].x,op[i].y);}
		else {ans[++cnt]=tr.query(op[i].x,op[i].y);}
	}
	for(int i=cnt;i>=1;i--)printf("%d\n",ans[i]);
	return 0;
}