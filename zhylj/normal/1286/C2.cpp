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
const int N = 200 + 5;

int b[N][N];
char s[N];

void GetPart(int l, int r, char ret[]) {
	memset(b, 0, sizeof(b));
	printf("? %d %d\n", l, r);
	fflush(stdout);
	for(int i = 1; i <= (r - l + 1) * (r - l + 2) / 2; ++i) {
		scanf("%s", s + 1);
		int m = strlen(s + 1);
		for(int j = 1; j <= m; ++j)
			++b[m][s[j]];
	}
	if(r > l) {
		printf("? %d %d\n", l + 1, r);
		fflush(stdout);
		for(int i = 1; i <= (r - l + 1) * (r - l) / 2; ++i) {
			scanf("%s", s + 1);
			int m = strlen(s + 1);
			for(int j = 1; j <= m; ++j)
				--b[m][s[j]];
		}
	}
	for(int i = 1; i <= r - l + 1; ++i) {
		int c = -1;
		for(int j = 'a'; j <= 'z'; ++j)
			if(b[i][j]) c = j;
		ret[l - 1 + i] = c;
		for(int j = i + 1; j <= r - l + 1; ++j)
			--b[j][c];
	}
}

int n, d[N][N];
char t[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n);
		if(n <= 3) GetPart(1, n, t);
		else {
			GetPart(1, (n + 1) / 2, t);
			printf("? %d %d\n", 1, n);
			fflush(stdout);
			for(int i = 1; i <= n * (n + 1) / 2; ++i) {
				scanf("%s", s + 1);
				int m = strlen(s + 1);
				for(int j = 1; j <= m; ++j)
					++d[m][s[j]];
			}
			for(int i = 1; i <= n / 2; ++i)
				for(int j = 1; j <= (n + 1) / 2; ++j) 
					d[i][t[j]] -= std::min(j, i);
			for(int i = n / 2; i > 1; --i)
				for(int j = 'a'; j <= 'z'; ++j)
					d[i][j] -= d[i - 1][j];
			for(int i = 1; i < n / 2; ++i)
				for(int j = 'a'; j <= 'z'; ++j)
					d[i][j] -= d[i + 1][j];
			for(int i = 1; i <= n / 2; ++i) {
				int c = -1;
				for(int j = 'a'; j <= 'z'; ++j)
					if(d[i][j]) c = j;
				t[n - i + 1] = c;
			}
		}
		printf("! %s\n", t + 1);
	} return 0;
}