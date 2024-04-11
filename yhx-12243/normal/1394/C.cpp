#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::string;

typedef std::pair <int, int> pr;
const int N = 500054;

int n;
pr a[N];
char s[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}

pr find(int radius) {
	int i, x, y, Lx = INT_MIN, Rx = INT_MAX, Ly = INT_MIN, Ry = INT_MAX, Lyx = INT_MIN, Ryx = INT_MAX;
	for (i = 0; i < n; ++i) {
		std::tie(x, y) = a[i];
		up(Lx, x - radius), down(Rx, x + radius);
		up(Ly, y - radius), down(Ry, y + radius);
		up(Lyx, y - x - radius), down(Ryx, y - x + radius);
	}
	if (Lx > Rx || Ly > Ry || Lyx > Ryx || Ryx < Ly - Rx || Lyx > Ry - Lx) return pr(INT_MIN, INT_MIN);
	if (Lyx <= Ly - Rx) return pr(Rx, Ly);
	if (Lyx <= Ry - Rx) return pr(Rx, Lyx + Rx);
	return pr(Ry - Lyx, Ry);
}

int main() {
	int i, x, y, L, R, M;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i)
		cin >> s, L = strlen(s), a[i] = pr(std::count(s, s + L, 'B'), std::count(s, s + L, 'N'));
	for (L = 0, R = 1000000; L < R; )
		std::tie(x, y) = find(M = (L + R) / 2),
		x != INT_MIN ? R = M : L = M + 1;
	std::tie(x, y) = find(L), up(x, 0), up(y, 0);
	if (!(x || y)) x = 1;
	memset(s, 66, x), memset(s + x, 78, y), s[x + y] = 10, s[x + y + 1] = 0;
	cout << L << '\n' << s;
	return 0;
}