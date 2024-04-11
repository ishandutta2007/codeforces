#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
template<typename T>
T add(T x) {
  return x;
}
template<typename T, typename... Ts>
T add(T x, Ts... y) {
  T res = x + add(y...);
  if (res >= mod)
    res -= mod;
  return res;
}
template<typename T, typename... Ts>
T sub(T x, Ts... y) {
  return add(x, mod - add(y...));
}
template<typename T, typename... Ts>
void udd(T& x, Ts... y) {
  x = add(x, y...);
}
template<typename T, typename... Ts>
void uub(T& x, Ts... y) {
  x = sub(x, y...);
}
template<typename T>
T mul(T x) {
  return x;
}
template<typename T, typename... Ts>
T mul(T x, Ts... y) {
  return (x * 1ll * mul(y...)) % mod;
}
template<typename T, typename... Ts>
void uul(T& x, Ts... y) {
  x = mul(x, y...);
}
int bin(int a, ll deg) {
  int r = 1;
  while (deg) {
    if (deg & 1)
      uul(r, a);
    deg >>= 1;
    uul(a, a);
  }
  return r;
}
int inv(int x) {
  assert(x);
  return bin(x, mod - 2);
}

void solve() {
  int n, p;
  cin >> n >> p;
  vector<int> k(n);
  for (int i = 0; i < n; ++i) {
    cin >> k[i];
  }
  sort(k.rbegin(), k.rend());
  const ll inf = 1e9;
  ll bal = 0;
  int balmod = 0;
  int last = k.front();

  auto shift = [&](int pw) {
    uul(balmod, bin(p, pw));
    for (int it = 0; it < pw; ++it) {
      if (bal == 0 || p == 1 || bal >= inf || bal <= -inf) {
        break;
      }
      bal *= p;
      if (bal < -inf) {
        bal = -inf;
      } else if (bal > inf) {
        bal = inf;
      }
    }
  };

  for (auto t : k) {
    int pw = last - t;
    last = t;
    shift(pw);

    if (bal > 0) {
      --bal;
      balmod = sub(balmod, 1);
    } else {
      ++bal;
      balmod = add(balmod, 1);
    }
  }
  shift(last);
  cout << balmod << '\n';
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    solve();
  }
}