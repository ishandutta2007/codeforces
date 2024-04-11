/*
 *  [SCOI2011].cpp
 *
 *  Created on: 2011-6-1
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;
int n, m;
int memo[41][41][10000];
int ns[41][41]; //-1,0,1
const int CHOSE = 0, OK = 1, BAD = 2;
int getState(int r, int c) {
	static const int DI[] = { 0, 0, -1, 1 }, DJ[] = { -1, 1, 0, 0 };
	if (ns[r][c] == 1)
		return CHOSE;
	for (int d = 0; d < 4; ++d) {
		int nr = r + DI[d], nc = c + DJ[d];
		if (nr < 0 || nr >= n || nc < 0 || nc >= m)
			continue;
		if (ns[nr][nc] == 1)
			return OK;
	}
	return BAD;
}

int rec(int r, int c) {
	int id = r * m + c;
	int mask = 0;
	bool hasBad = false;
	for (int i = 0; i <= m; ++i) {
		int cur = id - i - 1;
		if (cur < 0) {
			mask = mask * 3 + OK;
		} else {
			int nr = cur / m, nc = cur % m;
			int my = getState(nr, nc);
			mask = mask * 3 + my;
			hasBad |= my == BAD;
		}
	}
	for (int i = 0; i < id - m; ++i) {
		int nr = i / m, nc = i % m;
		if (getState(nr, nc) == BAD)
			return INT_MAX / 2;
	}
	if (r == n) {
		if (!hasBad)
			return 0;
		else
			return INT_MAX / 2;
	}
	int&ret = memo[r][c][mask];
	if (ret != -1)
		return ret;
	ret = INT_MAX / 2;
	for (int it = 0; it < 2; ++it) {
		ns[r][c] = it;
		int nr = r, nc = c + 1;
		if (nc == m)
			nr++, nc = 0;
		int tmp = rec(nr, nc);
		if (it == 1)
			++tmp;
		ret = min(ret, tmp);
		ns[r][c] = -1;
	}
	return ret;
}
int main() {
	cin >> n >> m;
	memset(memo, -1, sizeof memo);
	if (n < m)
		swap(n, m);
	memset(ns, -1, sizeof ns);
	cout << n * m - rec(0, 0) << endl;
	return 0;
}