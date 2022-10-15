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
#define mkp std::make_pair
typedef long long ll;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 2e2 + 5, M = 3e2 + 5, Mod = 1e4 + 7;

char s[N];
int n, m, f[N][N][N], mat[M][M], m_siz, S, T;

void Update(int &x, int y) { x = (x + y) % Mod; }
void Build() {
	f[0][n + 1][0] = 1;
	for(int k = 0; k <= n; ++k)
		for(int len = n + 1; len > 1; --len)
			for(int i = 0; i + len <= n + 1; ++i) {
				int j = i + len;
				if(s[i + 1] == s[j - 1])
					Update(f[i + 1][j - 1][k], f[i][j][k]);
				else {
					Update(f[i + 1][j][k + 1], f[i][j][k]);
					Update(f[i][j - 1][k + 1], f[i][j][k]);
				}
			}
	m_siz = n + (n + 1) / 2 + 2;
	S = 1; T = m_siz;
	for(int i = 1; i <= (n + 1) / 2; ++i) {
		mat[n + i + 1][n + i + 2] = 1;
		mat[n + i + 1][n + i + 1] = 25;
	}
	for(int i = 1; i <= n + 1; ++i) {
		if(i > 1) mat[i][i] = 24;
		if(i <= n) mat[i][i + 1] = 1;
	}
	for(int i = 0; i <= n; ++i) {
		int c = 0;
		for(int j = 0; j <= n; ++j) {
			Update(c, f[j][j + 1][i]);
			if(j) Update(c, f[j][j][i]);
		}
		mat[i + 1][T - (n - i + 1) / 2] = c;
	}
	mat[T][T] = 26;
}

void ReBuild() {
	m_siz = n + (n + 1) / 2 + 1;
	S = 1; T = m_siz;
	for(int i = 1; i <= (n + 1) / 2; ++i) {
		mat[n + i + 1][n + i + 2] = 1;
		mat[n + i + 1][n + i + 1] = 25;
	}
	for(int i = 1; i <= n + 1; ++i) {
		if(i > 1) mat[i][i] = 24;
		if(i <= n) mat[i][i + 1] = 1;
	}
	for(int i = 0; i <= n; ++i) {
		int c = 0;
		for(int j = 0; j <= n; ++j)
			Update(c, f[j][j + 1][i]);
		mat[i + 1][T - (n - i + 1) / 2 + 1] = c;
	}
}

int ret[M][M], bas[M][M], tmp[M][M];
void QPow(int b) {
	memset(ret, 0, sizeof(ret));
	for(int i = 1; i <= m_siz; ++i)
		ret[i][i] = 1;
	memcpy(bas, mat, sizeof(bas));
	for(; b; b >>= 1) {
		if(b & 1) {
			memset(tmp, 0, sizeof(tmp));
			for(int k = 1; k <= m_siz; ++k)
				for(int i = 1; i <= m_siz; ++i) if(ret[i][k])
					for(int j = 1; j <= m_siz; ++j)
						Update(tmp[i][j], ret[i][k] * bas[k][j]);
			memcpy(ret, tmp, sizeof(ret));
		}
		memset(tmp, 0, sizeof(tmp));
		for(int k = 1; k <= m_siz; ++k)
			for(int i = 1; i <= m_siz; ++i) if(bas[i][k])
				for(int j = 1; j <= m_siz; ++j)
					Update(tmp[i][j], bas[i][k] * bas[k][j]);
		memcpy(bas, tmp, sizeof(bas));
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; //rd(test_case_cnt);
	while(test_case_cnt--) {
		scanf("%s", s + 1);
		rd(m); n = strlen(s + 1);
		m += n;
		Build();
		QPow((m + 1) / 2 + 1);
		int ans_1 = ret[S][T];
		if(m % 2 == 0) printf("%d\n", ans_1);
		else {
			ReBuild();
			QPow((m + 1) / 2);
			int ans_2 = ret[S][T];
			printf("%d\n", (ans_1 - ans_2 + Mod) % Mod);
		}
	} return 0;
}