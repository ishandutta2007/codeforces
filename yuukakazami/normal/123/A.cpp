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

int f[1010], n, c[1010];

int fd(int x) {
	return x == f[x] ? x : (f[x] = fd(f[x]));
}

bool cmp(int a, int b) {
	return c[a] > c[b];
}

int main() {
	string s;
	cin >> s;
	n = s.size();
//	cin >> n;
	for (int i = 1; i <= n; ++i) {
		f[i] = i;
	}
	for (int p = 2; p <= n; ++p) {
		bool is = true;
		for (int i = 2; i < p; ++i) {
			if (p % i == 0) {
				is = false;
			}
		}
		if (is) {
			for (int i = 1; i * p <= n; ++i) {
				int a = fd(p), b = fd(p * i);
				f[a] = b;
			}
		}
	}
	memset(c, 0, sizeof c);
	for (int i = 1; i <= n; ++i) {
		c[fd(i)]++;
	}
	vector<int> a;
	for (int i = 1; i <= n; ++i) {
		if (c[i] > 0)
			a.push_back(i);
	}
	sort(a.begin(), a.end(), cmp);
	vector<pair<int, char> > let;
	for (char ch = 'a'; ch <= 'z'; ++ch) {
		int ct = count(s.begin(), s.end(), ch);
		if (ct > 0) {
			let.push_back(make_pair(ct, ch));
		}
	}

	string ret(s.size(), '?');
	for (int i = 0; i < a.size(); ++i) {
		int it = a[i];
		sort(let.rbegin(), let.rend());
		if (let[0].first < c[it]) {
			cout << "NO" << endl;
			return 0;

		}
		let[0].first -= c[it];
		for (int j = 1; j <= n; ++j) {
			if (fd(j) == it) {
				ret[j - 1] = let[0].second;
			}
		}
	}
	cout << "YES" << endl;
	cout << ret << endl;
}