#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int main() {
  int n, b, q; cin >> n >> b >> q;
  vector<PII> A; A.push_back(PII(b, n));
  for (int i = 0; i < q; ++i) {
    int a, b; cin >> a >> b;
    A.push_back(PII(a, b));
  }
  sort(A.begin(), A.end());
  for (int msk = 0; msk < 32; ++msk) {
    int l = 0, r = 0, pb = 0, pn = 0;
    for (auto &x: A) {
      int nb = x.first, nn = x.second;
      int ok = 0, bad = 0;
      for (int i = pb + 1; i <= nb; ++i) {
        if (msk >> (i % 5) & 1) ++ok;
        else ++bad;
      }
      if (nn < pn || nn - pn > nb - pb) {
        puts("unfair");
        return 0;
      }
      l += max(0, nn - pn - bad);
      r += min(nn - pn, ok);
      pb = nb, pn = nn;
    }
    int tot = n / 5 * __builtin_popcount(msk);
    if (tot < l || tot > r) {
      puts("unfair");
      return 0;
    }
  }
  puts("fair");
  return 0;
}