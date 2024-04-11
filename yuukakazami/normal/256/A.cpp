#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
int n;
const int MAX_N = 4000 + 10;
int a[MAX_N];

template<class T>
struct Index: public vector<T> {
	using vector<T>::erase;
	using vector<T>::begin;
	using vector<T>::end;
	void doit() {
		sort(begin(), end());
		erase(unique(begin(), end()), end());
	}
	int get(T x) {
		return lower_bound(begin(), end(), x) - begin();
	}
};
Index<int> idx;
int next[MAX_N][MAX_N];
int dp[MAX_N][MAX_N];

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		idx.push_back(a[i]);
	}
	if (n <= 2) {
		cout << n << endl;
		return 0;
	}
	idx.doit();
	for (int i = 0; i < n; ++i) {
		a[i] = idx.get(a[i]);
	}
	memset(next[n], -1, sizeof next[n]);
	for (int i = n - 1; i >= 0; --i) {
		memcpy(next[i], next[i + 1], sizeof next[i]);
		next[i][a[i]] = i;
	}
	for (int i = n - 1; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			dp[i][j] = 2;
			int nxt = next[j + 1][a[i]];
			if (nxt != -1) {
				dp[i][j] = dp[j][nxt] + 1;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
	return 0;
}