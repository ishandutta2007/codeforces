#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 10;
typedef long long LL;

int a[MAXN], b[MAXN];
int mark[MAXN];
int n, m;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++ i) scanf("%d", a + i);
  LL ret(0);
  for (int g = 1; g < n; ++ g) if (n % g == 0) {
    memset(mark, 0, sizeof(mark[0]) * n);
    for (int s = 0; s < g; ++ s) {
      int mx(0);
      for (int i = s; i < n; i += g) mx = max(mx, a[i]);
      for (int i = s; i < n; i += g) {
        if (a[i] == mx) mark[i] = 1;
      }
    }
    for (int i = 0, j; i < n; ++ i) {
      if (mark[i]) {
        int len(0);
        for (int j = 0; j < n; ++ j) {
          if (mark[(j + i) % n]) ++ len, mark[(j + i) % n] = 0;
          else break;
        }
        for (int j = 1; j < n; ++ j) {
          if (mark[(n - j + i) % n]) ++ len, mark[(n - j + i) % n] = 0;
          else break;
        }
        for (int k = g; k <= len; k += g) {
          if (__gcd(k, n) == g) {
            if (len == n) ret += n;
            else ret += len - k + 1;
          }
        }
      }
    }
    m ++;
  }
  cout << ret << endl;
  return 0;
}