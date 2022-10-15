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

const int kN = 2e5 + 5;

char str[kN];
int app[30];

int main() {
	int T; Read(T);
	while(T--) {
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", str + 1);
		int ans = 0;
		for(int i = 1; i <= k / 2; ++i) {
			memset(app, 0, sizeof(app));
			for(int j = 0; j < n; j += k)
				++app[str[j + i] - 'a' + 1], ++app[str[j + k - i + 1] - 'a' + 1];
			int cur_min = 0;
			for(int j = 1; j <= 26; ++j)
				cur_min = std::max(cur_min, app[j]);
			ans += cur_min;
		}
		if(k % 2 != 0) {
			memset(app, 0, sizeof(app));
			for(int j = k / 2 + 1; j <= n; j += k) {
				++app[str[j] - 'a' + 1];
			}
			int cur_min = 0;
			for(int j = 1; j <= 26; ++j)
				cur_min = std::max(cur_min, app[j]);
			ans += cur_min;
		}
		printf("%d\n", n - ans);
	}
	return 0;
}