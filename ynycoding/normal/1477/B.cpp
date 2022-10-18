#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long
const int N=200005;
int T, n, q, l[N], r[N];
char s[N], t[N];
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int sum[N<<2], tag[N<<2], len[N<<2];//1:0->1 2:1->0
	inline void upt(int id)
	{
		sum[id]=sum[lid]+sum[rid];
	}
	inline void put(int id, int t)
	{
		if(t==1) sum[id]=len[id];
		if(t==2) sum[id]=0;
		tag[id]=t;
	}
	inline void pushdown(int id)
	{
		if(tag[id])
		{
			put(lid, tag[id]);
			put(rid, tag[id]);
			tag[id]=0;
		}
	}
	void build(int id, int l, int r)
	{
		len[id]=r-l+1;
		tag[id]=0;
		if(l==r)
		{
			sum[id]=t[l]-'0';
			return;
		}
		int mid=(l+r)>>1;
		build(lid, l, mid);
		build(rid, mid+1, r);
		upt(id);
	}
	void add(int id, int l, int r, int l1, int r1, int v)
	{
		if(l1<=l&&r<=r1) { put(id, v); return; }
		pushdown(id);
		int mid=(l+r)>>1;
		if(l1<=mid) add(lid, l, mid, l1, r1, v);
		if(r1>mid) add(rid, mid+1, r, l1, r1, v);
		upt(id);
	}
	int ask(int id, int l, int r, int l1, int r1)
	{
		if(l1<=l&&r<=r1) return sum[id];
		pushdown(id);
		int mid=(l+r)>>1;
		int ret=0;
		if(l1<=mid) ret+=ask(lid, l, mid, l1, r1);
		if(r1>mid) ret+=ask(rid, mid+1, r, l1, r1);
		return ret;
	}
	void dfs(int id, int l, int r)
	{
		if(l==r) { t[l]=sum[id]+'0'; return; }
		pushdown(id);
		int mid=(l+r)>>1;
		dfs(lid, l, mid);
		dfs(rid, mid+1, r);
	}
}
using namespace SGT;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &q);
		scanf("%s%s", s+1, t+1);
		for(int i=1; i<=q; ++i) scanf("%d%d", l+i, r+i);
		build(1, 1, n);
		for(int i=q; i; --i)
		{
			int x=l[i], y=r[i], len=y-x+1;
			int v=ask(1, 1, n, x, y);
			if(v*2<len) add(1, 1, n, x, y, 2);
			else if(v*2>len) add(1, 1, n, x, y, 1);
			else goto out;
		}
		dfs(1, 1, n);
		if(memcmp(s+1, t+1, n))
		{
			out:;
			puts("NO");
		}
		else puts("YES");
	}
	return 0;
}