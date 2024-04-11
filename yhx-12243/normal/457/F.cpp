#include <bits/stdc++.h>
using std::cin;
using std::cout;

const int N = 254;

int n;
int p[N], lc[N], rc[N];
int cnt, o[N], id[N], size[N], w[N];
bool f[N][2][3];

inline void up(int &x, const int y) {x < y ? x = y : 0;}
inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline int min(const int x, const int y) {return x < y ? x : y;}
inline int max(const int x, const int y) {return x < y ? y : x;}

int dfs(int x) {
	o[cnt] = x, id[x] = cnt++;
	if (~w[x]) return size[x] = 0;
	size[x] = 1 + dfs(lc[x]);
	return size[x] += dfs(rc[x]);
}

bool check(int th) {
	int i, x, l, r;
	for (i = n - 1; i >= 0; --i) {
		x = o[i];
		if (~w[x]) {memset(f[x], w[x] >= th, 6); continue;}
		l = lc[x], r = rc[x];
		if (~w[l] && ~w[r]) {
			f[x][0][0] = f[x][0][1] = f[x][1][2] = min(w[l], w[r]) >= th,
			f[x][1][0] = f[x][1][1] = f[x][0][2] = max(w[l], w[r]) >= th;
			continue;
		}
		switch ((size[l] & 1) | (size[r] & 1) << 1) {
			case 0:
				f[x][0][0] = f[l][0][0] && f[r][0][0],
				f[x][1][0] = f[l][1][0] || f[r][1][0],
				f[x][0][1] = f[x][1][0] && (!size[l] || f[l][0][1 + !size[r]] || f[r][1][0]) && (!size[r] || f[l][1][0] || f[r][0][1 + !size[l]]),
				f[x][1][1] = f[x][0][0] || (size[l] && f[l][1][1 + !size[r]] && f[r][0][0]) || (size[r] && f[l][0][0] && f[r][1][1 + !size[l]]),
				f[x][0][2] = f[x][1][0] && (!size[l] || f[l][0][1] || f[r][1][0]) && (!size[r] || f[l][1][0] || f[r][0][1]),
				f[x][1][2] = f[x][0][0] || (size[l] && f[l][1][1] && f[r][0][0]) || (size[r] && f[l][0][0] && f[r][1][1]);
				break;
			case 1:
				f[x][0][0] = (f[l][0][0] || f[r][1][0]) && (f[l][1][1] || f[r][0][1]),
				f[x][1][0] = (f[l][1][0] && f[r][0][0]) || (f[l][0][1] && f[r][1][1]),
				f[x][0][1] = f[x][1][0] && f[l][0][1 + !size[r]] && f[r][0][0],
				f[x][1][1] = f[x][0][0] || f[l][1][1 + !size[r]] || f[r][1][0],
				f[x][0][2] = f[x][1][0] && f[l][0][1] && f[r][0][0],
				f[x][1][2] = f[x][0][0] || f[l][1][1] || f[r][1][0];
				break;
			case 2:
				f[x][0][0] = (f[l][1][0] || f[r][0][0]) && (f[l][0][1] || f[r][1][1]),
				f[x][1][0] = (f[l][0][0] && f[r][1][0]) || (f[l][1][1] && f[r][0][1]),
				f[x][0][1] = f[x][1][0] && f[l][0][0] && f[r][0][1 + !size[l]],
				f[x][1][1] = f[x][0][0] || f[l][1][0] || f[r][1][1 + !size[l]],
				f[x][0][2] = f[x][1][0] && f[l][0][0] && f[r][0][1],
				f[x][1][2] = f[x][0][0] || f[l][1][0] || f[r][1][1];
				break;
			case 3:
				f[x][0][0] = f[l][0][1] && f[r][0][1],
				f[x][1][0] = f[l][1][1] || f[r][1][1],
				f[x][0][1] = f[x][1][0] && (f[l][1][1 + (size[r] == 1)] || f[r][0][0]) && (f[l][0][0] || f[r][1][1 + (size[l] == 1)]);
				f[x][1][1] = f[x][0][0] || (f[l][0][1 + (size[r] == 1)] && f[r][1][0]) || (f[l][1][0] && f[r][0][1 + (size[l] == 1)]);
				f[x][0][2] = f[x][1][0] && (f[l][1][1] || f[r][0][0]) && (f[l][0][0] || f[r][1][1]);
				f[x][1][2] = f[x][0][0] || (f[l][0][1] && f[r][1][0]) || (f[l][1][0] && f[r][0][1]);
				break;
		}
	}
	return f[0][1][0];
}

void work() {
	int i, L = INT_MAX, R = INT_MIN, M;
	cin >> n, cnt = 0;
	for (i = 0; i < n; ++i)
		if (cin >> w[i], !~w[i]) cin >> lc[i] >> rc[i];
		else lc[i] = rc[i] = -1, down(L, w[i]), up(R, w[i]);
	dfs(0);
	for (; L < R; check(M) ? L = M : R = M - 1) M = (L + R + 1) / 2;
	cout << L << '\n';
}

int main() {
	int T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	for (cin >> T; T; --T) work();
	return 0;
}