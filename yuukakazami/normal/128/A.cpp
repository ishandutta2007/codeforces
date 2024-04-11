#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cmath>
#include <cctype>
#include <sstream>
using namespace std;
typedef long long int64;
const int N = 8;
int memo[N][N][100];
string mp[N];

int rec(int r, int c, int rem) {
	if (r < 0 || r >= N || c < 0 || c >= N)
		return 0;
	bool bad[N][N] = { };
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (mp[i][j] == 'S') {
				int ni = i + (99 - rem);
				if (ni < N)
					bad[ni][j] = true;
			}
		}
	}
	if (bad[r][c])
		return 0;
	if (r == 0 && c == N - 1)
		return 1;
	if (!rem)
		return 0;
	int&ret = memo[r][c][rem];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int nr = r - 1; nr <= r + 1; ++nr) {
		for (int nc = c - 1; nc <= c + 1; ++nc) {
			if (nr >= 0 && nr < N && nc >= 0 && nc < N && !bad[nr][nc] && rec(nr, nc, rem - 1)) {
				return ret = 1;
			}
		}
	}
	return ret;
}

int main() {
	for (int i = 0; i < N; ++i) {
		cin >> mp[i];
	}
	memset(memo, -1, sizeof memo);
	cout << (rec(N - 1, 0, 99) ? "WIN" : "LOSE") << endl;
	return 0;
}