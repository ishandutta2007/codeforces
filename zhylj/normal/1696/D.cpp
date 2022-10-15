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

int n, a[N], d[N], st_1[N], st_2[N], top_1, top_2;
std::vector <int> E[N];
std::queue <int> que;
void Add(int u, int v) {
	E[u].push_back(v);
	E[v].push_back(u);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		for(int i = 1; i <= n; ++i) rd(a[i]), d[i] = n;
		for(int i = 1; i <= n; ++i) E[i].clear();
		top_1 = top_2 = 0;
		for(int i = 1; i <= n; ++i) {
			while(top_1 && a[st_1[top_1]] > a[i]) --top_1;
			while(top_2 && a[st_2[top_2]] < a[i]) --top_2;
			if(i != 1) {
				if(st_1[top_1] < st_2[top_2])
					Add(i, *std::lower_bound(st_2 + 1, st_2 + top_2 + 1, st_1[top_1]));
				else Add(i, *std::lower_bound(st_1 + 1, st_1 + top_1 + 1, st_2[top_2]));
			}
			st_1[++top_1] = i;
			st_2[++top_2] = i;
		}
		d[1] = 0;
		que.push(1);
		while(!que.empty()) {
			int u = que.front(); que.pop();
			for(int v : E[u]) if(d[v] == n) {
				d[v] = d[u] + 1;
				que.push(v);
			}
		}
		printf("%d\n", d[n]);
	} return 0;
}