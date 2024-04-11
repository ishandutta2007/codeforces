#include <bits/stdc++.h>

#define gc() getchar()
template <typename T> inline void rd(T& x) {
	int si = 1; char c = gc(); x = 0;
	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
	x *= si;
}
template <typename T, typename... Args>
inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
#define fi first
#define se second
#define mkp std::make_pair
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef double ff;
typedef std::pair <int, int> pii;
const int N = 1.2e3 + 5, M = 200 + 5;

int GetInt(char c) {
	if(c >= 'A' && c <= 'Z') return c - 'A';
	else return c - 'a' + 26;
}
char GetChar(int idx) {
	if(idx < 26) return idx + 'A';
	else return idx - 26 + 'a';
}

int n, len[N], f[M][N][52], pos[N][52][2], n_S[N][52][52];
pii lst[M][N][52];
char t[N][M];

void Update(int &x, int y) { x = std::max(x, y); }

int main() {
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int test_case_cnt = 1; rd(test_case_cnt);
	while(test_case_cnt--) {
		memset(f, ~0x3f, sizeof(f));
		memset(pos, 0, sizeof(pos));
		memset(lst, 0, sizeof(lst));
		memset(n_S, 0, sizeof(n_S));
		rd(n);
		int len_mn = 200;
		for(int i = 1; i <= n; ++i) {
			scanf("%s", t[i] + 1);
			len[i] = strlen(t[i] + 1);
			len_mn = std::min(len_mn, len[i]);
			for(int j = 1; j <= len[i]; ++j) {
				int c = GetInt(t[i][j]);
				if(pos[i][c][0]) pos[i][c][1] = j;
				else pos[i][c][0] = j;
			}
		}
		for(int S = 0; S < 1 << n; ++S)
			for(int o_c = 0; o_c < 52; ++o_c)
				for(int c = 0; c < 52; ++c) {
					for(int i = 1; i <= n; ++i) {
						int cur_pos = pos[i][o_c][(S >> (i - 1)) & 1];
						if(pos[i][c][0] <= cur_pos &&
							pos[i][c][1] > cur_pos)
							n_S[S][o_c][c] |= 1 << (i - 1);
						else if(pos[i][c][0] <= cur_pos && pos[i][c][1] <= cur_pos) {
							n_S[S][o_c][c] = -1;
							break;
						}
					}
				}
		for(int c = 0; c < 52; ++c) {
			bool flag = true;
			for(int i = 1; i <= n; ++i)
				if(!pos[i][c][0]) { flag = false; break; }
			if(flag) f[1][0][c] = 1;
		}
		for(int i = 1; i <= len_mn; ++i)
			for(int S = 0; S < 1 << n; ++S)
				for(int o_c = 0; o_c < 52; ++o_c) if(f[i][S][o_c] > 0)
					for(int c = 0; c < 52; ++c) {
						int cur_n_S = n_S[S][o_c][c];
						if(cur_n_S == -1) continue;
						Update(f[i + 1][cur_n_S][c], f[i][S][o_c] + 1);
						if(f[i][S][o_c] + 1 == f[i + 1][cur_n_S][c])
							lst[i + 1][cur_n_S][c] = mkp(S, o_c);
					}
		std::string str;
		pii ep;
		int ans = 0;
		for(int i = 1; i <= len_mn; ++i)
			for(int S = 0; S < 1 << n; ++S)
				for(int c = 0; c < 52; ++c) {
					ans = std::max(ans, f[i][S][c]);
					if(f[i][S][c] == ans)
						ep = mkp(S, c);
				}
		printf("%d\n", ans);
		for(int u = ans, S = ep.fi, c = ep.se; u > 0; --u) {
			str.push_back(GetChar(c));
			pii tmp = lst[u][S][c];
			S = tmp.fi; c = tmp.se;
		}
		std::reverse(str.begin(), str.end());
		std::cout << str << std::endl;
	} return 0;
}