#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5, maxq = 1e6 + maxn, logn = 20;
int n, m, q, len[maxn + 3], pos[maxn + 3];
int sz, sa[maxn + 3], rnk[maxn + 3], cnt[maxn + 3], k_1[maxn + 3], k_2[maxn + 3], hei[maxn + 3];
int h[logn + 3][maxn + 3], lft[maxn + 3], rht[maxn + 3], tot, bit[maxn + 3], ans[maxq + 3];
char s[maxn + 3], t[maxn + 3];

struct event {
	int t, x, y, i, l, r;
	friend bool operator < (const event &a, const event &b) {
		return a.x == b.x ? a.t < b.t : a.x < b.x;
	}
} ev[maxq + 3];

void r_sort(int a[], int b[], int k[], int n) {
	fill(cnt + 1, cnt + sz + 1, 0);
	for (int i = 1; i <= n; i++) cnt[k[i]]++;
	for (int i = 2; i <= sz; i++) cnt[i] += cnt[i - 1];
	for (int i = n; i; i--) b[cnt[k[a[i]]]--] = a[i];
}

void make(char s[], int n) {
	sz = max(n + 1, 27);
	for (int i = 1; i <= n; i++) rnk[i] = s[i] - 'a' + 1, k_1[i] = i;
	r_sort(k_1, sa, rnk, n);
	for (int i = 1; i <= n; i++) rnk[sa[i]] = rnk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
	for (int k = 1; k < n; k <<= 1) {
		fill(k_1 + 1, k_1 + n + 1, 1);
		for (int i = 1; i <= n - k; i++) k_1[i] = rnk[i + k] + 1;
		for (int i = 1; i <= n; i++) k_2[i] = rnk[i], sa[i] = i;
		r_sort(sa, rnk, k_1, n), r_sort(rnk, sa, k_2, n);
		for (int i = 1; i <= n; i++) {
			bool f = k_1[sa[i]] == k_1[sa[i - 1]] && k_2[sa[i]] == k_2[sa[i - 1]];
			rnk[sa[i]] = f ? rnk[sa[i - 1]] : rnk[sa[i - 1]] + 1;
		}
		if (rnk[sa[n]] == n) break;
	}
	s[n + 1] = 0;
	for (int i = 1, j, k = 0; i <= n; hei[rnk[i++] - 1] = k) {
		for (k = max(0, k - 1), j = sa[rnk[i] - 1]; s[i + k] == s[j + k]; k++);
	}
	for (int i = 1; i <= n - 1; i++) {
		h[0][i] = hei[i];
	}
	for (int k = 1; 1 << k <= n - 1; k++) {
		for (int i = 1, j = (1 << (k - 1)) + 1; i <= n - (1 << k); i++, j++) {
			h[k][i] = min(h[k - 1][i], h[k - 1][j]);
		}
	}
}

void add(int t, int x, int y, int i, int l, int r) {
	ev[++tot].t = t, ev[tot].x = x, ev[tot].y = y, ev[tot].i = i, ev[tot].l = l, ev[tot].r = r;
}

void mod(int x) {
	for (int i = x; i <= m; i += i & -i) {
		bit[i]++;
	}
}

int sum(int x) {
	int y = 0;
	for (int i = x; i; i ^= i & -i) {
		y += bit[i];
	}
	return y;
}

int main() {
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", t + 1);
		len[i] = strlen(t + 1);
		pos[i] = m + 1;
		for (int j = 1; j <= len[i]; j++) {
			s[++m] = t[j];
		}
		s[++m] = '{';
	}
	pos[n + 1] = m + 1;
	make(s, m);
	for (int i = 1; i <= n; i++) {
		int x = rnk[pos[i]];
		for (int j = logn; ~j; j--) {
			int t = x - (1 << j);
			if (t > 0 && h[j][t] >= len[i]) x = t;
		}
		lft[i] = x, x = rnk[pos[i]];
		for (int j = logn; ~j; j--) {
			int t = x + (1 << j);
			if (t <= m && h[j][x] >= len[i]) x = t;
		}
		rht[i] = x;
	}
	for (int i = 1; i <= m; i++) {
		add(1, i, rnk[i], -1, -1, -1);
	}
	for (int i = 1, l, r, k; i <= q; i++) {
		scanf("%d %d %d", &l, &r, &k);
		l = pos[l], r = pos[r + 1] - 1;
		int L = lft[k], R = rht[k];
		add(2, l - 1, -1, i, L, R), add(2, r, 1, i, L, R);
	}
	sort(ev + 1, ev + tot + 1);
	for (int i = 1; i <= tot; i++) {
		if (ev[i].t == 1) {
			mod(ev[i].y);
		} else {
			ans[ev[i].i] += (sum(ev[i].r) - sum(ev[i].l - 1)) * ev[i].y;
		}
	}
	for (int i = 1; i <= q; i++) {
		printf("%d\n", ans[i]);
	}
	return 0;
}