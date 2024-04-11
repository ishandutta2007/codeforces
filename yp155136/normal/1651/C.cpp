#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

ll a[N], b[N];
set<ll> sta, stb;

ll Qa(ll x) {
  ll ret = 0x3f3f3f3f;
  auto iter = sta.lower_bound(x);
  if (iter != sta.end()) {
    ret = min(ret, *iter - x);
  }
  if (iter != sta.begin()) {
    ret = min(ret, x - *prev(iter));
  }
  return ret;
}

ll Qb(ll x) {
  ll ret = 0x3f3f3f3f;
  auto iter = stb.lower_bound(x);
  if (iter != stb.end()) {
    ret = min(ret, *iter - x);
  }
  if (iter != stb.begin()) {
    ret = min(ret, x - *prev(iter));
  }
  return ret;
}

void go() {
  sta.clear();
  stb.clear();
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    sta.insert(a[i]);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    stb.insert(b[i]);
  }
  ll ans = abs(a[1] - b[1]) + abs(a[n] - b[n]);
  ans = min(ans, abs(a[1] - b[n]) + abs(a[n] - b[1]));
  ans = min(ans, abs(a[1] - b[1]) + Qb(a[n]) + Qa(b[n]));
  ans = min(ans, abs(a[1] - b[n]) + Qb(a[n]) + Qa(b[1]));
  ans = min(ans, abs(a[n] - b[1]) + Qb(a[1]) + Qa(b[n]));
  ans = min(ans, abs(a[n] - b[n]) + Qb(a[1]) + Qa(b[1]));
  ans = min(ans, Qa(b[1]) + Qa(b[n]) + Qb(a[1]) + Qb(a[n]));
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}