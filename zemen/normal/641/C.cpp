#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

const int maxn = 1111111, maxq = 2222222;

int n, q, type[maxq], shift[maxq];
int p1[maxn], p2[maxn], ans[maxn];

int main() {
	scanf("%d%d", &n, &q);
	ll sumshift = 0;
	vector<int> swaps;
	for (int i = 0; i < q; ++i) {
		scanf("%d", &type[i]);
		if (type[i] == 1) {
			scanf("%d", &shift[i]);
			sumshift += shift[i];
		} else {
			if (sumshift & 1) {
				if (swaps.size() && swaps.back() == 1) swaps.pop_back();
				else swaps.push_back(1);
			} else {
				if (swaps.size() && swaps.back() == 0) swaps.pop_back();
				else swaps.push_back(0);
			}
		}
	}
	for (int i = 0; i < n; ++i) p1[i] = i;
	if (swaps.size() && swaps[0] == 1) {
		swaps.erase(swaps.begin());
		for (int i = 1; i + 1 < n; i += 2) {
			swap(p1[i], p1[i + 1]);
		}
		swap(p1[0], p1[n - 1]);
	}
	int k = swaps.size();
	for (int i = 0; i < n; ++i) {
		if (i & 1) {
			p2[i] = (i - k) % n;
		} else {
			p2[i] = (i + k) % n;
		}
		if (p2[i] < 0) p2[i] += n;
	}
	for (int i = 0; i < n; ++i) {
		ll pos = (p2[p1[i]] + sumshift) % n;
		if (pos < 0) pos += n;
		ans[pos] = i + 1;
	}
	for (int i = 0; i < n; ++i) printf("%d ", ans[i]);
	printf("\n");
  return 0;
}