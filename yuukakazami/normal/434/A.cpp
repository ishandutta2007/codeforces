#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, m, a[MAX_N];
vector<int> near[MAX_N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		cin >> a[i];
		if (i > 0 && a[i] != a[i - 1]) {
			near[a[i]].push_back(a[i - 1]);
			near[a[i - 1]].push_back(a[i]);
		}
	}
	long long sum = 0, ans;
	for (int i = 1; i < m; ++i) {
		sum += abs(a[i] - a[i - 1]);
	}
	ans = sum;
//	cout << ans << endl;

	for (int it = 1; it <= n; ++it) {
		//change it
		vector<int> vec = near[it];
		if (vec.empty())
			continue;
		sort(vec.begin(), vec.end());
		int x = vec[vec.size() / 2];
		long long ret = sum;
		for (int i = 0; i < vec.size(); ++i) {
			ret += abs(vec[i] - x) - abs(vec[i] - it);
		}
		ans = min(ans, ret);
	}
	cout << ans << endl;
}