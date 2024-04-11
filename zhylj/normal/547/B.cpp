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

const int kN = 2e5 + 5;

int a[kN], ls[kN], rs[kN], d[kN], st[kN], top = 0;

int main() {
	int n; rd(n);
	for(int i = 1; i <= n; ++i) rd(a[i]);
	st[top = 1] = 0;
	for(int i = 1; i <= n; ++i) {
		while(top && a[st[top]] >= a[i]) --top;
		ls[i] = st[top];
		st[++top] = i;
	}
	st[top = 1] = n + 1;
	for(int i = n; i; --i) {
		while(top && a[st[top]] >= a[i]) --top;
		rs[i] = st[top];
		st[++top] = i;
	}
	for(int i = 1; i <= n; ++i) {
		int siz = rs[i] - ls[i] - 1;
		d[siz] = std::max(d[siz], a[i]);
	}
	for(int i = n; i; --i) d[i] = std::max(d[i + 1], d[i]);
	for(int i = 1; i <= n; ++i) printf("%d ", d[i]);
	return 0;
}