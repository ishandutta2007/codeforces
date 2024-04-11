#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 50;

ll p;
int q;
int a[N], b[N], c[N];

void work() {
	int i, j, k, cnt = 0; ll A, cur, max = 1;
	cin >> p >> q, A = p;
	for (i = 2; i * i <= q; ++i)
		if (!(q % i)) {
			for (j = 0; !(q % i); q /= i, ++j);
			for (k = 0; !(p % i); p /= i, ++k);
			a[cnt] = i, b[cnt] = j, c[cnt++] = k;
		}
	if (q > 1) {
		i = q;
		for (j = 0; !(q % i); q /= i, ++j);
		for (k = 0; !(p % i); p /= i, ++k);
		a[cnt] = i, b[cnt] = j, c[cnt++] = k;
	}
	for (i = 0; i < cnt; ++i) {
		if (b[i] > c[i]) cur = A;
		else for (cur = A, j = c[i] - b[i] + 1; j; --j) cur /= a[i];
		max = std::max(max, cur);
	}
	cout << max << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}