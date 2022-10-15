#include <bits/stdc++.h>

template <typename T> inline void Read(T& x) {
	int si = 1; char c = getchar(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = getchar();
	while(isdigit(c)) x = x * 10 + c - 48, c = getchar();
	x *= si;
}
template <typename T, typename... Args>
inline void Read(T& x, Args&... args) { Read(x); Read(args...); }

typedef long long ll;

int Abs(int x) { return x < 0 ? -x : x; }

int main() {
	int T; Read(T);
	while(T--) {
		int a, b, c, d, x, y, x1, y1, x2, y2;
		Read(a, b, c, d);
		Read(x, y, x1, y1, x2, y2);
		int nx = x - a + b, ny = y - c + d;
		if(nx >= x1 && nx <= x2 && ny >= y1 && ny <= y2 && (x - (a > 0) >= x1 || x + (b > 0) <= x2)
			&& (y - (c > 0) >= y1 || y + (d > 0) <= y2)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}