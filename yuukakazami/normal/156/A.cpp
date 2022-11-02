#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	string s, u;
	cin >> s >> u;
	s = string(2002, '@') + s + string(2002, '@');
	int ans = 1000000;
	for (int i = 0; i + u.size() <= s.size(); ++i) {
		int cnt = 0;
		for (int j = 0; j < u.size(); ++j) {
			cnt += s[i + j] != u[j];
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}