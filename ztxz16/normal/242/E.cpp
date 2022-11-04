#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ
#define left LEFT
#define right RIGHt

using namespace std;

int FASTBUFFER;

const int N = 100005;

int left[N << 2], right[N << 2];
int s[N << 2][22], tag[N << 2][22];
int n, q, a[N];

void up(const int &i) {
	int lc = (i << 1), rc = (lc | 1);
	for (int x = 0; x <= 20; x++) {
		s[i][x] = s[lc][x] + s[rc][x];
	}
}

void down(const int &i) {
	int lc = (i << 1), rc = (lc | 1);
	for (int x = 0; x <= 20; x++) {
		if (tag[i][x]) {
			s[lc][x] = right[lc] - left[lc] + 1 - s[lc][x];
			s[rc][x] = right[rc] - left[rc] + 1 - s[rc][x];
			tag[lc][x] ^= 1;
			tag[rc][x] ^= 1;
			tag[i][x] = 0;
		}
	}
}

void make(const int &l, const int &r, const int &i) {
	int mid = (l + r) >> 1;
	left[i] = l, right[i] = r;
	if (l == r) {
		for (int x = 0; x <= 20; x++) {
			s[i][x] = ((a[l] & (1 << x)) > 0);
		}
		
		return;
	}
	
	make(l, mid, (i << 1));
	make(mid + 1, r, ((i << 1) | 1));
	up(i);
}

void work(const int &l, const int &r, const int &i, const int &type, long long &v) {
	if (l > right[i] || r < left[i]) {
		return;
	}
	
	if (l <= left[i] && r >= right[i]) {
		if (type == 1) {
			for (int x = 0; x <= 20; x++) {
				v += (1LL << x) * s[i][x];
			}
		} else {
			for (int x = 0; x <= 20; x++) {
				if (v & (1 << x)) {
					s[i][x] = right[i] - left[i] + 1 - s[i][x];
					tag[i][x] ^= 1;
				}
			}
		}
		
		return;
	}
	
	down(i);
	work(l, r, (i << 1), type, v);
	work(l, r, ((i << 1) | 1), type, v);
	up(i);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	make(1, n, 1);
	scanf("%d", &q);
	while (q--) {
		int type, l, r, x;
		scanf("%d", &type);
		if (type == 2) {
			scanf("%d %d %d", &l, &r, &x);
			long long xx = x;
			work(l, r, 1, 2, xx);
		} else {
			scanf("%d %d", &l, &r);
			long long ans = 0;
			work(l, r, 1, 1, ans);
			cout << ans << endl;
		}
	}
	
	return 0;
}