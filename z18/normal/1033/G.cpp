#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100, maxm = 1e5;
int n, m, t[maxn + 3], tot, cur[5];
ll v[maxn + 3];

struct event {
	int x, t, v;
	friend bool operator < (const event &a, const event &b) {
		return a.x < b.x;
	}
} ev[maxn * 3 + 3];

void add(int a, int b, int c) {
	ev[++tot].x = a, ev[tot].t = b, ev[tot].v = c;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
	}
	ll A = 0, B = 0;
	for (int s = 2; s <= m * 2; s++) {
		for (int i = 1; i <= n; i++) {
			t[i] = v[i] % s;
		}
		int l = max(1, s - m), r = (s - 1) / 2;
		for (int i = 1; i <= n; i++) {
			l = max(l, min(t[i] + 1, s - t[i]));
		}
		if (l > r) continue;
		tot = 0;
		add(l, 0, 0), add(r + 1, 0, 0);
		for (int i = 1; i <= n; i++) {
			int L = max(l, s - t[i]), R = min(r, t[i] / 2);
			if (L <= R) add(L, 1, 1), add(R + 1, 1, -1);
		}
		for (int i = 1; i <= n; i++) {
			int x = max(l, max(s - t[i], t[i] / 2 + 1));
			if (x <= r) add(x, 2, 1);
		}
		sort(ev + 1, ev + tot + 1);
		memset(cur, 0, sizeof(cur));
		ev[0].x = l;
		for (int i = 1; i <= tot; i++) {
			int cnt = cur[1], sum = cur[2];
			int len = ev[i].x - ev[i - 1].x;	
			if (cnt == 0 && (sum & 1)) A += len;
			if (cnt == 0 && (~sum & 1)) B += len;
			if (cnt == 1 && (~sum & 1)) A += len;
			cur[ev[i].t] += ev[i].v;
		}
	}
	A <<= 1, B <<= 1;
	for (int i = 1; i <= m; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++) {
			x ^= (v[j] / i) & 1;
		}
		if (x) A++;
		else B++;
	}
	ll C = (1ll * m * m - (A + B)) / 2;
	printf("%lld %lld %lld %lld\n", C, C, A, B);
	return 0;
}