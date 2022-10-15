#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }
template <typename T> inline void Write(T x) { if(x / 10) Write(x / 10); putchar(x % 10 + 48); }
template <typename T, typename... Args> inline void Write(T x, Args... args) {
	Write(x); putchar(' '); Write(args...);
}
template<typename T> inline T Abs(T x) { return x > 0 ? x : -x; }

const int kN = 105;

int a[kN];

int main() {
	int t;
	Read(t);
	while(t--) {
		int n; Read(n);
		for(int i = 1; i <= n; ++i) Read(a[i]);
		std::sort(a + 1, a + n + 1, [](int x, int y) { return x > y; });
		for(int i = 1; i <= n; ++i) Write(a[i]), putchar(' ');
		putchar('\n');
	}
	return 0;
}