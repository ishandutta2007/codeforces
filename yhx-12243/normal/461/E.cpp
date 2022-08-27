#include <bits/stdc++.h>

typedef long long ll;
typedef std::vector <int> vector;
typedef ll mat[4][4], (*pmat)[4];
const int N = 200054;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll n;
int len;
char s[N];
vector all[4];
mat pw[64], cur, B1, B2;
pmat fy = *pw;

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

namespace SAM {
	int p, np = 1, cnt = 1;
	int pa[N], d[N][4], val[N], pos[N];

#define q d[p][x]
	int extend(int x) {
		for (p = np, val[np = ++cnt] = val[p] + 1; p && !q; q = np, p = pa[p]);
		if (!p) pa[np] = 1;
		else if (val[p] + 1 == val[q]) pa[np] = q;
		else {
			int nq = ++cnt; val[nq] = val[p] + 1;
			memcpy(d[nq], d[q], 16);
			pa[nq] = pa[q], pa[q] = pa[np] = nq;
			for (int Q = q; p && q == Q; q = nq, p = pa[p]);
		}
		return np;
	}
#undef q
	void init_pos() {
		int i, j, c; static bool used[N]; used[1] = true;
		for (i = cnt; i; --i) if (~pos[i])
			for (j = i; !used[j]; j = pa[j])
				pos[pa[j]] = pos[j], used[j] = true;
	}
}

void matmul(pmat a, pmat b, pmat ret) {
	int i, j, k;
	memset(B1, 63, sizeof(mat));
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j)
			for (k = 0; k < 4; ++k)
				down(B1[i][k], a[i][j] + b[j][k]);
	memcpy(ret, B1, sizeof(mat));
}

bool check(pmat a) {
	int i, j;
	for (i = 0; i < 4; ++i)
		for (j = 0; j < 4; ++j) if (a[i][j] < n) return false;
	return true;
}

int main() {
	int i, j, u, v, len_l, len_r, pos; ll ans = 0;
	vector::iterator it;
	scanf("%lld%s", &n, s), len = strlen(s);
	memset(SAM::pos, -1, sizeof SAM::pos);
	for (i = 0; i < len; ++i) all[int(s[i] -= 65)].push_back(i), SAM::pos[SAM::extend(s[i])] = i;
	SAM::init_pos();
	if (std::count(SAM::d[1], SAM::d[1] + 4, 0)) abort();
	memset(fy, 63, sizeof(mat));
	for (i = 2; i <= SAM::cnt; ++i) {
		len_l = SAM::val[SAM::pa[i]] + 1, len_r = SAM::val[i], pos = SAM::pos[i];
		for (u = 0; u < 4; ++u) {
			it = std::upper_bound(all[u].begin(), all[u].end(), pos - len_l + 1);
			if (it == all[u].begin() || *--it <= pos - len_r) continue;
			for (v = 0; v < 4; ++v) if (!SAM::d[i][v]) down(fy[u][v], pos - *it + 1);
		}
	}
	for (i = 0; !check(pw[i]); ++i) matmul(pw[i], pw[i], pw[i + 1]);
	memset(cur, 63, sizeof(mat)), cur[0][0] = cur[1][1] = cur[2][2] = cur[3][3] = 0;
	for (j = i - 1; j >= 0; --j)
		if (matmul(cur, pw[j], B2), !check(B2)) ans |= 1ll << j, memcpy(cur, B2, sizeof(mat));
	printf("%lld\n", ++ans);
	return 0;
}