#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define lson (rt<<1)
#define rson (rt<<1|1)
#define mid ((l+r)>>1)

using namespace std;

typedef long long LL;

const int MAXN=200005;

struct node
{
	int cnt, d;
};

node tree[MAXN*4];
int A[MAXN], B[MAXN];
int N, M;

inline void pushdown(int rt)
{
	tree[lson].d+=tree[rt].d; tree[lson].cnt+=tree[rt].d;
	tree[rson].d+=tree[rt].d; tree[rson].cnt+=tree[rt].d;
	tree[rt].d=0;
}

inline void update(int rt)
{
	if (tree[lson].cnt==tree[rson].cnt) tree[rt].cnt=tree[lson].cnt;
	else tree[rt].cnt=0;
}

void modify(int rt, int l, int r, int ll, int rr)
{
	if (ll<=l&&rr>=r)
	{
		tree[rt].cnt++; tree[rt].d++;
		return;
	}
	if (tree[rt].d) pushdown(rt);
	if (ll<=mid) modify(lson, l, mid, ll, rr);
	if (rr>mid) modify(rson, mid+1, r, ll, rr);
	update(rt);
}

void query(int rt, int l, int r)
{
	if (l==r)
	{
		B[l]=tree[rt].cnt;
		return;
	}
	if (tree[rt].d) pushdown(rt);
	query(lson, l, mid); query(rson, mid+1, r);
}

int main()
{
	scanf("%d%d", &N, &M);
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	memset(tree, 0, sizeof(tree));
	for (int i=1; i<=N; i++)
		scanf("%d", &A[i]);
	while (M--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		modify(1, 1, N, l, r);
	}
	query(1, 1, N);
	sort(A+1, A+1+N); sort(B+1, B+1+N);
	LL ret=0;
	for (int i=1; i<=N; i++)
		ret+=(LL)A[i]*B[i];
	cout << ret << endl;
	return 0;
}