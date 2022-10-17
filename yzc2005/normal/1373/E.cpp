#include <bits/stdc++.h>
using namespace std;
bool isless(string a, string b) {
	if(a.length() != b.length()) return a.length() < b.length();
	return a < b;
}
int main() {
	int t, n, k;
	for(cin >> t; t; --t) {
		string ans = "-1";
		cin >> n >> k, n -= k * (k + 1) / 2;
		if(n >= 0 && n % (k + 1) == 0) {
			int lst = min(9 - k, n / (k + 1));
			ans = ""; ans += (char)('0' + lst);
			int rest = n / (k + 1) - lst;
			for(int i = 1; i <= rest / 9; ++i) ans = '9' + ans;
			if(rest % 9) ans = (char)('0' + rest % 9) + ans;
		}
		for(int t = 0; t <= k; ++t) {
			for(int cnt = 1; ; ++cnt) {
				int m = n + 9 * t * cnt, lst = 9 - k + t;
				if((k + 1) * (9 * (cnt - 1) + lst) > m) break;
				if(m % (k + 1) != 0) continue;
				int rest = m / (k + 1) - lst;
				string res = ""; res += '0' + lst;
				for(int i = 1; i < cnt; ++i) res = '9' + res;
				if(rest >= 9) res = '8' + res, rest -= 8;
				for(int i = 1; i <= rest / 9; ++i) res = '9' + res;
				if(rest % 9) res = (char)('0' + rest % 9) + res;
				if(ans == "-1" || isless(res, ans)) ans = res; 
			}
		}
		cout << ans << '\n';
	}
	return 0;
}