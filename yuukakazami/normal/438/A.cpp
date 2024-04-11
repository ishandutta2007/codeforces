#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
int n, m;
const int MAX_N = 1000 + 10;
int v[MAX_N];
bool dead[MAX_N];
bool e[MAX_N][MAX_N];
int ord[MAX_N];

bool cmp(int a, int b) {
	return v[a] > v[b];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		ord[i] = i;
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		e[a][b] = e[b][a] = true;
	}
	sort(ord, ord + n, cmp);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int u = ord[i];
		for (int v = 0; v < n; ++v) {
			if (!dead[v] && e[u][v])
				ans += ::v[v];
		}
		dead[u] = true;
	}
	cout << ans << endl;
}