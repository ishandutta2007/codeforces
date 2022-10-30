#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;

ll x[N];

void go() {
  ll n, a, b; cin >> n >> a >> b;
  swap(a, b);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }
  ll ans = (1ll << 60);
  ll tmp = 0;
  for (int i = n - 1; i >= 0; --i) {
    tmp += (x[i + 1] - x[i]) * (n - i) * a;
    // cerr << "tmp = " << tmp << endl;
    // cerr << "i = " << i << " , val = " << tmp + (a + b) * x[i] << endl;
    ans = min(ans, tmp + (a + b) * x[i]);
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