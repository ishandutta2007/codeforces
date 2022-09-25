#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int maxn = 3005;
vector<ll> pr[maxn];
vector<int> w;
vector<ll> c;
int k;
ll ans = 0;

void apply(vector<ll>& d, int w, ll c) {
  for (int i = (int) d.size() - w - 1; i >= 0; --i) {
    d[i + w] = max(d[i + w], d[i] + c);
  }
}

vector<ll> dmem[40];

void rec(int l, int r, int depth) {
  const auto& d = dmem[depth];
  if (l + 1 == r) {
    for (int i = 0; i <= min(k, w[l]); ++i) {
      ans = max(ans, d[k - i] + pr[l][i]);
    }
    return;
  }
  int c = (l + r) / 2;
  auto& d2 = dmem[depth + 1];
  for (int i = 0; i < (int) d2.size(); ++i) {
    d2[i] = d[i];
  }
  for (int i = l; i < c; ++i) {
    apply(d2, w[i], ::c[i]);
  }
  rec(c, r, depth + 1);
  for (int i = 0; i < (int) d2.size(); ++i) {
    d2[i] = d[i];
  }
  for (int i = c; i < r; ++i) {
    apply(d2, w[i], ::c[i]);
  }
  rec(l, c, depth + 1);
}

signed main() {
#ifdef LOCAL
  assert(freopen("c.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n >> k;
  w.resize(n);
  c.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> w[i];
    pr[i].resize(w[i] + 1);
    for (int j = 0; j < w[i]; ++j) {
      int x;
      cin >> x;
      c[i] += x;
      pr[i][j + 1] = pr[i][j] + x;
    }
  }
  for (int i = 0; i < 40; ++i) {
    dmem[i].resize(k + 1);
  }
  rec(0, n, 0);
  cout << ans << '\n';
}