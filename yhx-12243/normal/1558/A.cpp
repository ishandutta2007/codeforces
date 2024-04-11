#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

const int N = 200054;

bool w[N];

void work() {
	int i, A, B, d;
	cin >> A >> B;
	memset(w, false, A + B + 1);
	if (A > B) std::swap(A, B);
	d = B - A;
	if (d & 1) {
		for (i = d / 2; i <= 2 * A + d / 2 + 1; ++i) w[i] = true;
	} else {
		for (i = d / 2; i <= 2 * A + d / 2; i += 2) w[i] = true;
	}
	cout << std::count(w, w + (A + B + 1), true) << '\n';
	for (i = 0; i <= A + B; ++i) if (w[i]) cout << i << ' ';
	cout << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}