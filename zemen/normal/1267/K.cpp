#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()
typedef long double ld;
typedef long long ll;

ll fact(int n) {
  ll ans = 1;
  for (ll i = 1; i <= n; ++i)
    ans *= i;
  return ans;
}

ll calc(map<int, int> cnt) {
  int m = 0;
  for (auto e : cnt)
    m += e.second;
  int rem = cnt[0];

  ll ans = 1;
  
  for (int i = 1; i <= m; ++i) {
    rem += cnt[i];
    ans *= rem;
    --rem;
  }
  if (ans == 0)
    return 0;

  assert(rem == 0);

  for (auto e : cnt) {
    ans /= fact(e.second);
  }
    
  return ans;
}

int main() {
#ifdef LOCAL
  assert(freopen("k.in", "r", stdin));
#endif

  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    map<int, int> cnt;
    for (int i = 2; n; ++i) {
      cnt[n % i]++;
      n /= i;
    }

    ll ans = 0;
    ans += calc(cnt);
    if (cnt[0] > 0) {
      cnt[0]--;
      ans -= calc(cnt);
    }
    ans--;
    cout << ans << "\n";
  }
}