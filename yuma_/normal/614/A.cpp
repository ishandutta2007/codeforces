#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


//long long int gcd(vector<long long int>nums) {
//	if (nums.size() == 1)return nums[0];
//	long long int num = nums[0];
//	
//	for (int i = 1; i < nums.size(); ++i) {
//		num = gcd(num, nums[i]);
//	}
//	return num;
//}


int main() {
	unsigned long long int l, r, k; cin >> l >> r >> k;


	unsigned long long int num(18446744073709551615);
	int time = 0;
	while (num) {
		num /= k;
		time++;
	}
	vector<unsigned long long int >ans;
	unsigned long long int now = 1;
	for (int i = 0; i < time; ++i) {
		if (l <= now&&now <= r)ans.push_back(now);
		now *= k;
	}
	if (!ans.empty()) {
		for (int i = 0; i < ans.size(); ++i) {
			cout << ans[i];
			if (i == ans.size() - 1) {
				cout << endl;
			}
			else {
				cout << " ";
			}
		}
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}