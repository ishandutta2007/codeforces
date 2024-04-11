#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 100100;
int d[maxn];

const int M = 1 << 9;
ll c[M];
ll delta[M];
bool want[M];

void pre() {
  for (int i = 1; i < maxn; ++i) {
    for (int j = i; j < maxn; j += i) {
      ++d[j];
    }
  }

  for (int mask = 0; mask < M; ++mask) {
    vector<int> p(3);
    iota(p.begin(), p.end(), 0);
    int ps = 0;
    do {
      int ok = 0;
      for (int i = 0; i < 3; ++i) {
        if (mask & (1 << (i + 3 * p[i]))) {
          ++ok;
        }
      }
      if (ok == 3) {
        ++ps;
      }
    } while (next_permutation(p.begin(), p.end()));
    want[mask] = ps > 0;
    delta[mask] = want[mask] - c[mask];
    //if (delta[mask] != 0 && __builtin_popcount(mask) == 3) {
      //cerr << bitset<9>(mask) << ' ' << delta[mask] << '\n';
    //}
    for (int to = 0; to < M; ++to) {
      if ((mask & to) == mask) {
        c[to] += delta[mask];
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    assert(want[i] == c[i]);
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

ll x[8];
void solve() {
  int a[3];
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  for (int m = 1; m < 8; ++m) {
    int g = 0;
    for (int i = 0; i < 3; ++i) {
      if (m & (1 << i)) {
        g = gcd(g, a[i]);
      }
    }
    x[m] = d[g];
  }
  ll res = 0;
  for (int mask = 0; mask < M; ++mask) {
    if (delta[mask] == 0) {
      continue;
    }

    int ms[3];
    for (int i = 0; i < 3; ++i) {
      ms[i] = (mask >> (3 * i)) & 7;
    }
    ll cnt = x[ms[0]] * x[ms[1]] * x[ms[2]];
    //ll ini = cnt;
    cnt += x[ms[0] | ms[1]] * x[ms[2]];
    cnt += x[ms[0] | ms[2]] * x[ms[1]];
    cnt += x[ms[2] | ms[1]] * x[ms[0]];
    cnt += 2 * x[ms[2] | ms[1] | ms[0]];
    //cerr << bitset<9>(mask) << ' ' << ini << ' ' << cnt << '\n';
    //assert(cnt % 6 == 0);
    //cnt /= 6;

    if (cnt == 0) {
      continue;
    }
    //if (cnt == 2) {
      //cerr << bitset<9>(mask) << ' ' << delta[mask] << ' ' << cnt << '\n';
    //}
    res += delta[mask] * cnt;
  }
  assert(res % 6 == 0);
  res /= 6;
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  pre();
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
}