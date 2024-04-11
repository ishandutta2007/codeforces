#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 300054;

int n, K;
char s[N];

bool check() {
	int i, j, c, w[2] = {0};
	for (i = 0; i < K; ++i) {
		c = -1;
		for (j = i; j < n; j += K)
			switch (s[j]) {
				case 48: if (c == 1) return false; c = 0; break;
				case 49: if (c == 0) return false; c = 1; break;
			}
		if (~c) ++w[c];
	}
	return w[0] <= K / 2 && w[1] <= K / 2;
}

void work() {
	cin >> n >> K >> s;
	cout << (check() ? "YES\n" : "NO\n");
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}