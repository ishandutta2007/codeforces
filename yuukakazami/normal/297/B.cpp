#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include <vector>
#include <utility>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, m, k;
int a[MAX_N], b[MAX_N];

vector<pair<int, int> > es;

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
		es.push_back(make_pair(a[i], 1));
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
		es.push_back(make_pair(b[i], -1));
	}

	sort(es.begin(), es.end());
	int cnt = 0;

	for (int i = es.size() - 1; i >= 0; --i) {
		cnt += es[i].second;
		if (i == 0 || es[i].first > es[i - 1].first) {
			if (cnt > 0) {
				puts("YES");
				return 0;
			}
		}
	}

	puts("NO");
}