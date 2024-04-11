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

const int MN = 100100;
const int MM = 100100;
int n, m;
int a[MM], b[MM], c[MM], d[MM];


bool solve() {
	static int idx[MN];
	for (int i = 0; i < m; i++) {
		idx[i] = i;
	}
	sort(idx, idx+m, [&](const int &l, const int &r){
		if (a[l] != a[r]) return a[l] < a[r];
		return b[l] > b[r];
	});

	int u = -1, v = 1;
	int co = 0;
	for (int fe = 0; fe < m; fe++) {
		int i = idx[fe];
		int x = a[i], y = b[i];

		if (y == 1) {
			c[i] = co; d[i] = co+1;
			co++;
		} else {
			if (u == v-2 && v >= co) return false;
			if (u == v-2) {
				u = 0;
				v++;
			} else {
				u++;
			}
			c[i] = u; d[i] = v;
		}
	}
	return true;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", a+i, b+i);
	}
	if (solve()) {
		for (int i = 0; i < m; i++) {
			printf("%d %d\n", c[i]+1, d[i]+1);
		}
	} else {
		printf("-1\n");
	}
    return 0;
}