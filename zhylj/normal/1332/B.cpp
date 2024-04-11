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

const int kN = 1005;

int a[kN], col[kN], pr[kN] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, cnt = 0;
int vis[kN];

int main() {
	int T; Read(T);
	while(T--) {
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		int n; Read(n);
		for(int i = 1; i <= n; ++i) Read(a[i]);
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= 11; ++j)
				if(a[i] % pr[j] == 0) { a[i] = j; break; }
		}
		for(int i = 1; i <= n; ++i) {
			if(vis[a[i]]) col[i] = vis[a[i]];
			else col[i] = vis[a[i]] = ++cnt;
		}
		printf("%d\n", cnt);
		for(int i = 1; i <= n; ++i) printf("%d ", col[i]);
		printf("\n");
	}
	return 0;
}