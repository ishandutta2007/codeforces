#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

namespace Hashing {
const int maxn = 1001000;

bool isPrime(ll mod) {
  for (ll x = 2; x * x <= mod; ++x) {
    if (mod % x == 0) {
      return false;
    }
  }
  return true;
}

static const int k = 2;
ll mods[k] = {1000000033, 1000000087};
int alpha = 31;

struct AlphaPowers {
  ll a[maxn][k];

  void build() {
    for (int j = 0; j < k; ++j) {
      a[0][j] = 1;
    }
    for (int i = 1; i < maxn; ++i) {
      for (int j = 0; j < k; ++j) {
        a[i][j] = (a[i - 1][j] * alpha) % mods[j];
      }
    }
  }

} alpha_pow;

struct Hash {
  array<ll, k> h;
  int len = 0;

  Hash() {
    fill(h.begin(), h.end(), 0);
  }

  explicit Hash(ll elem) : len(1) {
    for (int i = 0; i < k; ++i) {
      h[i] = (elem + 1) % mods[i];
    }
  }

  void operator+=(const Hash& other) {
    len += other.len;
    for (int i = 0; i < k; ++i) {
      h[i] = (h[i] * alpha_pow.a[other.len][i] + other.h[i]) % mods[i];
    }
  }

  Hash operator+(const Hash& other) const {
    Hash res = *this;
    res += other;
    return res;
  }

  Hash operator-(const Hash& other) const {
    assert(len >= other.len);
    Hash res;
    res.len = len - other.len;
    for (int i = 0; i < k; ++i) {
      res.h[i] = (h[i] - other.h[i] * alpha_pow.a[len - other.len][i]) % mods[i];
      if (res.h[i] < 0) {
        res.h[i] += mods[i];
      }
    }
    return res;
  }

  bool operator==(const Hash& other) const {
    return len == other.len && equal(h.begin(), h.end(), other.h.begin());
  }

  bool operator!=(const Hash& other) const {
    return !operator==(other);
  }

  bool operator<(const Hash& other) const {
    if (len != other.len) {
      return len < other.len;
    }
    return h < other.h;
  }
};
}  // namespace Hashing
using Hashing::Hash;

void solve() {
  string s, t;
  cin >> s >> t;
  int num0 = 0, num1 = 0;
  for (auto c : s) {
    if (c == '0') {
      ++num0;
    } else {
      ++num1;
    }
  }

  vector<Hash> h((int) t.size() + 1);
  for (int i = 0; i < (int) t.size(); ++i) {
    h[i + 1] = h[i] + Hash(t[i]);
  }

  int res = 0;
  for (int l0 = 1; l0 * num0 < (int) t.size(); ++l0) {
    int l1 = ((int) t.size() - l0 * num0) / num1;
    if (l0 * num0 + l1 * num1 != (int) t.size() || l1 <= 0) {
      continue;
    }
    Hash hh[2];
    int p = 0;
    bool ok = true;
    for (auto c : s) {
      int l = c == '0' ? l0 : l1;
      Hash ch = h[p + l] - h[p];
      p += l;
      int id = c - '0';
      if (hh[id].len == 0) {
        hh[id] = ch;
      } else if (hh[id] != ch) {
        ok = false;
      }
    }
    if (hh[0] == hh[1]) {
      ok = false;
    }
    res += ok;
  }
  cout << res << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  ll seed;
  asm("rdtsc" : "=A"(seed));
  mt19937 rnd(seed);
  for (int id = 0; id < Hashing::k; ++id) {
    Hashing::mods[id] = rnd() % int(1e8) + int(9e8);
    while (!Hashing::isPrime(Hashing::mods[id])) {
      ++Hashing::mods[id];
    }
    //cerr << "mod" << id << ": " << Hashing::mods[id] << '\n';
  }
  Hashing::alpha = rnd() % 100 + 100;
  //cerr << "alpha: " << Hashing::alpha << '\n';
  Hashing::alpha_pow.build();
  solve();
}