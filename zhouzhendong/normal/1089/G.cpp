#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, k;
int a[N];

void Solve() {
	scanf("%d", &k);
	int sum = 0;
	for (int i = 0; i < 7; ++i) {
		scanf("%d", &a[i]);
		sum += a[i];
	}
	int ans = 2e9;
	for (int i = 0; i < 7; ++i) {
		int res = 0, tmp = k;
		for (int j = i; j < 7; ++j) {
			++res;
			tmp -= a[j];
			if (tmp == 0) {
				ans = min(ans, res);
				break;
			}
		}
		if (tmp == 0) continue; 
		int x = tmp / sum;
		if (sum * x >= tmp) --x;
		tmp -= x * sum;
		res += x * 7;
		for (int j = 0; j <= 7; ++j) {
			if (tmp == 0) {
				ans = min(ans, res);
				break;
			}
			++res;
			tmp -= a[j];
		}
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	cin >> t;
	while (t--) Solve();
}