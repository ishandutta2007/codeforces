#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_V = 100000 + 10;

vector<int> E[MAX_V];
int n;
int x[MAX_V], y[MAX_V], size[MAX_V], sx[MAX_V];
typedef long long int64;
int sumx, sumy;
int64 ans;

void rec(int u, int f) {
	sx[u] = x[u];
	size[u] = 1;
	for (vector<int>::iterator e = E[u].begin(); e != E[u].end(); ++e) {
		if (*e != f) {
			rec(*e, u);
			ans += 1LL * y[u] * sx[*e] * size[*e];
			sx[u] += sx[*e];
			size[u] += size[*e];
		}
	}
	ans += 1LL * y[u] * (sumx - sx[u]) * (n - size[u]);
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		E[a].push_back(b), E[b].push_back(a);
	}
	sumx = 0, sumy = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d%d", x + i, y + i);
		sumx += x[i], sumy += y[i];
	}
	ans = 0;
	rec(0, -1);
	printf("%0.15lf\n", 1.0 * ans / sumx / sumy);
	return 0;
}