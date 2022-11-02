#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <string>
#include <vector>
#include <utility>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > a;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		a.push_back(make_pair(x, 0));
	}
	int ret = 0;
	while (!a.empty()) {
		sort(a.begin(), a.end());
		if (a.back().first < k || a.back().second == 3) {
			ret += a.back().first;
			a.pop_back();
		} else {
			a.back().first -= k;
			a.back().second++;
			if (a.back().first == 0)
				a.pop_back();
		}
	}
	cout << ret << endl;
}