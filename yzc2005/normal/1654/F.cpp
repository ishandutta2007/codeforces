#include <bits/stdc++.h>
using namespace std;
const int P1 = 998244853, P2 = 1e9 + 9, B1 = 20051204, B2 = 20060223;
const int N = 1 << 18 | 5;
struct hash_t {
	int x, y;
	hash_t(int _x = 0, int _y = 0) : x(_x), y(_y) {}
	inline bool operator==(const hash_t &rhs) const { return x == rhs.x && y == rhs.y; }
	inline hash_t operator+(int v) { return hash_t((1ll * x * B1 + v) % P1, (1ll * y * B2 + v) % P2); }
	inline hash_t operator+(const hash_t &rhs) const { return hash_t((x + rhs.x) % P1, (y + rhs.y) % P2); }
	inline hash_t operator-(const hash_t &rhs) const { return hash_t((x - rhs.x + P1) % P1, (y - rhs.y + P2) % P2); }
	inline hash_t operator*(const hash_t &rhs) const { return hash_t(1ll * x * rhs.x % P1, 1ll * y * rhs.y % P2); }
} pw[N];
const hash_t B = hash_t(B1, B2);
int n; string s;
hash_t f[18][N];
inline bool cmp(int x, int y) {
	int i = 0;
	for (int k = n - 1; ~k; --k)
		if (f[k][i ^ x] == f[k][i ^ y]) i |= 1 << k;
	return s[x ^ i] < s[y ^ i];
}
int main() {
	pw[0] = hash_t(1, 1);
	for (int i = 1; i < N; ++i) pw[i] = pw[i - 1] * B;
	cin >> n >> s;
	for (int i = 0; i < 1 << n; ++i)
		f[0][i] = s[i];
	for (int k = 1; k < n; ++k) {
		hash_t coef = pw[1 << (k - 1)];
		for (int i = 0; i < 1 << n; ++i)
			f[k][i] = (f[k - 1][i] * coef) + f[k - 1][i ^ (1 << (k - 1))];
	}
	int ans = 0;
	for (int i = 1; i < 1 << n; ++i)
		if (cmp(i, ans)) ans = i;
	for (int i = 0; i < 1 << n; ++i)
		cout << s[ans ^ i];
	cout << "\n";
	return 0;
}