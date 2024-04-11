#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, nQ;
int v[MAX_N], c[MAX_N];
typedef long long int64;
const int64 INF = 1LL << 60;

struct Data {
	int64 dp[MAX_N];
	int mx[2];

	void init(int n) {
		fill(dp, dp + n, -INF);
		mx[0] = 0;
		mx[1] = 1;
	}

	int64 operator[](int i) {
		return dp[i];
	}

	void update(int i, int64 x) {
		if (x > dp[i]) {
			//if i in mx
			dp[i] = x;
			if (i == mx[0]) {
				return;
			}
			if (i == mx[1]) {
				if (dp[mx[1]] > dp[mx[0]])
					swap(mx[0], mx[1]);
				return;
			}
			if (dp[i] > dp[mx[1]]) {
				mx[1] = i;
				if (dp[mx[1]] > dp[mx[0]])
					swap(mx[0], mx[1]);
			}
		}
	}

	int64 evalOther(int i) {
		if (i == mx[0])
			return dp[mx[1]];
		else
			return dp[mx[0]];
	}
};

Data data;

int main() {
	cin >> n >> nQ;
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
		--c[i];
	}
	for (int i = 0; i < nQ; ++i) {
		int64 a, b;
		cin >> a >> b;
		data.init(n + 1);
		int64 ans = 0;
		for (int j = 0; j < n; ++j) {
			int x = c[j];
			int64 same = -INF;
			if (data[x] != -INF) {
				same = data[x] + a * v[j];
			}
			int64 other = max(data.evalOther(x), 0LL) + b * v[j];
			int64 best = max(same, other);
			data.update(x, best);
			ans = max(ans, best);
		}
		cout << ans << endl;
	}
	return 0;
}