#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void add(int &x, const int y) {(x += y) >= mod && (x -= mod);}
inline int Add(int x, const int y) {return add(x, y), x;}
inline void sub(int &x, const int y) {(x -= y) < 0 && (x += mod);}
inline int Sub(int x, const int y) {return sub(x, y), x;}
inline void mul(int &x, const int y) {x = 1ll * x * y % mod;}
inline int Mul(const int x, const int y) {return 1ll * x * y % mod;}
inline int power(int a, int b, int c = 1) {
  for (; b; b >>= 1, mul(a, a))
    if (b & 1) mul(c, a);
  return c;
}
const int _N = (1 << 20) + 5;
int w[23];
using poly = vector<int>;
void print(const poly &f) {for (int i = 0; i < f.size(); ++i) printf("%d%c", f[i], " \n"[i == f.size() - 1]);} 
void dft(int *a, int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i < j) swap(a[i], a[j]);
    for (int k = n >> 1; (j ^= k) < k; k >>= 1);
  }
  for (int k = 1, qaq = 0; k < n; k <<= 1, ++qaq) {
    int wn = ::w[qaq];
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0, w = 1; j < k; ++j) {
        int x  = Mul(w, a[i + j + k]);
        a[i + j + k] = Sub(a[i + j], x);
        add(a[i + j], x);
        mul(w, wn);
      }
    }
  }
}
void idft(int *a, int n) {
  reverse(a + 1, a + n);
  dft(a, n); int coef = power(n, mod - 2);
  for (int i = 0; i < n; ++i) mul(a[i], coef);
}
int extend(int n) {int x = 1; while (x < n) x <<= 1; return x;}
poly operator + (poly a, const poly &b) {
  if (a.size() < b.size()) a.resize(b.size());
  for (int i = 0; i < a.size(); ++i) add(a[i], b[i]);
  return a;
} 
poly operator * (const poly &a, const poly &b) {
  int len = a.size() + b.size() - 1;
  int n = extend(len);
  static int f[_N], g[_N];
  for (int i = 0; i < n; ++i)
    f[i] = i < a.size() ? a[i] : 0, 
    g[i] = i < b.size() ? b[i] : 0;
  dft(f, n), dft(g, n);
  for (int i = 0; i < n; ++i) mul(f[i], g[i]);
  idft(f, n); poly c(len);
  for (int i = 0; i < len; ++i) c[i] = f[i];
  return c;
}
poly rev(poly a) {return reverse(a.begin(), a.end()), a;} 
const int N = 5e5 + 5;
int t, n;
char s[N];
poly v, k, res;
int main(){
  scanf("%d", &t);
  for (int i = 1, j = 0; j < 21; i <<= 1, ++j) 
    w[j] = power(3, (mod - 1) / (2 * i)); 
  while (t--) {
    scanf("%d%s", &n, s + 1);
    v.assign(n + 1, 0), k.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      if (s[i] == 'V') v[i] = 1;
      else if (s[i] == 'K') k[i] = 1;
    }
    res = v * rev(k);
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      bool flag = 1;
      for (int j = n % i; j < res.size(); j += i) 
        if (res[j]) flag = 0;
      if (flag) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) 
      printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
  }
  return 0;
}