#include <bits/stdc++.h>
#define EB emplace_back
#define solve(expr) \
		for (cnt_buf = 0, i = 1; i <= n; ++i) if (!a[i]) buf[cnt_buf++] = i; \
		for (tmp.clear(), i = 1; i < cnt_buf; ++i) tmp.EB(buf[i]); \
		for (i = 0; i < cnt_buf; ++i) { \
			if (ask(tmp)) c = (expr), a[ buf[i] ] = c, pos[c] = buf[i]; \
			if (i < cnt_buf - 1) tmp[i] = buf[i]; \
		}
using std::cin;
using std::cout;
using std::endl;

typedef std::vector <int> vector;
const int N = 810;

int n;
int a[N], pos[N];
int cnt_buf = 0, buf[N];
int m2[N], m3[N], m5[N], m7[N], m8[N];

inline vector concat(const vector &u, const vector &v) {vector ret(u); return ret.insert(ret.end(), v.begin(), v.end()), ret;}

bool ask(const vector &v) {
	int r; cout << '?' << ' ' << v.size();
	for (int x : v) cout << ' ' << x;
	return cout << endl, cin >> r, r;
}

int finish() {
	cout << '!';
	for (int i = 1; i <= n; ++i) cout << ' ' << (a[1] <= n / 2 ? a[i] : n - a[i] + 1);
	return cout << endl, 0;
}

int main() {
	int i, j, c, e = 0; vector tmp, z[8];
//	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;

	solve(++e == 1 ? 1 : n) assert(e == 2); // solve 1, n
	if (n <= 2) return finish();

	for (i = 1; i <= n; ++i) if (!a[i]) m2[i] = ask({pos[1], i}); // modulo 2

	solve(m2[ buf[i] ] ? n - 1 : 2) // solve 2, n - 1
	if (n <= 4) return finish();

	solve(m2[ buf[i] ] ? 3 : n - 2) // solve 3, n - 2
	if (n <= 6) return finish();

	solve(m2[ buf[i] ] ? n - 3 : 4) // solve 4, n - 3
	if (n <= 8) return finish();

	// modulo 3
	z[0] = {pos[1], pos[2]};
	z[1] = {pos[1], pos[3]};
	z[2] = {pos[2], pos[3]};
	for (i = 1; i <= n; ++i) if (!a[i])
		for (j = 0; j < 3; ++j)
			if (ask(concat(z[j], {i}))) {m3[i] = (3 - j) % 3; break;}

	// modulo 5
	z[(0 + n) % 5] = {pos[1], pos[2], pos[3], pos[n - 1]};
	z[(1 + n) % 5] = {pos[1], pos[2], pos[3], pos[n]};
	z[(2 + n) % 5] = {pos[1], pos[2], pos[4], pos[n]};
	z[(3 + n) % 5] = {pos[1], pos[2], pos[3], pos[n - 3]};
	z[(4 + n) % 5] = {pos[1], pos[2], pos[3], pos[n - 2]};
	for (i = 1; i <= n; ++i) if (!a[i])
		for (j = 0; j < 5; ++j)
			if (ask(concat(z[j], {i}))) {m5[i] = (5 - j) % 5; break;}

	// modulo 7
	z[(0 + 3 * n) % 7] = {pos[1], pos[2], pos[3], pos[n - 3], pos[n - 2], pos[n - 1]};
	z[(1 + 3 * n) % 7] = {pos[1], pos[2], pos[3], pos[n - 3], pos[n - 2], pos[n]};
	z[(2 + 3 * n) % 7] = {pos[1], pos[2], pos[3], pos[n - 3], pos[n - 1], pos[n]};
	z[(3 + 3 * n) % 7] = {pos[1], pos[2], pos[3], pos[n - 2], pos[n - 1], pos[n]};
	z[(4 + 3 * n) % 7] = {pos[1], pos[2], pos[4], pos[n - 2], pos[n - 1], pos[n]};
	z[(5 + 3 * n) % 7] = {pos[1], pos[3], pos[4], pos[n - 2], pos[n - 1], pos[n]};
	z[(6 + 3 * n) % 7] = {pos[2], pos[3], pos[4], pos[n - 2], pos[n - 1], pos[n]};
	for (i = 1; i <= n; ++i) if (!a[i])
		for (j = 0; j < 7; ++j)
			if (ask(concat(z[j], {i}))) {m7[i] = (7 - j) % 7; break;}

	// modulo 4, 8
	for (i = 1; i <= n; ++i) if (!a[i])
		switch (m2[i] ? (ask({pos[1], pos[2], pos[4], i}) ? 1 : 3)
					  : (ask({pos[1], pos[2], pos[3], i}) ? 2 : 0)) {
			case 0: m8[i] = (ask({pos[1], pos[2], pos[3], pos[n - 3], pos[n - 2], pos[n - 1], pos[n], i}) ? 0 : 4); break;
			case 1: m8[i] = (ask({pos[2], pos[3], pos[4], pos[n - 3], pos[n - 2], pos[n - 1], pos[n], i}) ? 5 : 1); break;
			case 2: m8[i] = (ask({pos[1], pos[3], pos[4], pos[n - 3], pos[n - 2], pos[n - 1], pos[n], i}) ? 6 : 2); break;
			case 3: m8[i] = (ask({pos[1], pos[2], pos[4], pos[n - 3], pos[n - 2], pos[n - 1], pos[n], i}) ? 7 : 3); break;
		}

	for (i = 1; i <= n; ++i) if (!a[i])
		a[i] = (m3[i] * 280 + m5[i] * 336 + m7[i] * 120 + m8[i] * 105 - 1) % 840 + 1;

	return finish();
}