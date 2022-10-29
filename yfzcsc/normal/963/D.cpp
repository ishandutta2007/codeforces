#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
typedef bool boolean;
#define ll long long

const int N = 1e5 + 5, bzmax = 20;

typedef class Pair3 {
	public:
		int x, y, id;

		Pair3(int x = 0, int y = 0, int id = 0):x(x), y(y), id(id) {	}
}Pair3;

int n, q;
char str[N << 1];
int sa[N], rk[N], cnt[N];
Pair3 xs[N], ys[N];
char buf[N];

inline void init() {
	scanf("%s", str + 1);
	n = strlen(str + 1);
	scanf("%d", &q);
}

void radix_sort(Pair3* xs) {
	int m = max(n, 256);
	memset(cnt, 0, sizeof(int) * (m + 1));
	for (int i = 1; i <= n; i++)
		cnt[xs[i].y]++;
	for (int i = 1; i <= m; i++)
		cnt[i] += cnt[i - 1];
	for (int i = 1; i <= n; i++)
		ys[cnt[xs[i].y]--] = xs[i];

	memset(cnt, 0, sizeof(int) * (m + 1));
	for (int i = 1; i <= n; i++)
		cnt[ys[i].x]++;
	for (int i = 1; i <= m; i++)
		cnt[i] += cnt[i - 1];
	for (int i = n; i; i--)
		xs[cnt[ys[i].x]--] = ys[i];
}

void build_sa() {
	for (int i = 1; i <= n; i++)
		rk[i] = str[i];
	for (int k = 0, dif; k < bzmax; k++) {
		for (int i = 1; i + (1 << k) <= n; i++)
			xs[i] = Pair3(rk[i], rk[i + (1 << k)], i);
		for (int i = n - (1 << k) + 1; i <= n; i++)
			xs[i] = Pair3(rk[i], 0, i);
		radix_sort(xs);
		rk[xs[1].id] = dif = 1;
		for (int i = 2; i <= n; i++)
			rk[xs[i].id] = ((xs[i].x != xs[i - 1].x || xs[i].y != xs[i - 1].y) ? (++dif) : (dif));
		if (dif == n)
			break;
	}
	for (int i = 1; i <= n; i++)
		sa[rk[i]] = i;
}

int cnt1[256];
int ar[N], br[N];
void radix_sort(int* ar, int len) {
	const int temp = 255;
	int *x = ar, *y = br;
	for (int t = 0; t < 3; t++) {
		int bit = t * 8;
		memset(cnt1, 0, sizeof(cnt1));
		for (int i = 0; i < len; i++)
			cnt1[(x[i] >> bit) & temp]++;
		for (int i = 1; i <= temp; i++)
			cnt1[i] += cnt1[i - 1];
		for (int i = len - 1; ~i; i--)
			y[--cnt1[(x[i] >> bit) & temp]] = x[i];
		swap(x, y);
	}
	for (int i = 0; i < len; i++)
		ar[i] = x[i];
} 

inline void solve() {
	int K, len;
	while (q--) {
		scanf("%d%s", &K, buf + 1);
		len = strlen(buf + 1);
		
		int L = 1, R = n, l, r;
		for (int i = 1; i <= len && L <= R; i++) {
			l = L, r = R;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (str[sa[mid] + i - 1] >= buf[i])
					r = mid - 1;
				else
					l = mid + 1;
			}
			L = r + 1;
			if (L > R)
				break;
			l = L, r = R;
			while (l <= r) {
				int mid = (l + r) >> 1;
				if (str[sa[mid] + i - 1] <= buf[i])
					l = mid + 1;
				else
					r = mid - 1;
			}
			R = l - 1;
		}
		
		if (R - L + 1 < K)
			puts("-1");
//			continue;
		else {
			int res = 211985, lc = R - L + 1;
			for (int i = L; i <= R; i++)
				ar[i - L] = sa[i];
			radix_sort(ar, lc);
			for (int i = K - 1; i < lc; i++)
				res = min(ar[i] - ar[i - K + 1], res);
			printf("%d\n", res + len);
		}
	}
}

int main() {
	init();
	build_sa();
	solve();
	return 0;
}