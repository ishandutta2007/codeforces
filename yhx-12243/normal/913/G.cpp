#include <bits/stdc++.h>
using std::cin;
using std::cout;

typedef long long ll;
const ll mod = 762939453125ll, iv2 = 381469726563ll, iv4 = 572204589844ll, iv8 = 286102294922ll, iv16 = 143051147461ll;
const ll step[17] = {0ll, 143051147461ll, 518550950801ll, 713454200876ll, 289665379376ll,
120490959376ll, 609681359376ll, 177313046876ll, 62590625001ll, 312953125001ll,
38886718751ll, 194433593751ll, 209228515626ll, 283203125001ll, 653076171876ll,
213623046876ll, 305175781251ll};

ll PowerMod(ll a, int n, ll c = 1) {for (; n; n >>= 1, a = a * a % mod) if (n & 1) c = c * a % mod; return c;}

inline ll MulMod(ll a, ll b, ll m){
	ll t = (a * b - (ll)((long double)a * b / m) * m) % m;
	return t + (t >> 63 & m);
}

ll PowerMod(ll a, ll n, ll m) {
	if (!n || a == 1) return 1ll;
	ll s = PowerMod(a, n >> 1, m);
	return s = MulMod(s, s, m), n & 1 ? MulMod(s, a, m) : s;
}

ll pohlig_hellman(ll n) {
	int i; ll bs = -1, pw = 4, expo = 30517578125ll;
	switch (n % 5) {
		case 1: bs = 0; break;
		case 2: bs = 1, n = MulMod(n, iv2, mod); break;
		case 3: bs = 3, n = MulMod(n, iv8, mod); break;
		case 4: bs = 2, n = MulMod(n, iv4, mod); break;
	}
	assert(~bs);
	for (i = 1; i < 17; ++i, pw *= 5, expo /= 5)
		for (; PowerMod(n, expo, mod) != 1; n = MulMod(n, step[i], mod), bs += pw);
	return bs;
}

void work() {
	ll n;
	cin >> n, n = ((n * 1000000 - 1) | 131071) + 1;
	n = (n >> 17) + !(n % 5);
	cout << pohlig_hellman(n) + 17 << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}