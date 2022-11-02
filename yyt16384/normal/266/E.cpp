#include <cstdio>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int MAXK = 6;
const int MOD = 1000000007;

struct Data
{
	int a[MAXK];

	friend Data operator+(const Data &x, const Data &y)
	{
		Data z;
		for (int i = 0; i < MAXK; ++i)
		{
			z.a[i] = x.a[i] + y.a[i];
			if (z.a[i] >= MOD) z.a[i] -= MOD;
		}
		return z;
	}

	friend Data operator*(const Data &x, int y)
	{
		Data z;
		for (int i = 0; i < MAXK; ++i)
			z.a[i] = (long long)x.a[i] * y % MOD;
		return z;
	}

	Data& operator+=(const Data &y)
	{
		*this = *this + y;
		return *this;
	}
	Data& operator*=(int y)
	{
		*this = *this * y;
		return *this;
	}
};

struct Node
{
	Node *lc, *rc;
	int l, r;
	Data sumi, sum;
	int flag;
};

int n, m;
int a[MAXN];
int _ndn;
Node _nds[2 * MAXN];
Node *root;

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

Node *build(int l, int r)
{
	Node *now = &_nds[_ndn++];
	now->l = l;
	now->r = r;
	now->flag = -1;

	if (l + 1 == r)
	{
		now->lc = now->rc = NULL;
		int s = 1;
		for (int i = 0; i < MAXK; ++i)
		{
			now->sumi.a[i] = s;
			now->sum.a[i] = (long long)s * a[l] % MOD;
			s = (long long)s * (l + 1) % MOD;
		}
	}
	else
	{
		int mid = (l + r) >> 1;
		now->lc = build(l, mid);
		now->rc = build(mid, r);
		now->sumi = now->lc->sumi + now->rc->sumi;
		now->sum = now->lc->sum + now->rc->sum;
	}

	return now;
}

void setval(Node *x, int y)
{
	x->flag = y;
	x->sum = x->sumi * y;
}

void update_down(Node *x)
{
	if (x->flag != -1)
	{
		setval(x->lc, x->flag);
		setval(x->rc, x->flag);
		x->flag = -1;
	}
}

void update_up(Node *x)
{
	x->sum = x->lc->sum + x->rc->sum;
}

void insert(Node *now, int l, int r, int x)
{
	if (l == now->l && r == now->r)
	{
		setval(now, x);
		return;
	}

	update_down(now);
	int mid = (now->l + now->r) >> 1;
	if (r <= mid) insert(now->lc, l, r, x);
	else if (l >= mid) insert(now->rc, l, r, x);
	else insert(now->lc, l, mid, x), insert(now->rc, mid, r, x);
	update_up(now);
}

Data query(Node *now, int l, int r)
{
	if (l == now->l && r == now->r) return now->sum;

	update_down(now);
	int mid = (now->l + now->r) >> 1;
	if (r <= mid) return query(now->lc, l, r);
	else if (l >= mid) return query(now->rc, l, r);
	else return query(now->lc, l, mid) + query(now->rc, mid, r);
}

void solve()
{
	root = build(0, n);

	while (m--)
	{
		char type;
		scanf(" %c", &type);

		if (type == '=')
		{
			int l, r, x;
			scanf("%d%d%d", &l, &r, &x);
			--l;
			insert(root, l, r, x);
		}
		else if (type == '?')
		{
			int l, r, k;
			scanf("%d%d%d", &l, &r, &k);
			--l;
			Data res = query(root, l, r);

			int C[MAXK] = {1};
			for (int i = 1; i <= k; ++i)
				for (int j = i - 1; j >= 0; --j)
				{
					C[j + 1] += C[j];
					if (C[j + 1] >= MOD) C[j + 1] -= MOD;
					C[j] = (long long)C[j] * (MOD - l) % MOD;
				}

			int ans = 0;
			for (int i = 0; i <= k; ++i)
				ans = (ans + (long long)C[i] * res.a[i]) % MOD;
			printf("%d\n", ans);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("8750.in", "r", stdin);
	freopen("8750.out", "w", stdout);
#endif

	init();
	solve();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}