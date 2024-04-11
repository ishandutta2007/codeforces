#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

const int MAX_N = int(1e5) + 10;

struct WEdge {
	int a, b, c;
	WEdge(int a, int b, int c) :
			a(a), b(b), c(c) {
	}
	bool operator<(const WEdge&o) const {
		return c > o.c;
	}
};

vector<WEdge> wedges;

int f[MAX_N], sz[MAX_N], v[MAX_N];
int n, m;

int fd(int x) {
	if (f[x] == x)
		return x;
	return f[x] = fd(f[x]);
}

void unite(int a, int b) {
	a = fd(a), b = fd(b);
	if (a == b)
		return;
	f[a] = b;
	sz[b] += sz[a];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		scanf("%d", v + i);
	}
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b), --a, --b;
		wedges.push_back(WEdge(a, b, min(v[a], v[b])));
	}
	sort(wedges.begin(), wedges.end());
	for (int i = 0; i < n; ++i) {
		f[i] = i;
		sz[i] = 1;
	}

	long long sum = 0;

	for (auto e : wedges) {
		int a = e.a, b = e.b, c = e.c;
		a = fd(a), b = fd(b);
		if (a != b) {
			sum += 1LL * sz[a] * sz[b] * c;
			unite(a, b);
		}
	}
	double ans = 1.0 * sum / (1LL * n * (n - 1) / 2);
	printf("%0.10lf\n", ans);
}