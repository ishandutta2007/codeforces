#include <bits/stdc++.h>

typedef long long ll;
const int N = 100054;

int n, T;
int lb[N], ub[N], score[N], real[N];
bool fixed[N];
ll S, Lb[N], Ub[N];

inline void down(ll &x, const ll y) {x > y ? x = y : 0;}
inline int max(const int x, const int y) {return x < y ? y : x;}
inline ll max(const ll x, const ll y) {return x < y ? y : x;}

inline bool test(int *_arg) {
	int i, j; ll sum = 0;
	for (i = 0, j = n; i <= T; ++i, sum += j) {
		for (; j && _arg[j - 1] <= i; sum += _arg[--j] - i);
		if (sum < max(Lb[i], S - Ub[i])) return false;
	}
	return true;
}

inline ll allocate(int l, int r, int limit, ll sum) {
	int width = r - l + 1, base = real[l]; lldiv_t res;
	down(sum, (ll)limit * width), res = lldiv(sum, width);
	std::fill(real +  l, real + (l + res.rem), base + res.quot + 1);
	std::fill(real + (l + res.rem), real + (r + 1), base + res.quot);
	return sum;
}

bool check(int count, int value) {
	int i, j, _1, _rg, _crg; ll remain;
	_1 = std::count(score, score + count, -1);
	_rg = max(*std::max_element(score, score + n), 0);
	_crg = std::count(score, score + count, _rg);
	if (_1 + _crg != count || (_crg && _rg < value)) return false;
	if (!_crg) _rg = value;

	std::fill(real, real + count, _rg), memset(fixed, true, count);
	for (i = n - 1; i >= count; --i) real[i] = ((fixed[i] = (bool)~score[i]) ? score[i] : real[i + 1]);
	if ((remain = -std::accumulate(real, real + n, -S)) < 0) return false;

	for (j = n, i = n - 1; i >= count; --i)
		if (fixed[i])
			i == --j || (remain -= allocate(i + 1, j, real[i] - real[j], remain), j = i);
	if (count != j) remain -= allocate(count, j - 1, real[count - 1] - real[j], remain);

	return remain ? !_crg && (value += (remain + j - 1) / j) <= T && check(count, value) : test(real);
}

int main() {
	int i, c, L, R, M;
	scanf("%d%d", &T, &n), memset(score, -1, (n + 1) << 2), score[n] = 0;
	for (i = 0; i < T; ++i) scanf("%d%d", lb + i, ub + i);
	std::sort(lb, lb + T, std::greater <int> ());
	std::sort(ub, ub + T, std::greater <int> ());
	for (i = T - 1; i >= 0; --i) Lb[i] = Lb[i + 1] + lb[i], Ub[i] = Ub[i + 1] + ub[i];
	for (i = T; i >= 0; --i) Lb[i] = *Lb - Lb[i];
	for (scanf("%d", &L); L; --L) scanf("%d%d", &i, &R), score[--i] = R;
	scanf("%lld", &S);
	for (L = 0, R = n; L < R; check(M = (L + R + 1) / 2, 0) ? L = M : (R = M - 1));
	if (!L) return puts("-1 -1"), 0;
	for (c = L, L = 0, R = T; L < R; check(c, M = (L + R + 1) / 2) ? L = M : (R = M - 1));
	printf("%d %d\n", c, L);
	return 0;
}