#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define left LEFT
#define right RIGHT

using namespace std;

const int N = 2005;
const int INF = 2147483647;

double p;
int n, h, x[N], f[N], left[N], right[N];
double dp[N][N][2][2];
int visit[N][N][2][2];

double dfs(int l, int r, int ll, int rr) {
	if (l > r) {
		return 0.0;
	}
	
	if (visit[l][r][ll][rr]) {
		return dp[l][r][ll][rr];
	}
	
	visit[l][r][ll][rr] = 1;
	double ans = 0;
	double sl = 0, sr = 0;
	if (l == 1) {
		sl = h;
	} else {
		if (ll == 1) {
			sl = min(h, max(0, x[l] - x[l - 1] - h));
		} else {
			sl = min(h, x[l] - x[l - 1]);
		}
	}
	
	if (r == n) {
		sr = h;
	} else {
		if (rr == 1) {
			sr = min(h, max(0, x[r + 1] - x[r] - h));
		} else {
			sr = min(h, x[r + 1] - x[r]);
		}
	}
	
	ans += 0.5 * p * (sl + dfs(l + 1, r, 0, rr));
	ans += 0.5 * (1 - p) * (sr + dfs(l, r - 1, ll, 0));
	int pos = min(right[f[l]], r);
	if (pos < r) {
		ans += 0.5 * (1 - p) * (x[pos] + h - x[l] + dfs(pos + 1, r, 1, rr));
	} else {
		ans += 0.5 * (1 - p) * (x[pos] - x[l] + sr);
	}
	
	pos = max(l, left[f[r]]);
	if (pos > l) {
		ans += 0.5 * p * (x[r] + h - x[pos] + dfs(l, pos - 1, ll, 1));
	} else {
		ans += 0.5 * p * (x[r] - x[pos] + sl);
	}
	
	dp[l][r][ll][rr] = ans;
	return ans;
}

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d %d %lf", &n, &h, &p);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x[i]);
	}
	
	sort(x + 1, x + n + 1);
	f[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (x[i] - x[i - 1] < h) {
			f[i] = f[i - 1];
		} else {
			f[i] = f[i - 1] + 1;
		}
	}
	
	for (int i = 1; i <= f[n]; i++) {
		left[i] = INF;
		right[i] = -INF;
	}
	
	for (int i = 1; i <= n; i++) {
		int now = f[i];
		left[now] = min(left[now], i);
		right[now] = max(right[now], i);
	}
	
	printf("%.10f\n", dfs(1, n, 0, 0));
	return 0;
}