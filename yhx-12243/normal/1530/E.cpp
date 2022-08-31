#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 100054;

int n;
char s[N], t[N];
int c[26], d[26];

inline int Not(int x) {
	int i;
	for (i = 0; i < 26; ++i) if (i != x && d[i]) return i;
	throw "error";
}

bool test(int a, int b) {
	int i, C1, C2; bool lv;
	memcpy(d, c, 104), --d[a], --d[b];
	if (a == b) {
		t[0] = t[1] = a, C1 = d[a], C2 = n - 2 - C1, lv = true;
		for (i = 2; i < n; ++i) {
			if (lv) {
				if (C1 > C2) return false;
				t[i] = Not(a), --d[t[i]], --C2, lv = false;
			} else {
				if (C1 > C2 + 1) return false;
				if (C1 == C2 + 1) t[i] = a, --d[a], --C1, lv = true;
				else t[i] = Not(-1), --d[t[i]], (lv = t[i] == a) ? --C1 : --C2;
			}
		}
	} else {
		t[0] = a, t[1] = b, lv = false;
		if (a > b) {
			for (i = 2; i < n; ++i) t[i] = Not(-1), --d[t[i]];
			return true;
		}
		if (d[a] + d[b] == n - 2) {
			memset(t + 2, b, d[b]);
			memset(t + 2 + d[b], a, d[a]);
			return true;
		}
		for (i = 2; i < n; ++i) {
			if (d[a]) t[i] = a, --d[a], lv = true;
			else if (lv) {
				if (d[b] == n - i) throw "error0";
				t[i] = Not(b), --d[t[i]], lv = false;
			} else {
				t[i] = Not(-1), --d[t[i]];
			}
		}
	}
	return true;
}

void work() {
	int i, j;
	cin >> s, n = strlen(s);
	std::sort(s, s + n), memset(c, 0, 104);
	for (i = 0; i < n; ++i) ++c[s[i] - 97];
	if (std::count(s, s + n, *s) == n || *std::max_element(c, c + 26) < 2) {cout << s << '\n'; return;}
	if ((j = std::find(c, c + 26, 1) - c) != 26) {
		std::iter_swap(s, std::find(s, s + n, char(97 + j)));
		std::sort(s + 1, s + n);
		cout << s << '\n';
		return;
	}
	for (i = 0; i < 26; ++i) if (c[i])
		for (j = 0; j < 26; ++j) if (c[j] > (i == j) && test(i, j)) {
			for (i = 0; i < n; ++i) t[i] += 97;
			t[n] = 0, cout << t << '\n'; return;
		}
	abort();
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}