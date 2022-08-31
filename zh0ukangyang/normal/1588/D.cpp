#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 12, M = 1007;
int n, len[N], id[M];
int dp[52][1 << N];
int lst1[52][1 << N];
int lst2[52][1 << N];

int f[N][M], fp[N][52][M], nt[52];
int nx[N][M][52];
char s[N][M];
bool can[52];
int getc (char c) {
	if('a' <= c && c <= 'z') return c - 'a';
	else return c - 'A' + 26;
}
int ro[N], tp;
void Draw (int x, int y) {
	if(x < 0) return ;
	Draw (lst1[x][y], lst2[x][y]);
	ro[++tp] = x;
}
void Main () {
	memset(nx, -1, sizeof(nx));
	memset(dp, -0x3f, sizeof(dp));
	memset(lst1, -1, sizeof(lst1));
	L(i, 0, 51) can[i] = true;
	cin >> n;
	L(i, 1, n) {
		cin >> (s[i] + 1);
		memset(nt, 0, sizeof(nt));
		len[i] = strlen(s[i] + 1);
		L(j, 1, len[i]) {
			f[i][j] = getc(s[i][j]);
			nt[f[i][j]] += 1;
			id[j] = nt[f[i][j]];
			fp[i][f[i][j]][id[j] - 1] = j;
		}
		L(j, 0, 51) if(!nt[j]) can[j] = false;
		R(j, len[i], 1) {
			if (j > 1) {
				L(k, 0, 51) nx[i][j - 1][k] = nx[i][j][k];
				nx[i][j - 1][f[i][j]] = id[j];
			}
		}
	}
	int ns = 0, nsl = -1, nsr = 0;
	queue < int > q;
	L(i, 0, 51) if(can[i]) dp[i][0] = 1;
	L(p, 1, len[1]) {
		int c = f[1][p];
		R(i, (1 << n) - 1, 0) if(dp[c][i] > 0) {
			if(dp[c][i] > ns) 
				ns = dp[c][i], nsl = c, nsr = i;
			L(j, 0, 51) {
				bool ok = true;
				int ret = 0;
				L(k, 1, n) {
					int P = fp[k][c][i >> (k - 1) & 1];
					if(nx[k][P][j] == -1) {
						ok = false;
						break;
					}
					ret |= (nx[k][P][j] - 1) << (k - 1); 
				}
				if(ok && dp[c][i] + 1 > dp[j][ret]) {
					dp[j][ret] = dp[c][i] + 1;
					lst1[j][ret] = c;
					lst2[j][ret] = i;
				}
			}
		}
	}
	tp = 0;
	Draw(nsl, nsr);
	cout << ns << '\n';
	L(i, 1, tp) cout << ((char)(ro[i] < 26 ? ro[i] + 'a' : ro[i] - 26 + 'A'));
	cout << '\n';
} 
int main () {
	ios :: sync_with_stdio(false);
	cin.tie (0); cout.tie (0);
	int T;
	cin >> T;
	while (T--) Main ();
	return 0;
}