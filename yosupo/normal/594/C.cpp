#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

typedef tuple<ll, ll, int> T;

const int MN = 100100;

int n, k;
T xyz[MN], yxz[MN];


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		xyz[i] = T(a+c, b+d, i);
		yxz[i] = T(b+d, a+c, i);
	}

	sort(xyz, xyz+n);
	sort(yxz, yxz+n);

	ll ma = 1LL<<61;
	for (int l = 0; l <= k; l++) {
		for (int r = max(l+1, n-k); r <= n; r++) {
			for (int d = 0; d <= k; d++) {
				for (int u = max(d+1, n-k); u <= n; u++) {
					vector<int> v;
					for (int i = 0; i < l; i++) {
						v.push_back(get<2>(xyz[i]));
					}
					for (int i = r; i < n; i++) {
						v.push_back(get<2>(xyz[i]));
					}

					for (int i = 0; i < d; i++) {
						v.push_back(get<2>(yxz[i]));
					}
					for (int i = u; i < n; i++) {
						v.push_back(get<2>(yxz[i]));
					}

					sort(v.begin(), v.end());
					v.erase(unique(v.begin(), v.end()), v.end());

					if (k < (int)v.size()) continue;

					ma = min(ma,
						max(1LL, (get<0>(xyz[r-1]) - get<0>(xyz[l]) + 1) / 2)
						*
						max(1LL, (get<0>(yxz[u-1]) - get<0>(yxz[d]) + 1) / 2)
						);

				}
			}
		}
	}
	cout << ma << endl;
    return 0;
}