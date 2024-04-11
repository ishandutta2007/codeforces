#include <bits/stdc++.h>
#define EB emplace_back
using std::cin;
using std::cout;
using std::vector;

const int N = 100054;

int s[N];
vector <int> f[N];

namespace zig {
	void push(int i) {
		f[i].clear();
		if (s[i - 1] == s[i]) f[i].EB(1);
		for (int h : f[i - 1]) if (s[i - 2 * h - 1] == s[i]) f[i].EB(h + 1);
	}

	int check(int i) {
		if (f[i].empty()) return 0;
		int h = f[i].front();
		return std::binary_search(f[i - h].begin(), f[i - h].end(), h) ? h : 0;
	}
}

namespace misc {
	int suf[N], preP[N], preC[N];

	void push(int i) {
		int L;
		suf[i] = (f[i].empty() ? 0 : f[i].front()), preP[i] = preP[i - 1], preC[i] = preC[i - 1];
		if (!((L = i - preP[i]) & 1) && std::binary_search(f[i].begin(), f[i].end(), L >>= 1))
			preP[i] += L, ++preC[i];
	}

	int query_suf(int i) {
		int j, ret = preC[i], L = preP[i];
		for (j = i; suf[j] && L < j - suf[j]; j -= suf[j]) ++ret;
		return ret;
	}
}

int main() {
	int i, h, n, x, Z = 0, top = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n, *s = -1;
	for (i = 0; i < n; ++i) {
		cin >> x, s[++top] = x, zig::push(top);
		if ((h = zig::check(top))) ++Z, top -= 2 * h;
		else misc::push(top);
		cout << 2 * Z + misc::query_suf(top) << (i == n - 1 ? '\n' : ' ');
	}
	return 0;
}