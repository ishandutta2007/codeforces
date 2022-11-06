#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps=1e-9;

int main() {
	int N, T; cin >> N >> T;
	vector<vector<ld>>nows(N);
	
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= i; ++j) {
			nows[i].push_back(0);
		}
	}
	for (int t = 0; t < T; ++t) {
		nows[0][0] += 1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j <=i; ++j) {
				if (nows[i][j]>1 + eps) {
					if (i != N - 1) {
						nows[i + 1][j] += (nows[i][j] - 1) / 2;
						nows[i + 1][j + 1] += (nows[i][j] - 1) / 2;
					}
					nows[i][j] = 1;
				}
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <=i; ++j) {
			if (nows[i][j]>1 - eps) {
				ans++;
			}
		}
	}
	cout << ans << endl;
	return 0;
}