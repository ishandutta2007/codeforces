#include <bits/stdc++.h>
#define lg2 std::__lg
#define ctz __builtin_ctz
using std::cin;
using std::cout;

typedef unsigned int u32;
typedef std::pair <int, int> pr;
const int N = 10054;

int n, rank = 0, ans_len = 0, bak_len = 0;
int idp[32], pos[N];
u32 x[N], y[N], z[N];
pr ans[2003731], bak[2003731];

namespace linear {
	u32 lb[32], wb[32];

	inline bool insert(u32 x, u32 w) {
		for (int i; x; )
			if (lb[i = lg2(x)]) x ^= lb[i], w ^= wb[i];
			else return lb[i] = x, wb[i] = w, true;
		return false;
	}

	inline bool represent(u32 x) {
		for (int i; x; )
			if (lb[i = lg2(x)]) x ^= lb[i];
			else return false;
		return true;
	}

	inline u32 find_represent(u32 x) {
		u32 r = 0;
		for (int i; x; )
			if (lb[i = lg2(x)]) x ^= lb[i], r ^= wb[i];
			else throw "linear independent !";
		return r;
	}
}

inline void Xor_eq(int x, int y) {ans[ans_len++] = pr(x, y);}
inline void elim(int x, int y) {bak[bak_len++] = pr(idp[x], idp[y]);}
inline void swap(int x, int y) {if (x != y) elim(x, y), elim(y, x), elim(x, y);}

int main() {
	int i, j, k; u32 coef;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	for (i = 0; i < n; ++i)
		if (pos[i] = -1, cin >> x[i], !linear::represent(x[i]))
			idp[rank] = i, pos[i] = rank,
			linear::insert(x[i], 1u << rank++);
	for (i = 0; i < n; ++i)
		if (cin >> y[i], !linear::represent(y[i])) return cout << "-1\n", 0;
	for (i = 0; i < n; ++i) if (!~pos[i])
		for (coef = linear::find_represent(x[i] ^ y[i]); coef; coef &= coef - 1)
			Xor_eq(i, idp[ctz(coef)]);
	for (j = 0; j < rank; ++j) i = idp[j], z[j] = linear::find_represent(y[i]);
	for (k = i = 0; i < rank; ++i) {
		for (j = k; j < rank && ~z[j] >> i & 1; ++j);
		if (j == rank) continue;
		swap(k, j), std::swap(z[k], z[j]);
		for (j = 0; j < rank; ++j) if (j != k && z[j] >> i & 1) elim(j, k), z[j] ^= z[k];
		++k;
	}
	for (i = 0; i < rank; ++i)
		for (coef = z[i] ^ (1u << i); coef; coef &= coef - 1)
			Xor_eq(idp[i], idp[ctz(coef)]);
	ans_len = std::reverse_copy(bak, bak + bak_len, ans + ans_len) - ans,
	cout << ans_len << '\n';
	for (i = 0; i < ans_len; ++i) cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
	return 0;
}