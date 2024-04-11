#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1 << 20;

int mult(int a, int b) { return (1LL * a * b) % mod; }

int pw(int a, int b) {
  if (b == 0)
    return 1;
  if (b & 1)
    return mult(a, pw(a, b - 1));
  int res = pw(a, b / 2);
  return mult(res, res);
}
int inv(int x) { return pw(x, mod - 2); }

int sub(int a, int b) {
  int s = a - b;
  if (s < 0)
    s += mod;
  return s;
}

int sum(int a, int b) {
  int s = a + b;
  if (s >= mod)
    s -= mod;
  return s;
}

void fft(vector<int> &a, bool invert) {
  int n = (int)a.size();

  for (int i = 1, j = 0; i < n; ++i) {
    int bit = n >> 1;
    for (; j >= bit; bit >>= 1)
      j -= bit;
    j += bit;
    if (i < j)
      swap(a[i], a[j]);
  }

  for (int len = 2; len <= n; len <<= 1) {
    int wlen = invert ? root_1 : root;
    for (int i = len; i < root_pw; i <<= 1)
      wlen = int(wlen * 1ll * wlen % mod);
    for (int i = 0; i < n; i += len) {
      int w = 1;
      for (int j = 0; j < len / 2; ++j) {
        int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
        a[i + j] = u + v < mod ? u + v : u + v - mod;
        a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
        w = int(w * 1ll * wlen % mod);
      }
    }
  }
  if (invert) {
    int nrev = pw(n, mod - 2);
    for (int i = 0; i < n; ++i)
      a[i] = int(a[i] * 1ll * nrev % mod);
  }
}

void poly_mult(vector<int> &a, vector<int> b) {
  int s = a.size() + b.size();
  int r = 1;
  while (r < s)
    r *= 2;
  a.resize(r);
  b.resize(r);
  fft(a, false);
  fft(b, false);
  for (int j = 0; j < r; j++) {
    a[j] = mult(a[j], b[j]);
  }
  fft(a, true);
  while (a.size() >= s)
    a.pop_back();
}
void poly_square(vector<int> &a) {
  int s = a.size() + a.size();
  int r = 1;
  while (r < s)
    r *= 2;
  a.resize(r);
  fft(a, false);
  for (int j = 0; j < r; j++) {
    a[j] = mult(a[j], a[j]);
  }
  fft(a, true);
  while (a.size() >= s)
    a.pop_back();
}

int n;
char s[N];
int bal, a, b, c, x, y;

int A[N], B[N];

int fact[N], inv_fact[N];

int C(int k, int n) {
  if (k < 0 || k > n)
    return 0;
  return mult(fact[n], mult(inv_fact[k], inv_fact[n - k]));
}
void solve() {
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i < N; i++)
    fact[i] = mult(i, fact[i - 1]), inv_fact[i] = inv(fact[i]);

  scanf("%d", &n);

  bool flag = 0;

  for (int i = 0; i < n; i++) {
    scanf("%s", s);

    if (!strcmp(s, "WW")) {
      flag = 1;
      bal++;
    }
    if (!strcmp(s, "BB")) {
      flag = 1;
      bal--;
    }

    if (!strcmp(s, "W?") || !strcmp(s, "?W")) {
      a++;
    }
    if (!strcmp(s, "B?") || !strcmp(s, "?B")) {
      b++;
    }
    if (!strcmp(s, "W?") || !strcmp(s, "?B") || !strcmp(s, "WB")) {
      x++;
    }
    if (!strcmp(s, "B?") || !strcmp(s, "?W") || !strcmp(s, "BW")) {
      y++;
    }

    if (!strcmp(s, "??")) {
      c++;
    }
  }

  // cerr << a << " " << b << " " << c << endl;
  {
    vector<int> va(n + 1), vb(n + 1);

    for (int i = 0; i <= n; i++)
      va[i] = C(i, a), vb[i] = C(i, b);
    // for (int i = 0; i < n; i++)
    //   cerr << va[i] << " ";
    // cerr << endl;
    // for (int i = 0; i < n; i++)
    //   cerr << vb[i] << " ";
    // cerr << endl;

    reverse(vb.begin(), vb.end());
    poly_mult(va, vb);
    for (int i = 0; i <= n + n; i++)
      A[i] = va[i];
    // for (int i = 0; i <= n + n; i++)
    //   cerr << i - n << " " << A[i] << endl;
  }
  {
    vector<int> va(1), vb(3);
    va[0] = 1;
    vb[0] = 1, vb[1] = 2, vb[2] = 1;
    // auto vc = vb;
    // for(auto x : vb)
    //   cerr << x << " ";
    // cerr << endl;
    // poly_mult(vb, vc);
    // for(auto x : vc)
    //   cerr << x << " ";
    // cerr << endl;
    // for(auto x : vb)
    //   cerr << x << " ";
    // cerr << endl;

    int p = c;
    while (p) {
      if (p & 1)
        poly_mult(va, vb);
      p >>= 1;
      poly_square(vb);
      // cerr << va.size() << "-" << vb.size() << endl;
      // for(auto x : va)
      //   cerr << x << " ";
      // cerr << endl;
      // for(auto x : vb)
      //   cerr << x << " ";
      // cerr << endl;
    }
    for (int i = -c; i <= c; i++)
      B[i + n] = va[va.size() / 2 + i];

    // for (int i = 0; i <= n + n; i++)
    //   cerr << i - n << " " << B[i] << endl;
  }
  int ans = 0;
  for (int i = -b; i <= a; i++) {
    int j = -i - bal;
    // cerr << i << " " << j << " " << bal << " " << A[i + n] << " " << B[j + n]
    // << endl;
    ans = sum(ans, mult(A[i + n], B[j + n]));
  }
  // cerr << ans << endl;
  if (!flag) {
    ans = sub(ans, pw(2, c));
    if (x == 0)
      ans = sum(ans, 1);
    if (y == 0)
      ans = sum(ans, 1);
  }

  printf("%d\n", ans);
}
int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--)
    solve();
}