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


int n, m, col[N], fa[N];
std::set <int> s_l[N], s_r[N];
void MergeSet(std::set <int> &A, std::set <int> &B) {
	if(A.size() < B.size()) std::swap(A, B);
	for(auto i : B) A.insert(i);
}
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
void Merge(int x, int y) {
	x = Find(x); y = Find(y);
	if(x != y) {
		fa[x] = y;
		MergeSet(s_l[y], s_l[x]);
		MergeSet(s_r[y], s_r[x]);
		col[y] = 0;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, m);
		for(int i = 0; i <= n + 1; ++i) {
			fa[i] = i;
			col[i] = 1;
		}
		int cnt = 0;
		for(int i = 1; i <= m; ++i) {
			int opt, x, y, z; rd(opt, x);
			if(opt) {
				++cnt;
				if(col[Find(x)] == 0) { printf("NO\n"); continue; }
				if(col[x] == -1) { printf("YES\n"); continue; }
				if(!col[Find(x + 1)]) {
					auto it = s_l[Find(x + 1)].upper_bound(x);
					if(it != s_l[Find(x + 1)].begin()) {
						--it;
						if((Find(*it) == Find(x - 1) && !col[Find(x - 1)]) || *it == x) { 
							//if(n == 10000 && m == 100000 && cnt == 3434) printf("A");
							printf("YES\n");
							continue;
						}
					}
				}
				if(!col[Find(x - 1)] && s_r[Find(x - 1)].count(x)) {
					//if(n == 10000 && m == 100000 && cnt == 3434) printf("B");
					printf("YES\n");
					continue;
				}
				printf("N/A\n");
			} else {
				rd(y, z);
				if(z == 0) {
					for(int j = x + 1; j <= y; j = Find(j) + 1)
						Merge(x, j);
					if(!col[Find(x - 1)])
						Merge(x - 1, x);
					if(!col[Find(y + 1)])
						Merge(y, y + 1);
					col[Find(x)] = 0;
				} else {
					s_l[Find(y)].insert(x);
					s_r[Find(x)].insert(y);
					if(x == y) col[x] = -1;
				}
			}
		}
	} return 0;
}