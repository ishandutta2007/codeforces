#include <bits/stdc++.h>

using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

const int MN = 5050;
const ll INF = TEN(18);

ll a[MN];
ll memo[MN][MN][2];
bool vis[MN][MN][2];
ll calc(int p, int k, bool f) {
  if (k == 0) return 0;
  if (p <= -1) return INF;
  if (vis[p][k][f]) return memo[p][k][f];
  vis[p][k][f] = true;

  ll ans = calc(p-1, k, false);

  {
    // use p
    ll buf = 0;
    {
      ll bk = a[p + 1];
      if (f) bk = min(bk, a[p + 2] - 1);
      buf += max(0LL, bk - a[p] + 1);
    }
    if (p) {
      buf += max(0LL, a[p-1] - a[p] + 1);
    }
    buf += calc(p-2, k-1, true);

    ans = min(ans, buf);
  }
  return memo[p][k][f] = ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  a[n] = -1;

  for (int k = 1; k <= (n+1)/2; k++) {
    cout << calc(n-1, k, false) << " ";
  }
  cout << endl;
  return 0;
}