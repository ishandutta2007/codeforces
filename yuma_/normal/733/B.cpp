#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

int main() {
	int lwin = 0;
	vector<int>nums;
	int N; cin >> N;
	for (int i = 0; i < N; ++i) {
		int l, r; cin >> l >> r;
		nums.push_back(2 * (l-r));
		lwin += l - r;

	}
	pair<int, int>ans = make_pair(abs(lwin), -1);
	for (int i = 0; i < N; ++i) {
		pair<int, int>aans = make_pair(abs(lwin - nums[i]), i);
		ans = max(ans, aans);
	}
	cout << ans.second + 1 << endl;
	return 0;
}