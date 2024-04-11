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
const int kN = 1e6 + 5, kInf = 0x3f3f3f3f;
const ll kMod = 1e9 + 7, kInfLL = 0x3f3f3f3f3f3f3f3fLL;

int tr[kN][26], fch[kN][26], fail[kN], slink[kN], d[kN], s[kN], len[kN],
	s_len, cur, node_cnt, f[kN], g[kN][2];
void Init() { node_cnt = 1; len[0] = -1; s[0] = -1; }
void Insert(int c) {
	int p = s[s_len - len[cur]] == c ? cur : fch[cur][c];
	s[++s_len] = c;
	if(tr[p][c]) cur = tr[p][c];
	else {
		cur = tr[p][c] = ++node_cnt;
		int fu = fail[cur] = p ? tr[fch[p][c]][c] : 1;
		len[cur] = len[p] + 2; d[cur] = len[cur] - len[fu];
		slink[cur] = d[fu] == d[cur] ? slink[fu] : fu;
		for(int i = 0; i < 26; ++i)
			fch[cur][i] = s[s_len - len[fu]] == i ? fu : fch[fu][i];
	}
}

int n; char str[kN], t[kN];
int main() { 
#ifndef ONLINE_JUDGE
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
#endif
	int T = 1; //rd(T);
	while(T--) {
		scanf("%s", str + 1); n = strlen(str + 1);
		std::reverse(str + n / 2 + 1, str + n + 1);
		for(int i = 1; i <= n; ++i)
			t[i] = str[(1 - i % 2) * (n / 2) + (i + 1) / 2];
		Init(); f[0] = 1;
		for(int i = 1; i <= n; ++i) {
			Insert(t[i] - 'a');
			for(int j = cur; j > 1; j = slink[j]) {
				int dlt = len[slink[j]] + d[j];
				g[j][0] = g[j][1] = 0;
				g[j][dlt & 1] = f[i - dlt];
				if(fail[j] != slink[j]) {
					for(int k = 0; k < 2; ++k)
						g[j][k] = (g[j][k] + g[fail[j]][k ^ (d[j] & 1)]) % kMod;
				}
				f[i] = (f[i] + g[j][0]) % kMod;
			}
		}
		printf("%d\n", f[n]);
	} return 0;
}