#include <bits/stdc++.h>
#define EB emplace_back
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef long long ll;
const int N = 400054, mod = 998244353;

int n, K;
int h[N], v[N];
int fact[N], finv[N];
std::set <int> S;

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

void init() {
	int i;
	for (*fact = i = 1; i < N; ++i) fact[i] = (ll)fact[i - 1] * i % mod;
	--i, finv[i] = PowerMod(fact[i], mod - 2);
	for (; i; --i) finv[i - 1] = (ll)finv[i] * i % mod;
}

namespace pb_ds {
	int cnt;
	std::set <int> S;
	struct node {int v, lc, rc;} x[4000000];

	void init() {
		cnt = 1, x[1] = x[0], S.clear(), S.emplace(n + 1);
	}

	int add(int id, int L, int R, int h, int v) {
		if (!id) id = ++cnt, x[id] = x[0];
		x[id].v += v;
		if (L == R) return id;
		int M = (L + R - 1) / 2;
		h <= M ? x[id].lc = add(x[id].lc, L, M, h, v) : x[id].rc = add(x[id].rc, M + 1, R, h, v);
		return id;
	}

	int get(int kth) {
		int id = 1, L = 1, R = n, M, left;
		for (; L < R; ) {
			M = (L + R - 1) / 2, left = M - L + 1;
			if (x[id].lc) left -= x[id].lc[x].v;
			if (kth > left) kth -= left, L = M + 1, id = x[id].rc;
			else R = M, id = x[id].lc;
		}
		return L;
	}

	void set(int x) {S.emplace(x), add(1, 1, n, x, 1);}
}


void work() {
	int i, pos, right, spaces, ans;
	cin >> n >> K, ans = n - K - 1, pb_ds::init();
	for (i = 0; i < K; ++i) cin >> h[i] >> v[i];
	for (i = K - 1; i >= 0; --i) {
		pos = pb_ds::get(v[i]), pb_ds::set(pos);
		if (pb_ds::S.count(pos + 1)) ++ans;
		else {
			spaces = n - (K - i);
			right = (n - h[i]) - (K - i - 1);
			ans += v[i] + right > spaces;
		}
	}
	cout << int((ll)fact[n + ans] * finv[n] % mod * finv[ans] % mod) << '\n';
}

int main() {
	int T; init();
	std::ios::sync_with_stdio(false), cin.tie(nullptr);
	for (cin >> T; T; --T) work();
	return 0;
}