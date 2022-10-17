#include <bits/stdc++.h>
using namespace std;
int t, m, d, w;
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d%d%d", &m, &d, &w);
    int n = min(m, d), gcd = __gcd(w, d - 1), d = w / gcd;
    n += d - 1; int x = n / d, y = n % d + 1;
    auto cal = [&](int x) {
      return 1ll * x * (x - 1) / 2;
    }; printf("%lld\n", 1ll * cal(x) * y + 1ll * cal(x - 1) * (d - y));
  }
  return 0;
}