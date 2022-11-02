#include <cstdio>
#include <utility>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 200005;
const int MOD = 1000000000;

struct Node
{
	Node *lc, *rc;
	int flag;
	int sumf1; // sum(fib[n])
	int sumf2; // sum(fib[n+1])
	int suma1; // sum(fib[n] * a[n])
	int suma2; // sum(fib[n+1] * a[n])

	void update_down();
	void update_up();
}nds[2*MAXN];
Node *newnode = nds;

void Node::update_down()
{
	if (flag)
	{
		lc->suma1 = (lc->suma1 + (long long)flag * lc->sumf1) % MOD;
		lc->suma2 = (lc->suma2 + (long long)flag * lc->sumf2) % MOD;
		lc->flag = (lc->flag + flag) % MOD;
		rc->suma1 = (rc->suma1 + (long long)flag * rc->sumf1) % MOD;
		rc->suma2 = (rc->suma2 + (long long)flag * rc->sumf2) % MOD;
		rc->flag = (rc->flag + flag) % MOD;
		flag = 0;
	}
}

void Node::update_up()
{
	suma1 = (lc->suma1 + rc->suma1) % MOD;
	suma2 = (lc->suma2 + rc->suma2) % MOD;
}

int n, q;
int a[MAXN];
int _fib[MAXN];
int *fib = _fib + 1;
Node *root;

Node *build(int l = 0, int r = n)
{
	Node *now = newnode++;
	now->flag = 0;
	if (l + 1 == r)
	{
		now->lc = now->rc = NULL;
		now->sumf1 = fib[l];
		now->sumf2 = fib[l+1];
		now->suma1 = (long long)fib[l] * a[l] % MOD;
		now->suma2 = (long long)fib[l+1] * a[l] % MOD;
	}
	else
	{
		int mid = (l + r) >> 1;
		now->lc = build(l, mid);
		now->rc = build(mid, r);
		now->sumf1 = (now->lc->sumf1 + now->rc->sumf1) % MOD;
		now->sumf2 = (now->lc->sumf2 + now->rc->sumf2) % MOD;
		now->update_up();
	}
	return now;
}

void init()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	fib[-1] = 1; fib[0] = 0;
	for (int i = 1; i <= n; ++i)
		fib[i] = (fib[i-1] + fib[i-2]) % MOD;
	root = build();
}

void insert(int x, int y, Node *now = root, int l = 0, int r = n)
{
	if (l + 1 == r)
	{
		now->suma1 = (long long)now->sumf1 * y % MOD;
		now->suma2 = (long long)now->sumf2 * y % MOD;
		return;
	}

	now->update_down();
	int mid = (l + r) >> 1;
	if (x < mid) insert(x, y, now->lc, l, mid);
	else insert(x, y, now->rc, mid, r);
	now->update_up();
}

void add(int ql, int qr, int v, Node *now = root, int l = 0, int r = n)
{
	if (ql == l && qr == r)
	{
		now->flag = (now->flag + v) % MOD;
		now->suma1 = (now->suma1 + (long long)now->sumf1 * v) % MOD;
		now->suma2 = (now->suma2 + (long long)now->sumf2 * v) % MOD;
		return;
	}

	now->update_down();
	int mid = (l + r) >> 1;
	if (qr <= mid) add(ql, qr, v, now->lc, l, mid);
	else if (ql >= mid) add(ql, qr, v, now->rc, mid, r);
	else
	{
		add(ql, mid, v, now->lc, l, mid);
		add(mid, qr, v, now->rc, mid, r);
	}
	now->update_up();
}

std::pair<int, int> query(int ql, int qr, Node *now = root, int l = 0, int r = n)
{
	if (ql == l && qr == r)
		return std::make_pair(now->suma1, now->suma2);

	now->update_down();
	int mid = (l + r) >> 1;
	if (qr <= mid) return query(ql, qr, now->lc, l, mid);
	else if (ql >= mid) return query(ql, qr, now->rc, mid, r);
	else
	{
		std::pair<int, int> tmpl = query(ql, mid, now->lc, l, mid);
		std::pair<int, int> tmpr = query(mid, qr, now->rc, mid, r);
		return std::make_pair((tmpl.first + tmpr.first) % MOD, (tmpl.second + tmpr.second) % MOD);
	}
}

void solve()
{
	while (q--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			--x;
			insert(x, y);
		}
		else if (type == 2)
		{
			int l, r;
			scanf("%d%d", &l, &r);
			--l;
			std::pair<int, int> ss = query(l, r);
			int part1 = (long long)fib[l-1] * ss.second % MOD;
			int part2 = (long long)fib[l] * ss.first % MOD;
			int ans = (part1 - part2 + MOD) % MOD;
			if (l % 2) ans = (MOD - ans) % MOD;
			printf("%d\n", ans);
		}
		else if (type == 3)
		{
			int l, r, d;
			scanf("%d%d%d", &l, &r, &d);
			--l;
			add(l, r, d);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9180.in", "r", stdin);
	freopen("9180.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}