#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int main() {
	string s;
	int n;
	cin >> s >> n;
	int cnt[26] = { };
	for (int i = 0; i < s.size(); ++i) {
		cnt[s[i] - 'a']++;
	}

	int tot = 0;
	for (int i = 0; i < 26; ++i) {
		if (cnt[i])
			++tot;
	}

	if (tot > n) {
		puts("-1");
		return 0;
	}

	int L = 0, R = s.size() + 10;

	while (L + 1 < R) {
		int M = (L + R) >> 1;
		int need = 0;
		for (int i = 0; i < 26; ++i) {
			if (cnt[i] > 0) {
				need += (cnt[i] - 1) / M + 1;
			}
		}
		if (need > n)
			L = M;
		else
			R = M;
	}

	cout << R << endl;
	string ans = "";
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] > 0) {
			int take = (cnt[i] - 1) / R + 1;
			while (take--)
				ans += char('a' + i);
		}
	}
	while (ans.size() < n)
		ans += char('a');
	cout << ans << endl;
	return 0;
}