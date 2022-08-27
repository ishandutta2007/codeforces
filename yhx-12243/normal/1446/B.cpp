#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 5054;

int S, T;
char s[N], t[N];
int f[N][N];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline int max(const int x, const int y) {return x < y ? y : x;}

int main() {
	int i, j, ans = 0;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> S >> T >> s + 1 >> t + 1;
	memset(f, 192, sizeof f);
	f[0][0] = 0;
	for (i = 1; i <= S; ++i)
		for (j = 1; j <= T; ++j) {
			if (s[i] == t[j])
				f[i][j] = max(f[i - 1][j - 1], 0) + 2;
			else
				f[i][j] = max(max(f[i - 1][j], f[i][j - 1]), 0) - 1;
			up(ans, f[i][j]);
		}
	cout << ans << '\n';
	return 0;
}