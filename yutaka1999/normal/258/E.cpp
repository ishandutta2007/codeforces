#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define BT 128*1024*2
#define INF 1000000000

using namespace std;

struct P
{
	int mn,cnt;
	P(int mn=0,int cnt=0):mn(mn),cnt(cnt){}
};
P unite(P p,P q)
{
	P ret;
	ret.mn=min(p.mn,q.mn);
	if(ret.mn==p.mn) ret.cnt+=p.cnt;
	if(ret.mn==q.mn) ret.cnt+=q.cnt;
	return ret;
}
struct segtree
{
	P seg[BT];
	int add[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		memset(add,0,sizeof(add));
		for(int i=mum-1;i<mum+n-1;i++) seg[i]=P(0,1);
		for(int i=mum+n-1;i<mum*2;i++) seg[i]=P(INF,1);
		for(int i=mum-2;i>=0;i--) make(i);
	}
	void make(int k)
	{
		seg[k]=unite(seg[k*2+1],seg[k*2+2]);
		seg[k].mn+=add[k];
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b)
		{
			seg[k].mn+=v;
			add[k]+=v;
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
			make(k);
		}
	}
	void update(int a,int b,int v)
	{
		update(a,b,0,0,mum,v);
	}
	int get()
	{
		if(seg[0].mn!=0) return 0;
		return seg[0].cnt;
	}
};
segtree seg;
vector <int> vec[SIZE];
vector <int> add[SIZE];
int id[SIZE],ch[SIZE];
int ans[SIZE],cnt[SIZE];
int nw;

void dfs(int v=0,int p=-1)
{
	id[v]=nw++;
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) dfs(to,v);
	}
	ch[v]=nw;
}
void solve(int v=0,int p=-1)
{
	for(int i=0;i<add[v].size();i++)
	{
		int to=add[v][i];
		if(cnt[v]==0) seg.update(id[v],ch[v],1);
		if(cnt[to]==0) seg.update(id[to],ch[to],1);
		cnt[v]++;cnt[to]++;
	}
	ans[v]=seg.get();
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p) solve(to,v);
	}
	for(int i=0;i<add[v].size();i++)
	{
		int to=add[v][i];
		cnt[v]--;cnt[to]--;
		if(cnt[v]==0) seg.update(id[v],ch[v],-1);
		if(cnt[to]==0) seg.update(id[to],ch[to],-1);
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	for(int i=0;i<m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		add[a].push_back(b);
		add[b].push_back(a);
	}
	dfs();
	seg.init(n);
	solve();
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		ans[i]=n-ans[i];
		printf("%d",max(0,ans[i]-1));
	}puts("");
	return 0;
}