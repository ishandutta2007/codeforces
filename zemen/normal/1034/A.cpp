#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int B = 1.5e7 + 1000;
int minp[B];
int cnt[B];
vector<int> p;

void sieve() {
  for (int i = 2; i < B; ++i) {
    if (minp[i] == 0) {
      minp[i] = i;
      p.push_back(i);
    }
    for (int j = 0; j < (int) p.size() && p[j] <= minp[i] && i * p[j] < B; ++j) {
      minp[i * p[j]] = p[j];
    }
  }
}

int gcd(int a, int b) {
  while (a && b) {
    if (a >= b) {
      a %= b;
    } else {
      b %= a;
    }
  }
  return a + b;
}

signed main() {
#ifdef LOCAL
  assert(freopen("a.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  sieve();
  int n;
  cin >> n;
  vector<int> a(n);
  int g = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    g = gcd(g, a[i]);
  }
  for (int i = 0; i < B; ++i) {
    cnt[i] = n;
  }
  for (int i = 0; i < n; ++i) {
    int x = a[i] / g;
    int pr = -1;
    while (x > 1) {
      int p = minp[x];
      if (p != pr) {
        cnt[p]--;
        //cerr << "del " << p << '\n';
      }
      pr = p;
      x /= p;
    }
  }
  int res = n;
  for (int i = 0; i < B; ++i) {
    res = min(res, cnt[i]);
  }
  if (res == n) {
    res = -1;
  }
  cout << res << '\n';
}