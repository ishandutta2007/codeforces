#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5;
int n, a[maxn + 3], k, p[maxn + 3];
bool b[maxn + 3];
vector<int> vec[maxn + 3];

void prework(int n) {
	for (int i = 2; i <= n; i++) {
		if (!b[i]) {
			p[++k] = i;
		}
		for (int j = 1; j <= k && i * p[j] <= n; j++) {
			b[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	prework(maxn);
	scanf("%d", &n);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		for (int j = 2; j * j <= x; j++) {
			if (x % j == 0) {
				int c = 0;
				while (x % j == 0) x /= j, c++;
				vec[j].push_back(c);
			}
		}
		if (x > 1) vec[x].push_back(1);
	}
	long long ans = 1;
	for (int i = 2; i <= maxn; i++) if (!b[i]) {
		sort(vec[i].begin(), vec[i].end());
		if (vec[i].size() == n) {
			for (int j = 0; j < vec[i][1]; j++) ans *= i;
		} else if (vec[i].size() == n - 1) {
			for (int j = 0; j < vec[i][0]; j++) ans *= i;
		}
	}
	printf("%I64d\n", ans);
	return 0;
}