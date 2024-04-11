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

int n, q;
char str[N];

bool Check(int i) {
	if(i + 2 > n || i <= 0) return false;
	if(str[i] == 'a' && str[i + 1] == 'b' && str[i + 2] == 'c')
		return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		rd(n, q);
		scanf("%s", str + 1);
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			if(Check(i)) ++cnt;
		while(q--) {
			int pos; rd(pos);
			char c[10]; scanf("%s", c);
			for(int i = pos - 2; i <= pos; ++i)
				cnt -= Check(i);
			str[pos] = c[0];
			for(int i = pos - 2; i <= pos; ++i)
				cnt += Check(i);
			printf("%d\n", cnt);
		}
	} return 0;
}