#include <bits/stdc++.h>
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 100054;

int n, L, R;
int pred[N], succ[N];
int que[2][N];
int cnt = 0, result[N];
char s[N], *p = s;
vector seq[4], final;

inline void join(vector &A, const vector &B) {A.insert(A.end(), B.begin(), B.end());}

int main() {
	int i, j, v, h[2] = {0, 0}, t[2] = {0, 0}, ans;
	for (scanf("%s", s); *p; ++p) *p = (*p & 2) >> 1; ans = n = p - s;
	L = std::count(s, p, 0), R = std::count(s, p, 1);
	if (abs(L - R) > 1) throw "orzfy";
	memset(pred, -1, n << 2), memset(succ, -1, n << 2);
	for (p = s; p != s + n; que[*p][t[*p]++] = p - s, ++p)
		if (h[!*p] < t[!*p]) --ans, succ[ pred[p - s] = que[!*p][h[!*p]++] ] = p - s;
	printf("%d\n", ans - 1);
	for (i = 0; i < n; ++i)
		if (!~pred[i]) {for (j = i; ~succ[j]; j = succ[j]); seq[s[i] | s[j] << 1].EB(i);}
	assert(int(seq[0].size() + seq[1].size() + seq[2].size() + seq[3].size()) == ans);
	final.reserve(n);
	if (seq[0].empty() && seq[3].empty()) {
		if (!(seq[1].empty() || seq[2].empty())) {
			if (seq[1].front() > seq[2].front()) seq[1].swap(seq[2]);
			v = seq[1].front(), seq[1].front() = succ[v], succ[v] = seq[2].front(), seq[2].front() = v;
		}
		join(final = seq[1], seq[2]);
	} else {
		if (seq[0].size() < seq[3].size()) seq[0].swap(seq[3]), seq[1].swap(seq[2]);
		final = seq[2], final.EB(seq[0].back()), seq[0].pop_back(), join(final, seq[1]);
		for (v = 3; !seq[v].empty(); v ^= 3) final.EB(seq[v].back()), seq[v].pop_back();
	}
	for (int st : final) for (i = st; ~i; i = succ[i]) result[cnt++] = i;
	assert(cnt == n);
	for (i = 0; i < n; ++i) printf("%d%c", result[i] + 1, i == n - 1 ? 10 : 32);
	return 0;
}