#include <bits/stdc++.h>
using namespace std;
const int N = 10005, M = N * 3;
int t, n, a[N], b[M], c[M], d[M];
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum % n) {
      puts("-1");
      continue;
    } 
    int st = sum / n;
    int m = 0;
    auto work = [&](int x, int y, int z) {
      b[++m] = x;
      c[m] = y;
      d[m] = z;
      a[x] -= x * z;
      a[y] += x * z;
    };
    for (int i = 2; i <= n; ++i) {
      if (a[i] % i) work(1, i, i - a[i] % i);
      work(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; ++i) {
      work(1, i, st);
    }
    printf("%d\n", m);
    for (int i = 1; i <= m; ++i) {
      printf("%d %d %d\n", b[i], c[i], d[i]);
    }
  }
  return 0;
}