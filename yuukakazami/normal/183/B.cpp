/*
 * b.cpp
 *
 *  Created on: 2012-4-27
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = int(1e6) + 10;
const int MAX_M = 250 + 1;

typedef long long int64;

struct Point {
	int64 x, y;
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))

int n, m;
Point ps[MAX_M];

int can[MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> ps[i].x >> ps[i].y;
	}
	for (int i = 1; i <= n; ++i) {
		can[i] = 1;
	}
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < i; ++j) {
			Point a = ps[i], b = ps[j];
			if (a.y == b.y)
				continue;
			int64 dx = a.x - b.x, dy = a.y - b.y;
			int64 g = __gcd(dx, dy);
			dx /= g, dy /= g;

			int cnt = 0;
			for (int k = 0; k < m; ++k) {
				if (cross(ps[i],ps[j],ps[k]) == 0)
					++cnt;
			}

			if (a.y % dy == 0) {
				int64 by = a.y / dy;
				int64 x = a.x - by * dx, y = a.y - by * dy;
				if (x >= 1 && x <= n) {
					can[x] = max(can[x], cnt);
				}
			}
		}
	}

	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += can[i];
	}

	cout << ans << endl;
}