#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
	int N, M; cin >> N >> M;
	vector<pair<int, int>>ranges;
	int ans = 1e9;
	for (int i = 0; i < M; ++i) {
		int l, r; cin >> l >> r;
		l--;
		ranges.emplace_back(l, r);
		ans = min(ans, r - l);
	}
	vector<int>v(N);
	for (int i = 0; i < N; ++i) {
		v[i] = i%ans;
	}
	cout << ans << endl;
	for (int i = 0; i < N; ++i) {
		cout << v[i];
		if (i != N - 1)cout << " ";
		else cout << endl;
	}

	return 0;
}