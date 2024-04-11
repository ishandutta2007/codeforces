#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
	int N, K; cin >> N >> K;
	vector<int>as(N);
	for (int i = 0; i < N; ++i)cin >> as[i];
	vector<int>bs(as);
	for (int i = 0; i < N - 1; ++i) {
		if (bs[i] + bs[i + 1] < K) {
			bs[i + 1] = K - bs[i];
		}
	}
	int asum = accumulate(as.begin(), as.end(), 0);
	int bsum = accumulate(bs.begin(), bs.end(), 0);
	cout << bsum - asum << endl;
	for (int i = 0; i < N; ++i) {
		cout << bs[i];
		if (i == N - 1)cout << endl;
		else cout << " ";
	}
	return 0;
}