/*
 * e.cpp
 *
 *  Created on: 2012-3-28
 *      Author: mac
 */
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
#define REP(i,n) for(int i=0;i<n;++i)
using namespace std;

const int MAX_N = 600 + 10;
const int MAX_K = 300 + 10;

int mod;
int n, m;
bool isSrc[MAX_N], isDst[MAX_N];

vector<int> edge[MAX_N], redge[MAX_N];

int srcId[MAX_N], dstId[MAX_N];
int nId;

int rev;

int cnt[MAX_N][MAX_N];

int calc(int a, int b) {
	int&ret = cnt[a][b];
	if (ret != -1)
		return ret;
	if (a == b)
		return ret = 1;
	ret = 0;
	for (vector<int>::iterator e = redge[b].begin(); e != redge[b].end(); ++e) {
		ret += calc(a, *e);
		if (ret >= mod)
			ret -= mod;
	}
	return ret;
}

typedef long long int64;
int64 mat[MAX_K][MAX_K];

int64 myPow(int64 a, int64 e) {
	if (e == 0)
		return 1;
	if (e % 2 == 0)
		return myPow(a * a % mod, e >> 1);
	else
		return myPow(a, e - 1) * a % mod;
}

void rex(int64&x) {
	x %= mod;
	if (x < 0)
		x += mod;
}

int main() {
	cin >> n >> m >> mod;
	for (int i = 0; i < n; ++i) {
		isSrc[i] = isDst[i] = true;
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edge[a].push_back(b);
		redge[b].push_back(a);
		isSrc[b] = false;
		isDst[a] = false;
	}

	nId = 0;
	for (int i = 0; i < n; ++i) {
		if (isSrc[i])
			srcId[i] = nId++;
	}
	nId = 0;
	for (int i = 0; i < n; ++i) {
		if (isDst[i])
			dstId[i] = nId++;
	}
	rev = 1;
	for (int i = 0; i < n; ++i) {
		if (isSrc[i] && isDst[i]) {
			int a = srcId[i], b = dstId[i];
			if ((a + b) % 2 == 1)
				rev *= -1;
		}
	}

	nId = 0;
	memset(srcId, -1, sizeof srcId);
	memset(dstId, -1, sizeof dstId);
	for (int i = 0; i < n; ++i) {
		if (isSrc[i] && !isDst[i])
			srcId[i] = nId++;
	}
	nId = 0;
	for (int i = 0; i < n; ++i) {
		if (isDst[i] && !isSrc[i])
			dstId[i] = nId++;
	}

	memset(cnt, -1, sizeof cnt);

	for (int i = 0; i < n; ++i) {
		if (srcId[i] != -1) {
			for (int j = 0; j < n; ++j) {
				if (dstId[j] != -1)
					mat[srcId[i]][dstId[j]] = calc(i, j);
			}
		}
	}

//	for (int i = 0; i < nId; ++i) {
//		for (int j = 0; j < nId; ++j) {
//			cout << mat[i][j] << " ";
//		}
//		cout << endl;
//	}

	//calc mat's det
	int64 ans = 1;
	for (int c = 0; c < nId; ++c) {
		int myR = -1;
		for (int r = c; r < nId; ++r) {
			if (mat[r][c] != 0) {
				myR = r;
				break;
			}
		}
		if (myR == -1) {
			ans = 0;
			break;
		}
		if (c != myR) {
			rev *= -1;
			for (int nc = 0; nc < nId; ++nc) {
				swap(mat[c][nc], mat[myR][nc]);
			}
		}
		ans *= mat[c][c];
		ans %= mod;
		int64 inv = myPow(mat[c][c], mod - 2);
		for (int nc = 0; nc < nId; ++nc) {
			mat[c][nc] *= inv;
			mat[c][nc] %= mod;
		}
		for (int nr = 0; nr < nId; ++nr)
			if (nr != c) {
				if (mat[nr][c] != 0) {
					int64 by = mat[nr][c];
					for (int nc = 0; nc < nId; ++nc) {
						rex(mat[nr][nc] -= mat[c][nc] * by);
					}
				}
			}
	}
	ans *= rev;
	rex(ans);
	cout << ans << endl;
	return 0;
}