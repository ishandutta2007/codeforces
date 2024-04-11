#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	int a[100][100] = { };
	cin >> n >> m;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			cin >> a[r + 1][c + 1];
			a[r + 1][c + 1] += a[r][c + 1] + a[r + 1][c] - a[r][c];
		}
	}

	int ans = 0;
	int A, B, C;
	cin >> A >> B >> C;
	vector<int> tmp;
	tmp.push_back(A), tmp.push_back(B), tmp.push_back(C);
	sort(tmp.begin(), tmp.end());
	for (int x1 = 1; x1 < m; ++x1) {
		for (int x2 = x1 + 1; x2 < m; ++x2) {
			int s[3] = { a[n][x1], a[n][x2], a[n][m] };
			for (int i = 2; i >= 1; --i) {
				s[i] -= s[i - 1];
			}
			vector<int> cur(s, s + 3);
			sort(cur.begin(), cur.end());
			if (cur == tmp)
				ans++;
		}
	}
	for (int y1 = 1; y1 < n; ++y1) {
		for (int y2 = y1 + 1; y2 < n; ++y2) {
			int s[3] = { a[y1][m], a[y2][m], a[n][m] };
			for (int i = 2; i >= 1; --i) {
				s[i] -= s[i - 1];
			}
			vector<int> cur(s, s + 3);
			sort(cur.begin(), cur.end());
			if (cur == tmp)
				ans++;
		}
	}
	cout << ans << endl;
}