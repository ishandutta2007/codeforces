#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n;
  cin >> n;
  V<ll> v(2*n);
  for (int i = 0; i < 2*n; i++) cin >> v[i];

  sort(begin(v), end(v));

  ll ans = (v[n-1] - v[0]) * (v[2*n-1] - v[n]);
  for (int i = 0; i < n; i++) {
    ans = min(ans, (v[2*n-1] - v[0]) * (v[i+n-1] - v[i]));
  }
  cout << ans << endl;
  return 0;
}