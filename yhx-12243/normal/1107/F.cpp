#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const int N = 508;

struct credit {
	int a, b, t; ll pf;
	friend std::istream & operator >> (std::istream &in, credit &B) {return in >> B.a >> B.b >> B.t, B.pf = std::max(B.a - (ll)B.b * B.t, 0ll), in;}
	inline bool operator < (const credit &B) const {return b > B.b;}
} c[N];

int n;
ll f[N];

inline void up(ll &x, const ll y) {x < y ? x = y : 0;}

int main() {
	int i, j;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i) cin >> c[i];
	std::sort(c, c + n);
	for (i = 0; i < n; *f += c[i++].pf)
		for (j = i; j >= 0; --j) up(f[j + 1] += c[i].pf, f[j] + c[i].a - (ll)c[i].b * j);
	cout << *std::max_element(f, f + (n + 1)) << '\n';
	return 0;
}