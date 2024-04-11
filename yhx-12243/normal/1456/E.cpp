#include <bits/stdc++.h>
#define lg2 std::__lg
using std::cin;
using std::cout;

const int N = 54;
typedef long long ll, (*pDP)[N][4][4];

int n, B;
int sig[N];
ll c[N], L[N], R[N], G[N][2];
ll dp[2][N][N][4][4];
pDP cur = *dp, nxt = dp[1];

inline void down(int &x, const int y) {x > y ? x = y : 0;}
inline void down(ll &x, const ll y) {x > y ? x = y : 0;}

int main() {
	int i, j, l, r, bl, br, b, dl, dr, d; ll u, v, mask;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> B;
	for (i = 1; i <= n; ++i)
		cin >> u >> v, L[i] = u + (1ll << B) - 1, R[i] = v + (1ll << B) + 1, sig[i] = lg2(L[i] ^ R[i]),
		mask = ~(-1ll << sig[i]), G[i][0] = ~L[i] & mask, G[i][1] = R[i] & mask; 
	for (i = 0; i < B; ++i) cin >> c[i];
	for (i = 1; i < n; ++i) for (bl = 0; bl < 2; ++bl) for (br = 0; br < 2; ++br) nxt[i - 1][i][bl][br] = 0;
	nxt[0][1][0][0] = nxt[0][1][0][1] = nxt[n][n + 1][0][0] = nxt[n][n + 1][1][0] = 0;
	for (i = B; i >= 0; --i) {
		std::swap(cur, nxt), memset(nxt, 63, sizeof *dp);
		for (d = 1; d <= n + 1; ++d)
			for (l = 0, r = d; r <= n + 1; ++l, ++r)
				for (bl = 0; bl < 4; ++bl) if (l ? ~bl & 2 || G[l][bl & 1] >> i & 1 : !bl)
					for (br = 0; br < 4; ++br) if (r == n + 1 ? !br : ~br & 2 || G[r][br & 1] >> i & 1) {
						ll &ret = nxt[l][r][bl][br]; b = 64;
						for (j = l + 1; j < r; ++j)
							down(ret, nxt[l][j][bl][2] + nxt[j][r][2][br]),
							down(ret, nxt[l][j][bl][3] + nxt[j][r][3][br]), down(b, sig[j]);
						if (i + 1 < b) {
							if (!l || r == n + 1) dl = dr = 0;
							else
								dl = ((bl & 1 ? R[l] : L[l]) >> i & 1) ^ (bl >> 1),
								dr = ((br & 1 ? R[r] : L[r]) >> i & 1) ^ (br >> 1);
							down(ret, cur[l][r][bl & 1][br & 1] + (dl ^ dr) * c[i]);
						}
					}
	}
	cout << nxt[0][n + 1][0][0] << '\n';
	return 0;
}