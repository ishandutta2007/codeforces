#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int> 
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 2007, inf = 1e9, mod = 1e9 + 7;
char s[N], t[N];
int n, a[N], b[N], cur[N], o[N]; 
int f[N][N * 2][2];
int g[N][N * 2][2];
void Main () {
	cin >> n;
	cin >> (s + 1);
	cin >> (t + 1);
	L(i, 0, n + 1) memset(f[i], 0, sizeof(f[i])), memset(g[i], 0, sizeof(g[i]));
	f[0][N][0] = 1;
	L(i, 1, n) {
		L(j, 2, N * 2 - 3) L(o, 0, 1) if(f[i - 1][j][o] || g[i - 1][j][o]) {
//			cout << "qwq\n";
			L(x, 0, 1) if(s[i] == '?' || s[i] - '0' == x)  L(y, 0, 1) if(t[i] == '?' || t[i] - '0' == y) {
				int ho = x ^ y ^ o, w = j, Z = 0;
				if(i & 1) {
					if(x) w += 1;
					if(y) w -= 1; 
				}
				else {
					if(x) w -= 1;
					if(y) w += 1;
				}
				Z = abs(j - N);
				(f[i][w][ho] += f[i - 1][j][o]) %= mod;
				(g[i][w][ho] += (ll) f[i - 1][j][o] * Z % mod) %= mod;
				(g[i][w][ho] += g[i - 1][j][o]) %= mod;
			}
		}
	}
	cout << (g[n][N][0] + g[n][N][1]) % mod << '\n';
//	int ret = 0;
//	L(u, 0, (1 << n) - 1) {
//		L(v, 0, (1 << n) - 1) {
//			L(i, 1, n) a[i] = u >> (i - 1) & 1;
//			L(i, 1, n) b[i] = v >> (i - 1) & 1;	
//			bool ok = true;
//			L(i, 1, n) if(s[i] != '?' && s[i] - '0' != a[i]) ok = false;
//			L(i, 1, n) if(t[i] != '?' && t[i] - '0' != b[i]) ok = false;
//			if(!ok) continue;
//			L(i, 1, n) o[i] = a[i] ^ b[i];
//			int cnt = 0, r = 0, ns = 0;
//			L(i, 1, n) {
//				r ^= o[i];
//				if(i & 1) {
//					if(a[i]) 
//						cnt += 1;
//					if(b[i]) 
//						cnt -= 1;
//				} 
//				else {
//					if(a[i]) 
//						cnt -= 1;
//					if(b[i]) 
//						cnt += 1;
//				}
//				if(r) ns += 1;
//				else if(cnt) ns += 2;
//			}
//			if(cnt == 0) 
//				ret += ns;
//		}
//	}
//	cout << ret << '\n';
}
int main () {
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main () ;
	return 0;
}