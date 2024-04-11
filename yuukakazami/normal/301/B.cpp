#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
const int MAX_N = 100 + 10, INF = ~0U >> 1;
int n, d;
int x[MAX_N], y[MAX_N];
int dist[MAX_N][MAX_N];
int a[MAX_N];

int dp[MAX_N];

int main() {
	cin >> n >> d;
	for (int i = 1; i < n - 1; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
		}
	}

	fill(dp, dp + n, INF);
	dp[n - 1] = 0;
	for (;;) {
		bool updated = false;
		for (int i = 0; i < n; ++i)
			if (dp[i] < INF) {
				for (int j = 0; j < n; ++j)
					if (j != i) {
						//j->i
						int nc = d * dist[j][i] - a[j] + dp[i];
						if (nc < dp[j]) {
							dp[j] = nc;
							updated = true;
						}
					}
			}
		if (!updated)
			break;
	}
	cout << dp[0] << endl;
}