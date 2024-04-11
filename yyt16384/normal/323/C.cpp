#include <algorithm>
#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 1000005;

namespace util
{

void read_int(int &x)
{
	int c;
	bool flag = false;
	while (((c = getchar()) < '0' || c > '9') && c != '-')
		continue;
	if (c == '-')
	{
		flag = true;
		c = getchar();
	}
	x = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		x = x * 10 + c - '0';
	if (flag)
		x = -x;
}

}

namespace tree
{

const int MAXNDN = 25000005;

int n;

struct Node
{
	Node *lc, *rc;
	int sum;
};

Node nds[MAXNDN];
Node *newnode = nds;

Node *insert(const Node *now, int x, int v, int l = 0, int r = n)
{
	Node *p = newnode++;
	if (now)
		*p = *now;
	p->sum += v;
	if (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if (x < mid)
			p->lc = insert(p->lc, x, v, l, mid);
		else
			p->rc = insert(p->rc, x, v, mid, r);
	}
	return p;
}

int query(const Node *now, int ql, int qr, int l = 0, int r = n)
{
	if (!now)
		return 0;
	if (ql == l && qr == r)
		return now->sum;
	int mid = (l + r) >> 1;
	if (qr <= mid)
		return query(now->lc, ql, qr, l, mid);
	else if (ql >= mid)
		return query(now->rc, ql, qr, mid, r);
	else
		return query(now->lc, ql, mid, l, mid) +
			query(now->rc, mid, qr, mid, r);
}

}

int n;
int a[MAXN];
int b[MAXN];
tree::Node *root[MAXN];

void input()
{
	util::read_int(n);
	for (int i = 0; i < n; ++i)
	{
		util::read_int(a[i]);
		--a[i];
	}
	for (int i = 0; i < n; ++i)
	{
		util::read_int(b[i]);
		--b[i];
	}
}

void init()
{
	static int tmp[MAXN];
	for (int i = 0; i < n; ++i)
		tmp[a[i]] = i;
	tree::n = n;
	root[0] = NULL;
	for (int i = 0; i < n; ++i)
		root[i+1] = tree::insert(root[i], tmp[b[i]], 1);
}

void solve()
{
	int m;
	int lastans = -1;
	scanf("%d", &m);
	while (m--)
	{
		int l1, r1, l2, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
		--l1; --r1; --l2; --r2;
		l1 = (l1 + lastans + 1) % n;
		r1 = (r1 + lastans + 1) % n;
		l2 = (l2 + lastans + 1) % n;
		r2 = (r2 + lastans + 1) % n;
		if (l1 > r1)
			std::swap(l1, r1);
		if (l2 > r2)
			std::swap(l2, r2);
		++r1; ++r2;

		lastans = tree::query(root[r2], l1, r1) -
			tree::query(root[l2], l1, r1);
		printf("%d\n", lastans);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8763.in", "r", stdin);
	freopen("8763.out", "w", stdout);
#endif

	input();
	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}