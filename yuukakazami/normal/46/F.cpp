#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;
const int MAX_N = 1000 + 10;
int n, m, k;
int ea[MAX_N], eb[MAX_N];
struct VertexSet {
	set<string> names;
	set<int> keys;
};

vector<VertexSet*> read() {
	vector<VertexSet*> vs(n);
	for (int i = 0; i < n; ++i) {
		vs[i] = new VertexSet;
	}
	for (int i = 0; i < k; ++i) {
		string name;
		cin >> name;
		int at;
		cin >> at;
		--at;
		int cnt;
		cin >> cnt;
		vs[at]->names.insert(name);
		for (int j = 0; j < cnt; ++j) {
			int x;
			cin >> x;
			--x;
			vs[at]->keys.insert(x);
		}
	}
	for (;;) {
		bool changed = false;
		for (int i = 0; i < m; ++i) {
			int a = ea[i], b = eb[i];
			if (vs[a] != vs[b]) {
				if (vs[a]->keys.count(i) || vs[b]->keys.count(i)) {
					vs[a]->keys.insert(vs[b]->keys.begin(), vs[b]->keys.end());
					vs[a]->names.insert(vs[b]->names.begin(), vs[b]->names.end());
					VertexSet*old = vs[b];
					for (int j = 0; j < n; ++j) {
						if (vs[j] == old)
							vs[j] = vs[a];
					}
					changed = true;
				}
			}
		}
		if (!changed)
			break;
	}
	return vs;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		cin >> ea[i] >> eb[i];
		--ea[i], --eb[i];
	}
	vector<VertexSet*> x = read(), y = read();
	for (int i = 0; i < n; ++i) {
		if (x[i]->keys != y[i]->keys || x[i]->names != y[i]->names) {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}