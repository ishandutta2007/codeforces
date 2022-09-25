#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

const int maxn = 222222;

int n, k;
ll a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	++n;
	for (int i = 0; i < n; ++i) cin >> a[i], b[i] = a[i];
	int idx = -1;
	for (int i = 0; i + 1 < n; ++i) {
		int x = a[i] < 0 ? (a[i] - 1) / 2 : a[i] / 2;
		a[i + 1] += x;
		a[i] -= 2 * x;
		if (a[i] != 0 && idx == -1) {
			idx = i;
		}
	}
	if (a[n - 1] != 0 && idx == -1) idx = n - 1;
	if (idx == -1) cout << 0 << endl, exit(0);

	int ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (llabs(a[i]) > 2 * k) {
			break;
		}
		//for (int j = 0; j < n; ++j) {
			//cerr << a[j] << " ";
		//}
		//cerr << endl;
		if (i <= idx) {
			if (i == n - 1) {
				if (b[i] != a[i] && llabs(b[i] - a[i]) <= k) ++ans;
			} else {
				if (llabs(b[i] - a[i]) <= k) ++ans;
			}
		}
		if (i == 0) break;
		a[i - 1] += a[i] * 2;
		a[i] = 0;
	}
	cout << ans << endl;
  return 0;
}