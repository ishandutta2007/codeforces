#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	int dp[11000];
	memset(dp, 0, sizeof(dp));
	dp[0] = true;
	int a, b, c; cin >> a >> b >> c;
	for (int i = 0; i < 10000; ++i) {
		if (dp[i]) {
			dp[i + a] = true;
			dp[i + b] = true;
		}
	}
	if (dp[c]) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}