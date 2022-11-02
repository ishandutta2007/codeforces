#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <numeric>
#include <vector>
using namespace std;
int n, k;
const int MAX_N = 1000 + 10;
int a[MAX_N];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = -(1 << 30);
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			//[i,j]
			vector<int> x, y;
			for (int k = 0; k < n; ++k) {
				if (k < i || k > j)
					y.push_back(a[k]);
				else
					x.push_back(a[k]);
			}
			sort(x.begin(), x.end()), sort(y.begin(), y.end());
			for (int i = 0; i < k && i < x.size() && i < y.size(); ++i) {
				if (x[i] < y[y.size() - 1 - i]) {
					swap(x[i], y[y.size() - 1 - i]);
				} else
					break;
			}
			ans = max(ans, accumulate(x.begin(), x.end(), 0));
		}
	}
	cout << ans << endl;
}