#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void add(int &a, int b) { (a += b) >= mod && (a -= mod); }
int Add(int a, int b) { return add(a, b), a; }
void sub(int &a, int b) { (a -= b) < 0 && (a += mod); }
int Sub(int a, int b) { return sub(a, b), a; }
void mul(int &a, int b) { a = 1ll * a * b % mod; }
int Mul(int a, int b) { return 1ll * a * b % mod; }
int qpow(int a, int b) {
    int res = 1; 
    for (; b; b >>= 1, mul(a, a)) 
      if (b & 1) mul(res, a); 
    return res;
}

const int N = 2005;
int n, ans, a[N][N], f[N][N];
bool vis[2][N];
struct Fenwick {
  int s[N];
  void init() {memset(s, 0, sizeof(s));}
  void add(int p, int x) {
    for (; p <= n; p += p & -p) 
      s[p] += x;
  }
  int query(int p) {
    int res = 0;
    for (; p; p -= p & -p)
      res += s[p];
    return res;
  }
} bit1, bit2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  f[0][0] = f[2][0] = 1;
  for (int i = 1; i <= n; ++i)
    f[0][i] = Mul(i, f[0][i - 1]);
  for (int i = 3; i <= n; ++i) 
    f[i][0] = Mul(i - 1, Add(f[i - 1][0], f[i - 2][0]));
  for (int i = 1; i <= n; ++i) 
    for (int j = 1; j <= n; ++j) {
      f[i][j] = Add(Mul(i - 1, f[i - 1][j]), Mul(j, Add(f[i - 1][j - 1], f[i][j - 1])));
      if (i > 1) add(f[i][j], Mul(i - 1, f[i - 2][j]));
    }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      cin >> a[i][j];
  for (int j = 1; j <= n; ++j) {
    int k = a[1][j] - bit1.query(a[1][j]) - 1;
    add(ans, Mul(k, f[0][n - j]));
    bit1.add(a[1][j] + 1, 1);
  } 
  mul(ans, qpow(f[n][0], n - 1));
  for (int i = 2; i <= n; ++i) {
    bit1.init(), bit2.init();
    for (int j = 1; j <= n; ++j) 
      vis[0][j] = vis[1][j] = 0;
    int x = n, y = 0, res = 0;
    for (int j = 1; j <= n; ++j) {
      int k1 = a[i][j] - bit1.query(a[i][j]) - 1;
      if (a[i - 1][j] < a[i][j] && !vis[1][a[i - 1][j]]) --k1;
      int k2 = bit2.query(a[i][j] - 1); k1 -= k2; 
      bit1.add(a[i][j] + 1, 1);
      if (!vis[1][a[i - 1][j]]) bit2.add(a[i - 1][j], 1);
      if (vis[0][a[i][j]]) bit2.add(a[i][j], -1);
      vis[0][a[i - 1][j]] = vis[1][a[i][j]] = 1;
      auto upd = [&](bool tp, int a) {
        if (vis[tp ^ 1][a]) --y;
        else --x, ++y;
      }; upd(0, a[i - 1][j]);
      if (x) add(res, Mul(k1, f[x - 1][(y + 1) / 2]));
      add(res, Mul(k2, f[x][(y - 1) / 2]));
      upd(1, a[i][j]);
    }
    add(ans, Mul(res, qpow(f[n][0], n - i)));
  }
  cout << ans << "\n";
  return 0;
}