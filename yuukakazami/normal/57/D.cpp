/*
 * D. Journey.cpp
 *
 *  Created on: 2011-8-20
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;
int n, m;
const int MAX_N = 1000 + 10;
bool map[MAX_N][MAX_N];
typedef long long int64;
int rcnt[MAX_N], ccnt[MAX_N];

void rotate() {
	static bool nmap[MAX_N][MAX_N];
	memcpy(nmap, map, sizeof map);
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			map[m - 1 - c][r] = nmap[r][c];
		}
	}
	swap(n, m);
}

int64 ans;

int rc[MAX_N], cr[MAX_N];
void doit() {
	memset(rc, -1, sizeof rc);
	memset(cr, -1, sizeof cr);
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (map[r][c])
				rc[r] = c, cr[c] = r;
		}
	}

	int64 cnt = 0;
	for (int c = 0; c < m; ++c) {
		if (cr[c] != -1) {
			int64 tmp = 0;
			int L = c, R = c;
			for (int r = 0; r < n; ++r) {
				if (L >= 0 && map[r][L])
					--L;
				if (R < m && map[r][R])
					++R;
				if (L < R) {
					tmp += R - L - 1;
					if (rc[r] > L && rc[r] < R)
						--tmp;
				}
			}
			cnt += cr[c] * tmp;
		}
	}
	ans += cnt * 2;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			scanf(" ");
			map[r][c] = getchar() == 'X';
		}
	}
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (!map[r][c])
				++rcnt[r], ++ccnt[c];
		}
	}
	ans = 0;
	for (int r = 0; r < n; ++r) {
		for (int r2 = 0; r2 < n; ++r2) {
			ans += abs(r - r2) * rcnt[r] * rcnt[r2];
		}
	}
	for (int c = 0; c < m; ++c) {
		for (int c2 = 0; c2 < m; ++c2) {
			ans += abs(c - c2) * ccnt[c] * ccnt[c2];
		}
	}
	for (int dir = 0; dir < 4; ++dir) {
		doit();
		rotate();
	}
	int64 cnt = 0;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (!map[r][c])
				++cnt;
		}
	}
	double ret = 1.0 * ans / (cnt * cnt);
	printf("%0.10lf\n", ret);
	return 0;
}