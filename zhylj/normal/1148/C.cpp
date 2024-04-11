#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 5e5 + 5;

int n, p[N], q[N];
std::vector <pii> ans;
void Do(int i, int j) {
	std::swap(q[p[i]], q[p[j]]);
	std::swap(p[i], p[j]);
	ans.push_back(mkp(i, j));
}
void Swap(int i, int j) {
	if(i > j) std::swap(i, j);
	if(j - i >= n / 2) Do(i, j);
	else if(i <= n / 2 && j <= n / 2) {
		Do(i, n);
		Do(j, n);
		Do(i, n);
	} else if(i <= n / 2) {
		Do(i, n); // 1 i j n => 1 n j i
		Do(n, 1); // 1 n j i => i n j 1
		Do(1, j); // i n j 1 => j n i 1
		Do(1, n); // j n i 1 => 1 n i j
		Do(n, i); // 1 n i j => 1 j i n
	} else {
		Do(i, 1);
		Do(j, 1);
		Do(i, 1);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(p[i]), q[p[i]] = i;
		for(int i = 1; i <= n; ++i)
			if(i != q[i]) Swap(i, q[i]);
		printf("%d\n", (int)ans.size());
		for(pii i : ans) printf("%d %d\n", i.fi, i.se);
	} return 0;
}