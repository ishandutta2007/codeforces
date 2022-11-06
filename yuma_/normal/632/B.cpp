#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	int N; cin >> N;
	vector<long long int>nums(N);
	
	for (int i = 0; i < N; ++i) {
		cin >> nums[i];
	}
	string st; cin >> st;
	long long int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (st[i] == 'B') {
			nums[i] = -nums[i];
		}
		else {
			sum += nums[i];
		}
	}
	long long int ans = 0;
	{
		long long int plus = 0;
		for (int i = 0; i < N; ++i) {
			plus -= nums[i];
			ans = max(ans, plus);
		}
	}
	{
		long long int plus = 0;
		for (int i = N-1; i >=0; --i) {
			plus -= nums[i];
			ans = max(ans, plus);
		}
	}
	cout << ans + sum << endl;
	return 0;
}