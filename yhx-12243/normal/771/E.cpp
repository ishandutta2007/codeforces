#include <bits/stdc++.h>
using std::map;

typedef long long ll;
const int N = 300054;

int n;
int a[N], b[N];
int Ab[N], Bb[N], Cb[N];
map <ll, int> Am, Bm, Cm;
map <int, int> f[N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}

int dfs(int A, int B) {
	map <int, int>::iterator it; bool _;
	std::tie(it, _) = f[A].emplace(B, 0);
	if (!_) return it->second;
	int &ret = it->second, C = min(A, B); ret = 0;
	if (Ab[A] < Bb[B]) up(ret, dfs(A, Bb[B]) + 1);
	else if (~Ab[A]) up(ret, dfs(Ab[A], B) + 1);
	if (~Cb[C]) up(ret, dfs(Cb[C], Cb[C]) + 1);
	return ret;
}

int main() {
	int i; ll A = 0, B = 0, C = 0; bool ret;
	map <ll, int>::iterator it;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i) scanf("%d", a + i);
	for (i = 1; i <= n; ++i) scanf("%d", b + i);
	for (i = 0; i <= n; ++i)
		std::tie(it, ret) = Am.emplace(A += a[i], i),
		ret ? Ab[i] = -1 : (Ab[i] = it->second, it->second = i),
		std::tie(it, ret) = Bm.emplace(B += b[i], i),
		ret ? Bb[i] = -1 : (Bb[i] = it->second, it->second = i),
		std::tie(it, ret) = Cm.emplace(C += a[i] + b[i], i),
		ret ? Cb[i] = -1 : (Cb[i] = it->second, it->second = i);
	for (i = 1; i <= n; ++i)
		up(Ab[i], Ab[i - 1]), up(Bb[i], Bb[i - 1]), up(Cb[i], Cb[i - 1]);
	printf("%d\n", dfs(n, n));
	return 0;
}