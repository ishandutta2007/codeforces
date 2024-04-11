#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;


int n;
bool g[3][200];
bool used[3][200];
bool dp[3][200];

bool calc(int x, int y) {
	if (g[y][x]) return false;
	if (n <= x) return true;
	if (used[y][x]) return dp[y][x];
	used[y][x] = true;
	dp[y][x] = false;

	int xx = x+1;
	if (g[y][xx]) return false;

	bool f = false;
	for (int d = -1; d <= 1; d++) {
		int yy = y+d;
		if (!(0 <= yy && yy <= 2)) continue;
		if (g[yy][xx]) continue;
		int xxx = xx;
		xxx++;
		if (g[yy][xxx]) continue;
		xxx++;
		if (g[yy][xxx]) continue;
		if (calc(xxx, yy)) {
			f = true;
			break;
		}
	}

	return dp[y][x] = f;
}

void solve() {
	int k;
	cin >> n >> k;
	string gs[3];
	cin >> gs[0] >> gs[1] >> gs[2];
	memset(g, 0, sizeof(g));
	memset(used, 0, sizeof(used));
	int sx, sy;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			if (gs[i][j] == 's') {
				sx = j; sy = i;
				gs[i][j] = '.';
			}
			g[i][j] = (gs[i][j] != '.');
		}
	}
	if (calc(sx, sy)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

}

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		solve();
	}
    return 0;
}