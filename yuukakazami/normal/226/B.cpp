#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
typedef long long int64;
int n;
const int MAX_N = int(1e5) + 10;
int64 a[MAX_N];
int64 sum[MAX_N];
int64 ans[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	partial_sum(a, a + n, sum);
	for (int k = 1; k <= n; ++k) {
		//k,k^2,k^3
		int64 cur = 1;
		int64 i = 0, iter = 0;
		while (i < n) {
			int l = i, r = min(i + cur - 1, int64(n - 1));
			ans[k] += (sum[r] - (l ? sum[l - 1] : 0)) * iter;
			i += cur;
			++iter;
			cur *= k;
		}
	}
	int nQ;
	cin >> nQ;
	for (int i = 0; i < nQ; ++i) {
		int x;
		cin >> x;
		x = min(x, n);
		cout << ans[x] << " ";
	}
	return 0;
}