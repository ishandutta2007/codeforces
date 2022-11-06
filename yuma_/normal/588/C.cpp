#include "bits/stdc++.h"
using namespace std;



int main() {
	int n; cin >> n;
	vector<int>weights;
	vector<int>nums(1100001);
	for (int i = 0; i < n; ++i) {
		int a;
		scanf("%d", &a);
		nums[a] ++;
	}
	for (int i = 0; i < 1100000; ++i) {
		nums[i + 1] += nums[i] / 2;
		nums[i] %= 2;
	}
	int ans = 0;
	for (int i = 0; i < 1100001; ++i) {
		if (nums[i]) {
			ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}