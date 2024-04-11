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
const int N = 5e5 + 5; //  1e5.

int Mex(std::vector <int> v) {
	std::sort(v.begin(), v.end());
	int x = 0;
	for(int i : v) if(i == x) ++x;
	return x;
}

int n, cnt, f[N], g[N], sg[N];
char s[N];

char b[N] = "0011203110332240522330113021104527401120311033224455233011302110453748",
	c[N] = "1120311033224455933011302110453748";

//1 1 2 0 3 1 1 0 3 3 2 2 4 0 5 2 2 3 3 0 1 1 3 0 2 1 1 0 4 5 2 7 4 0 1 1 2 0 3 1 1 0 3 3 2 2 4 4 5 5 2 3 3 0 1 1 3 0 2 1 1 0 4 5 3 7 4 8 1 1 2 0 3 1 1 0 3 3 2 2 4 4 5 5 9 3 3 0 1 1 3 0 2 1 1 0 4 5 3 7 4 8

void Init() {
	for(int i = 2; i < N; ++i) {
		if(i < 70) sg[i] = b[i] - '0';
		else sg[i] = c[(i - 70) % 34] - '0';
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	Init();
	while(test_case_cnt--) {
		rd(n);
		scanf("%s", s + 1);
		cnt = 0;
		for(int i = 1; i <= n; ++i) {
			if(s[i] == 'R') ++cnt;
			else --cnt;
		}
		if(cnt > 0) {
			printf("Alice\n");
		} else if(cnt < 0) {
			printf("Bob\n");
		} else {
			for(int i = 1; i < n; ++i)
				g[i] = (s[i] != s[i + 1]);
			g[n] = 0;
			int xor_s = 0;
			for(int i = 1, j = 0; i <= n; ++i) {
				++j;
				if(!g[i]) {
					xor_s ^= sg[j];
					j = 0;
				}
			}
			printf(xor_s ? "Alice\n" : "Bob\n");
		}
	} return 0;
}