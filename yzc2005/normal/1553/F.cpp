#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 300005;
int n, a[N];
ll cnt[N];

struct BIT {
  ll c[N];
  void add(int p, int x) {
    for (; p < N; p += p & -p)
      c[p] += x;
  }
  ll query(int p) {
    ll res = 0;
    for (; p; p -= p & -p) res += c[p];
    return res;
  }
  ll query(int l, int r) {
    if (!l) return query(r);
    return query(r) - query(l - 1);
  }
} t1, t2;

int main() {
  scanf("%d", &n);
  ll cur = 0, curr = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    curr += cur + 1ll * a[i] * (i - 1);
    cur += a[i];
    int lim = a[i] / (a[i] / sqrt(a[i]));
    for (int j = 1; j <= lim; ++j) 
      if (cnt[j]) curr -= (a[i] / j) * j;
    lim = a[i] / (lim + 1);
    for (int j = 1; j <= lim; ++j) 
      curr -= t2.query(a[i] / (j + 1) + 1, a[i] / j) * j;
    for (int l = 0, r; l < N; l = r + 1) {
      r = min(l + a[i], N) - 1;
      curr -= t1.query(l, r) * a[i] * (l / a[i]);
    }
    printf("%lld ", curr);
    ++cnt[a[i]], t1.add(a[i], 1), t2.add(a[i], a[i]);
  }
  return 0;
}