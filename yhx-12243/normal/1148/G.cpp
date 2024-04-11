#include <bits/stdc++.h>
#define EB emplace_back
#define ctz __builtin_ctz

typedef signed char s8;
typedef std::vector <int> vector;
const int N = 100054, MAX = 10000054;

int n, K, ti = 0;
int a[N], f_[MAX], tag[MAX];
int bel[N], buf[N * 2];
bool major[N];
vector D[N], branch[N];
int cI = 0, I[N];
int cJ = 0, J[N];
int ans[N], *tail = ans;
int pn = 0, c[MAX], p[666666];
s8 mu[MAX];

inline int & f(int pos) {return tag[pos] == ti ? f_[pos] : (tag[pos] = ti, f_[pos] = 0);}

void sieve(int n) {
	int i, j, v; mu[1] = 1;
	memset(c, -1, sizeof c);
	for (i = 2; i <= n; ++i) {
		if (!~c[i]) p[pn] = i, c[i] = pn++, mu[i] = -1;
		for (j = 0; (v = i * p[j]) <= n && j < c[i]; ++j) c[v] = j, mu[v] = -mu[i];
		if (v <= n) c[v] = j;
	}
}

void factor(vector &ret, int n) {
	int i;
	for (ret.clear(); n != 1; )
		for (i = c[n], ret.EB(p[i]); !(n % p[i]); n /= p[i]);
}

vector subsets(const vector &div) {
	int i, n = div.size(); vector ret; ret.EB(1), ret.reserve(1 << n);
	for (i = 1; i < 1 << n; ++i) ret.EB(ret[i & (i - 1)] * div[ctz(i)]);
	return ret;
}

void partition(int L, int R, int *_beg, int *_end) {
	if (_beg == _end) return;
	if (L + 1 == R) {for (; _beg != _end; ++_beg) bel[*_beg] = I[L]; return;}
	int i, s, M = (L + R) / 2, *_mid, *p, *p1 = buf, *p2 = buf + N; ++ti;
	for (i = L; i < M; ++i)
		for (int d : subsets(D[i])) f(d) += mu[d];
	for (p = _beg; p != _end; ++p) {
		s = 0;
		for (int d : subsets(D[*p])) s += f(d);
		(s ? *p1++ : *p2++) = *p;
	}
	_mid = _beg + (p1 - buf),
	memcpy(_beg, buf, (_mid - _beg) << 2), memcpy(_mid, buf + N, (_end - _mid) << 2),
	partition(L, M, _beg, _mid), partition(M, R, _mid, _end);
}

int main() {
	int i, s; sieve(MAX - 1);
	scanf("%d%d", &n, &K);
	for (i = 0; i < n; ++i) {
		scanf("%d", a + i), factor(D[i], a[i]), s = 0;
		vector &&dt = subsets(D[i]);
		for (int d : dt) s += f(d);
		if ((major[i] = !s)) {
			I[cI++] = i;
			for (int d : dt) f(d) += mu[d];
		} else J[cJ++] = i;
	}
	if (cI >= K) {
		for (i = 0; i < K; ++i) printf("%d%c", I[i] + 1, i == K - 1 ? 10 : 32);
		return 0;
	}
	partition(0, cI, J, J + cJ);
	for (s = i = 0; i < n; ++i) branch[ major[i] ? i : bel[i] ].EB(i);
	std::sort(I, I + cI, [] (const int x, const int y) {return branch[x].size() > branch[y].size();});
	assert(branch[*I].size() > 2);
	for (i = 0; i < cI; ++i) tail = std::copy(branch[ I[i] ].begin(), branch[ I[i] ].end(), tail);
	for (i = 0; i < cI; ++i) if ((s += branch[i].size()) > K) break;
	assert(branch[i].size() > 1);
	tail = (s == K + (int)branch[i].size() - 1 ? ans + 1 : ans);
	for (i = 0; i < K; ++i) printf("%d%c", tail[i] + 1, i == K - 1 ? 10 : 32);
	return 0;
}