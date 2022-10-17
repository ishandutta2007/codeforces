#include <bits/stdc++.h>

template <typename T> inline void rd(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

#define fi first
#define se second

typedef long long ll;
typedef double ff;
typedef std::pair<int, int> pii;

const int kN = 5e5 + 5;

int md[kN];

int main() {
	int n; rd(n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 2; j * j <= i; ++j)
			if(i % j == 0) { md[i] = i / j; break; }
		if(!md[i]) md[i] = 1;
	}
	std::sort(md + 1, md + n + 1);
	for(int i = 2; i <= n; ++i) printf("%d ", md[i]);
	return 0;
}