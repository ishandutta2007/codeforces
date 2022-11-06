#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	long long int N, nums[4]; cin >> N >> nums[0] >> nums[1] >> nums[3] >> nums[2];
	int sums[4];
	int max_sum = 0;
	int min_sum = 1e9;
	for (int i = 0; i < 4; ++i) {
		sums[i] = nums[(i + 1)%4] + nums[i];
		max_sum = max(max_sum, sums[i]);
		min_sum = min(min_sum, sums[i]);
	}
	long long int ans = 0;
	if (max_sum - min_sum > N) {
		cout << 0 << endl;
		return 0;
	}
	ans = N*(N - (max_sum - min_sum));
	cout << ans << endl;

	return 0;
}