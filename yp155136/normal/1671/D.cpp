#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
ll a[N];

void go() {
  ll n, x; cin >> n >> x;
  ll mn = 0x3f3f3f3f, mx = -1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    mn = min(mn, a[i]);
    mx = max(mx, a[i]);
  }
  ll ans = 0;
  for (int i = 1; i <= n - 1; ++i) {
    ans += abs(a[i] - a[i + 1]);
  }
  ll ans1 = ans + (max(mn, 1ll) - 1) * 2 + (x - min(mx, x)) * 2;
  ll ans2 = ans + abs(a[1] - 1) + (mx >= x ? 0 : x - 1);
  ll ans3 = ans + abs(a[1] - x) + (mn == 1 ? 0 : x - 1);
  ll ans4 = ans + abs(a[n] - 1) + (mx >= x ? 0 : x - 1);
  ll ans5 = ans + abs(a[n] - x) + (mn == 1 ? 0 : x - 1);
  ll ans6 = ans + (max(mn, 1ll) - 1) * 2 + min(abs(a[1] - x), abs(a[n] - x));
  ll ans7 = ans + (x - min(mx, x)) * 2 + min(abs(a[1] - 1), abs(a[n] - 1));
  ll ans8 = ans + abs(a[1] - 1) + abs(a[n] - x);
  ll ans9 = ans + abs(a[1] - x) + abs(a[n] - 1);
  cout << min({ans1, ans2, ans3, ans4, ans5, ans6, ans7, ans8, ans9}) << '\n';
  /* mn = max(mn, 1ll);
  mx = min(mx, x);
  cout << ans + (mn - 1) * 2 + (x - mx) * 2 << '\n'; */
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}