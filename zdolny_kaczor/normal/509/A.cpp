#include <bits/stdc++.h>
using namespace std;
const int mod = 1187401517;
int inv(int x) {
  int r = 1, e = mod - 2;
  while (e) {
    if (e & 1)
      r = r * 1ll * x % mod;
    x = x * 1ll * x % mod;
    e >>= 1;
  }
  return r;
}
const int nax = 1410;
int fac[nax], fin[nax];
int main() {
  fac[0] = 1;
  for (int i = 1; i < nax; ++i)
    fac[i] = fac[i - 1] * 1ll * i % mod;
  fin[nax - 1] = inv(fac[nax - 1]);
  for (int i = nax - 2; i >= 0; --i)
    fin[i] = fin[i + 1] * (i + 1ll) % mod;
  int n;
  scanf("%d", &n);
  n--;
  printf("%lld\n", fac[n * 2] * 1ll * fin[n] % mod * fin[n] % mod);
}