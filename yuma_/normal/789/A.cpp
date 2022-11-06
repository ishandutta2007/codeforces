#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int N, K; cin >> N >> K;
	vector<int>ws(N);
	for (int i = 0; i < N; ++i) {
		cin >> ws[i];
		ws[i] = (ws[i] - 1) / K + 1;
	}
	int ans = 0;
	ans = max(ans,( accumulate(ws.begin(), ws.end(), 0) + 1) / 2);
	cout << ans << endl;

	return 0;

	int B, Q, L, M; cin >> B >> Q >> L >> M;
	for (int i = 0; i < M; ++i) {
		int a; cin >> a;
	}
}