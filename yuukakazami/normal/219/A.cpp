#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	string s;
	int k;
	int cnt[26] = { };
	cin >> k >> s;
	for (int i = 0; i < s.size(); ++i) {
		cnt[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] % k != 0) {
			puts("-1");
			return 0;
		}
	}
	string r = "";
	for (int i = 0; i < 26; ++i) {
		for (int j = 0; j < cnt[i] / k; ++j) {
			r += char('a' + i);
		}
	}
	string ret = "";
	for (int i = 0; i < k; ++i) {
		ret += r;
	}
	cout << ret << endl;
	return 0;
}