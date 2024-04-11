#include <bits/stdc++.h>
#define EB emplace_back

typedef long long ll;
typedef std::pair <int, int> fragment;
typedef std::vector <int> vector, *pvector;
typedef std::map <fragment, pvector> map;
const int N = 200054, mod = 900000011;

ll base;
int n;
char s[N];
int ha[N], pw[N];
fragment mid[N];
map f[N];

namespace Alloc {
	vector buf[2003731 * 2]; pvector cur = buf;
	inline pvector alloc() {return cur++;}
}

inline fragment getHash(int L, int R) {
	int J = (ha[R] - (ll)ha[L] * pw[R - L]) % mod;
	return fragment(R - L, J + (J >> 31 & mod));
}

void insert(map &M, const fragment &key, int value) {
	map::iterator it = M.find(key);
	if (it == M.end()) {pvector t = Alloc::alloc(); t->EB(value), M.emplace(key, t);}
	else it->second->EB(value);
}

int main() {
	int i, j, u, v, z, l; pvector t;
	// ---- random begin ---- //
	char *_ = new char; std::mt19937 gen(time(NULL) + (size_t)_);
	base = gen() % (mod / 2) + mod / 4, delete _;
	// ---- random end ---- //
	scanf("%d%s", &n, s);
	for (*pw = 1, i = 0; i < n; ++i)
		ha[i + 1] = (ha[i] * base + (s[i] - 97)) % mod, pw[i + 1] = pw[i] * base % mod;
	for (i = 0; i < n; ++i) insert(*f, getHash(i, i + 1), i);
	for (i = 0; i < n; ++i)
		for (const auto &p : f[i]) {
			l = p.first.first, t = p.second, z = t->size();
			fprintf(stderr, "[level %d] string with (len=%d, hash=%d):\n", i, l, p.first.second);
			for (j = 1; j < z; ++j)
				mid[j] = getHash(t->at(j - 1) + l, t->at(j));
			for (u = 0; (v = u + 1) < z; u = v) {
				for (; v < z - 1 && mid[v] == mid[v + 1]; ++v);
				insert(f[i + v - u], getHash(t->at(u), t->at(v) + l), t->at(u));
			}
		}
	for (z = n - 1; z && f[z].empty(); --z);
	printf("%d\n", ++z);
	return 0;
}