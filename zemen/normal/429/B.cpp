#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <ctime>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <complex>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define INF 1000000001
#define INFL 2000000000000000001ll

#define NAME "b"

int d[4][1001][1001];
int a[1001][1001];
int na[1001][1001];
int n, m;


int main() {
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%d", a[i] + j);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			d[0][i + 1][j + 1] = max(d[0][i][j + 1], d[0][i + 1][j]) + a[i][j];
	for (int i = n - 1; i >= 0; --i)
		for (int j = 0; j < m; ++j)
			d[1][i][j + 1] = max(d[1][i][j], d[1][i + 1][j + 1]) + a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = m - 1; j >= 0; --j)
			d[2][i + 1][j] = max(d[2][i][j], d[2][i + 1][j + 1]) + a[i][j];
	for (int i = n - 1; i >= 0; --i)
		for (int j = m - 1; j >= 0; --j)
			d[3][i][j] = max(d[3][i + 1][j], d[3][i][j + 1]) + a[i][j];
	ll res = 0;
	for (int x = 1; x < n - 1; ++x)
		for (int y = 1; y < m - 1; ++y) {
			res = max(res, ll(d[0][x + 1][y]) + d[1][x + 1][y + 1] + d[3][x][y + 1] + d[2][x][y]);
			res = max(res, ll(d[0][x][y + 1]) + d[1][x][y] + d[3][x + 1][y] + d[2][x + 1][y + 1]);
		}
	cout << res << '\n';
}