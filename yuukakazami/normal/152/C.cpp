#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

const int MOD = int(1e9) + 7;
typedef long long ll;

int main() {
	int n, m;
	cin >> n >> m;
	set<char> have[200];

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			have[j].insert(s[j]);
		}
	}

	ll ans = 1;
	for (int i = 0; i < m; ++i) {
		ans *= have[i].size();
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}