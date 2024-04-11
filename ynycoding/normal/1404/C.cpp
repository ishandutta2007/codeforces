#include <cstdio>
#include <vector>
#include <algorithm>
#define N 300005
int n, Q, a[N], q[N][2], id[N], ans[N];
bool cmp(int a, int b) { return q[a][1]<q[b][1]; }
namespace SGT{
	#define lid (id<<1)
	#define rid (id<<1|1)
	int mx[N<<2], tag[N<<2];
	void add(int id, int v) { mx[id]+=v, tag[id]+=v; }
	void pushdown(int id) { add(lid, tag[id]), add(rid, tag[id]), tag[id]=0; }
	void insert(int id, int l, int r, int p, int v)
	{
		if(l==r) { if(mx[id]>=v) add(id, 1); return; }
		pushdown(id);
		int mid=(l+r)>>1;
		if(mx[rid]<v||p<=mid) insert(lid, l, mid, p, v);
		else add(lid, 1), insert(rid, mid+1, r, p, v);	
		mx[id]=std::max(mx[lid], mx[rid]);	
	}
	int query(int id, int l, int r, int p)
	{
		if(l==r) return mx[id];
		pushdown(id);
		int mid=(l+r)>>1;
		if(p<=mid) return query(lid, l, mid, p);
		return query(rid, mid+1, r, p);
	}
}
using namespace SGT;
int main()
{
	scanf("%d%d", &n, &Q);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), a[i]=i-a[i];
	for(int i=1; i<=Q; ++i) scanf("%d%d", q[i], q[i]+1), q[i][1]=n+1-q[i][1], id[i]=i;
	std::sort(id+1, id+Q+1, cmp);
	for(int i=1, j=1; i<=Q; ++i)
	{
		int x=id[i];
		while(j<q[x][1]) (a[j]>=0?insert(1, 1, n, j, a[j]), 0:0), ++j;
		ans[x]=query(1, 1, n, q[x][0]+1);
	}
	for(int i=1; i<=Q; ++i) printf("%d\n", ans[i]);
	return 0;
}