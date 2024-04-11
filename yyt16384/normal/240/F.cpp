#include <cstdio>
#include <cstring>

#ifdef _WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

const int MAXN = 100005;
const int SZ = 26;

namespace segment_tree
{

const int MAXN = 270005;

struct SegTree
{
	int sum[MAXN][SZ];
	int flag[MAXN];
	int ll, rr;

	void build(int l, int r)
	{
		ll = l;
		rr = r;
		memset(flag, -1, sizeof(flag));
	}

	void setval(int now, int l, int r, int x)
	{
		memset(sum[now], 0, SZ * sizeof(sum[now][0]));
		sum[now][x] = r - l;
		flag[now] = x;
	}

	void insert(int ql, int qr, int x, int now, int l, int r)
	{
		if (ql == l && qr == r)
		{
			setval(now, l, r, x);
			return;
		}
		int mid = (l + r) >> 1;
		if (flag[now] != -1)
		{
			setval(now * 2 + 1, l, mid, flag[now]);
			setval(now * 2 + 2, mid, r, flag[now]);
			flag[now] = -1;
		}
		if (qr <= mid)
			insert(ql, qr, x, now * 2 + 1, l, mid);
		else if (ql >= mid)
			insert(ql, qr, x, now * 2 + 2, mid, r);
		else
		{
			insert(ql, mid, x, now * 2 + 1, l, mid);
			insert(mid, qr, x, now * 2 + 2, mid, r);
		}
		for (int i = 0; i < SZ; ++i)
			sum[now][i] = sum[now * 2 + 1][i] + sum[now * 2 + 2][i];
	}

	void insert(int l, int r, int x)
	{
		insert(l, r, x, 0, ll, rr);
	}

	int getsum(int ql, int qr, int x, int now, int l, int r)
	{
		if (ql == l && qr == r)
			return sum[now][x];
		if (flag[now] == x)
			return qr - ql;
		if (flag[now] >= 0)
			return 0;
		int mid = (l + r) >> 1;
		if (qr <= mid)
			return getsum(ql, qr, x, now * 2 + 1, l, mid);
		else if (ql >= mid)
			return getsum(ql, qr, x, now * 2 + 2, mid, r);
		else
			return getsum(ql, mid, x, now * 2 + 1, l, mid) + getsum(mid, qr, x, now * 2 + 2, mid, r);
	}

	int getsum(int l, int r, int x)
	{
		return getsum(l, r, x, 0, ll, rr);
	}

	void print_ans(int now, int l, int r) const
	{
		if (flag[now] != -1)
		{
			for (int i = l; i < r; ++i)
				putchar(flag[now] + 'a');
			return;
		}
		int mid = (l + r) >> 1;
		print_ans(now * 2 + 1, l, mid);
		print_ans(now * 2 + 2, mid, r);
	}

	void print_ans() const
	{
		print_ans(0, ll, rr);
	}
};

}

using segment_tree::SegTree;

int n, m;
SegTree tr;

void init()
{
	static char s[MAXN];
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	for (int i = 0; i < SZ; ++i)
		tr.build(0, n);
	for (int i = 0; i < n; ++i)
	{
		int x = s[i] - 'a';
		tr.insert(i, i + 1, x);
	}
}

void solve()
{
	while (m--)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		int cnt = 0;
		int oddx;
		int sum[SZ];
		for (int i = 0; i < SZ; ++i)
		{
			sum[i] = tr.getsum(l, r, i);
			if (sum[i] % 2)
			{
				++cnt;
				oddx = i;
			}
			sum[i] /= 2;
		}
		if (cnt > 1)
			continue;
		for (int i = 0, nowp = 0; i < SZ; ++i)
			if (sum[i])
			{
				tr.insert(l + nowp, l + nowp + sum[i], i);
				tr.insert(r - nowp - sum[i], r - nowp, i);
				nowp += sum[i];
			}
		if (cnt)
			tr.insert((l + r) / 2, (l + r + 1) / 2, oddx);
	}
}

void output()
{
	tr.print_ans();
	putchar('\n');
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("9159.in", "r", stdin);
	freopen("9159.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();
	solve();
	output();

#ifndef ONLINE_JUDGE
	fclose(stdin); fclose(stdout);
#endif
	return 0;
}