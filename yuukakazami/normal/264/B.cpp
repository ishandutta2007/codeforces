#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
vector<int> ds[MAX_N];
int n;
int a[MAX_N];
int dp[MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	for (int i = 2; i < MAX_N; ++i) {
		for (int j = i; j < MAX_N; j += i)
			ds[j].push_back(i);
	}
	for (int i = 0; i < n; ++i) {
		int me = a[i];
		int h = 1;
		for (vector<int>::iterator e = ds[me].begin(); e != ds[me].end(); ++e) {
//			dp[*e] = max(dp[*e], dp[*e] + 1);
			h = max(h, dp[*e] + 1);
		}
		for (vector<int>::iterator e = ds[me].begin(); e != ds[me].end(); ++e) {
			dp[*e] = max(dp[*e], h);
		}
	}
	int ans = *max_element(dp, dp + MAX_N);
	if (ans == 0)
		ans = 1;
	cout << ans << endl;
	return 0;
}