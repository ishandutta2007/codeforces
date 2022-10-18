//test
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int g[MAXN + 1];
string s;

vector<pair<int, int>> segments; // [l, r]

int get(int k, int i) { // get k-th '1' on [i, |s|)
	--i;
	while (k --> 0) i = s.find('1', i + 1);
	return i;
}

void five() {
	int first = get(1, 0), last = get(5, 0);
	int r = (int)s.size() - 1;
	if (last - first + 1 == 5) { // creating 16: ['001111', '1', '0000']
		segments.emplace_back(0, last - 1);
		segments.emplace_back(last, last);
		if (last < r) segments.emplace_back(last + 1, r);
	} else { // creating 8: cut out '101' or '100' and cut everything in single digits
		int pos = s.find("101");
		if (pos == string::npos) pos = s.find("100");
		for (int i = 0; i < pos; ++i) segments.emplace_back(i, i);
		segments.emplace_back(pos, pos + 2);
		for (int i = pos + 3; i <= r; ++i) segments.emplace_back(i, i);
	}
}

void solve(int l, int r, int k, int n) { // [l; r]
	if (k == n) { // cutting into single digits
		for (int i = l; i <= r; ++i) segments.emplace_back(i, i);

	} else if (k == 2 && n == 3) {
		int pos = get(1, l);
		if (s[pos + 1] == '1') { // ['11', '00...00']
			segments.emplace_back(l, pos + 1);
			if (pos + 2 <= r) segments.emplace_back(pos + 2, r);

		} else { // ['10', '0001', '00000']
			int newpos = get(1, pos + 1);
			segments.emplace_back(l, pos + 1);
			segments.emplace_back(pos + 2, newpos);
			if (newpos + 1 <= r) segments.emplace_back(newpos + 1, r);
		}

	} else if (3 * k / 2 >= n) { // using previous if technique
		int pos = get(2, l);
		solve(l, pos, 2, 3);
		if (k > 2) solve(pos + 1, r, k - 2, n - 3);

	} else if ((k == 4 && n == 8) || (k == 9 && n == 16)) {
		int pos = get(1, l);
		string sub = s.substr(pos, 3);
		segments.emplace_back(l, pos + 2);
		if (sub == "100") solve(pos + 3, r, k - 1, n - 4);
		if (sub == "101") solve(pos + 3, r, k - 2, n - 5);
		if (sub == "110") solve(pos + 3, r, k - 2, n - 6);
		if (sub == "111") solve(pos + 3, r, k - 3, n - 7);

	} else if ((k == 7 && n == 11) || (k == 10 && n == 16)) {
		int mid = get(4, l);
		solve(l, mid, 4, 8);
		solve(mid + 1, r, k - 4, n - 8);

	} else { // common case
		int mid = get(k / 2, l);
		solve(l, mid, k / 2, n / 2);
		solve(mid + 1, r, k - k / 2, n / 2);

	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	g[1] = 1;
	for (int i = 2; i <= MAXN; ++i) g[i] = g[(i + 1) / 2] * 2;
	int T;
	cin >> T;
	while (T --> 0) {
		cin >> s;
		int k = count(s.begin(), s.end(), '1');
		if (!k) {
			cout << -1 << '\n';
			continue;
		}
		segments.clear();
		if (k == 5) five();
		else solve(0, (int)s.size() - 1, k, g[k]);
		cout << segments.size() << '\n';
		for (auto &[l, r] : segments) {
			cout << l + 1 << ' ' << r + 1 << '\n';
		}
	}
	return 0;
}