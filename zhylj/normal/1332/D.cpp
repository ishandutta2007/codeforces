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

int main() {
	int k, M = 1; Read(k);
	printf("3 2\n");
	for(; M <= k; M <<= 1);
	M <<= 1;
	printf("%d %d\n%d %d\n%d %d\n", M - 1, (M - 1) ^ k, k, M - 1, 0, k);
	return 0;
}