#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;
int n, p;
const int MAX_N = 50000 + 10, INF = ~0U >> 2;
int a[33], id[33], pw10[33], nId;

int dp[33][MAX_N]; //xor,mod
bool used[33][MAX_N];
int prev[33][MAX_N];

int orig[MAX_N];

int main() {
	cin >> n >> p;
	nId = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (x < 32) {
			a[nId] = x;
			id[nId++] = i;
		}
		orig[i] = x;
	}

	n = nId;
	for (int i = 0; i < n; ++i) {
		pw10[i] = 1;
		while (pw10[i] <= a[i])
			pw10[i] *= 10;
	}

	priority_queue<pair<int, pair<int, int> > > pque;
	fill(dp[0], dp[32], INF);
	dp[0][0] = 0;
	prev[0][0] = -1;
	pque.push(make_pair(-dp[0][0], make_pair(0, 0)));
	while (!pque.empty()) {
		int xr = pque.top().second.first, md = pque.top().second.second;
		pque.pop();
		if (used[xr][md])
			continue;
		used[xr][md] = true;
		int d = dp[xr][md];
		for (int i = d; i < n; ++i) {
			int nxr = xr ^ a[i], nmd = (md * pw10[i] + a[i]) % p;
			if (nxr == 0 && nmd == 0) {
				vector<int> ans;
				ans.push_back(id[i] + 1);
				int code = md * 32 + xr;

				for (;;) {
					int b = code / 32, x = code % 32;
					if (dp[x][b] == 0)
						break;
					ans.push_back(id[dp[x][b] - 1] + 1);
					code = prev[x][b];
				}
				cout << "Yes" << endl;
				reverse(ans.begin(), ans.end());
				cout << ans.size() << endl;
				for (vector<int>::iterator e = ans.begin(); e != ans.end(); ++e) {
					cout << *e << " ";
				}
				cout << endl;
				return 0;
			}
			if (i + 1 < dp[nxr][nmd]) {
				dp[nxr][nmd] = i + 1;
				prev[nxr][nmd] = md * 32 + xr;
				pque.push(make_pair(-dp[nxr][nmd], make_pair(nxr, nmd)));
			}
		}
	}
	cout << "No" << endl;
	return 0;
}