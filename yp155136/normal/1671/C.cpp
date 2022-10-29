#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

ll a[N];
ll pre[N];

void go() {
  ll n, x; cin >> n >> x;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; ++i) {
    pre[i] = pre[i - 1] + a[i];
  }
  ll ans = 0;
  ll day = 0;
  for (int i = n; i >= 1; --i) {
    if (pre[i] > x) continue;
    ll can_last = (x - pre[i]) / i;
    if (can_last < day) continue;
    ans += (can_last - day + 1) * 1ll * i;
    day = can_last + 1;
  }
  cout << ans << '\n';
}

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}