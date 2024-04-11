#include <bits/stdc++.h>
using namespace std;
int T, l, r;
long long m;
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%d%lld", &l, &r, &m);
    long long lb = m - (r - l), rb = m + (r - l);
    for (int a = l; a <= r; ++a) {
      long long lp = (lb - 1) / a, rp = rb / a;
      if (lp != rp) {
        long long n = a * (lp + 1);
        if (n <= 0) continue; 
        int b, c, d = abs(n - m);
        b = r - d, c = r;
        if (n < m) swap(b, c);
        printf("%d %d %d\n", a, b, c); 
        break; 
      }
    }
  } 
  return 0;
}