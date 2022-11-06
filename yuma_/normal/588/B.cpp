#include "bits/stdc++.h"
using namespace std;

vector<long long int> divisor(long long int n) {
	vector<long long int> res;
	for (long long int i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			res.push_back(i);
			if (i * i != n) res.push_back(n / i);
		}
	}
	sort(begin(res), end(res));
	return res;
}
bool isso(long long int a) {
	if (a == 1 || a == 0)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if ((a%(i*i))) {
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	
	long long int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	vector<long long int>nums(divisor(n));
	reverse(nums.begin(), nums.end());
	for (int i = 0; i < nums.size(); ++i) {
		if (isso(nums[i])) {
			cout << nums[i] << endl;
			return 0;
		}
	}
	



	return 0;
}