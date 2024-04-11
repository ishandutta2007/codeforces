#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 500 + 10;

int edge[MAX_N][MAX_N], x[MAX_N];
int n;

bool have[MAX_N];

int dist[MAX_N][MAX_N];

typedef long long int64;
int64 ans[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> edge[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
		--x[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			dist[i][j] = edge[i][j];
		}
	}

	for (int i = n - 1; i >= 0; --i) {
		int me = x[i];
		have[me] = true;
		ans[i] = 0;

		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				dist[a][b] = min(dist[a][b], dist[a][me] + dist[me][b]);
			}
		}

		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				if (have[a] && have[b])
					ans[i] += dist[a][b];
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}