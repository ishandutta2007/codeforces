#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 998244353;

const int N = 100006;
const int M = 512;

vector<int> G[N];

int SG[N];

int cal_sg(int i) {
  if (SG[i] != -1) return SG[i];
  vector<int> v;
  for (int to : G[i]) {
    v.push_back(cal_sg(to));
  }
  sort(v.begin(), v.end());
  v.resize(unique(v.begin(), v.end()) - v.begin());
  if (v.empty()) {
    SG[i] = 0;
  }
  else {
    v.push_back(v.back() + 87);
    for (int x = 0; ; ++x) {
      if (v[x] != x) {
        SG[i] = x;
        break;
      }
    }
  }
  return SG[i];
}

ll power(ll a, ll n) {
  ll ret = 1, now = a;
  while (n) {
    if (n & 1) ret = (ret * now) % mod;
    now = (now * now) % mod;
    n >>= 1;
  }
  return ret;
}

ll inv(ll x) {
  return power(x, mod - 2);
}

int cnt[M];

ll a[M][M + 1];

int main () {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  memset(SG, -1, sizeof(SG));
  for (int i = 1; i <= m; ++i) {
    int x, y; cin >> x >> y;
    G[x].push_back(y);
  }
  for (int i = 1; i <= n; ++i) {
    ++cnt[cal_sg(i)];
  }
  ll inv_n = inv(n + 1);
  for (int i = 0; i < M; ++i) {
    a[i][M] = (i != 0) * inv_n % mod;
    for (int j = 0; j < M; ++j) {
      if (i == j) {
        a[i][j]++;
      }
      a[i][j] -= cnt[i ^ j] * inv_n;
      a[i][j] = (a[i][j] % mod + mod) % mod;
    }
  }
  for (int i = 0; i < M; ++i) {
    if (a[i][i] == 0) {
      for (int j = i + 1; j < M; ++j) {
        if (a[j][i] != 0) {
          for (int k = 0; k <= M; ++k) {
            swap(a[i][k], a[j][k]);
          }
          break;
        }
      }
    }
    for (int j = i + 1; j < M; ++j) {
      ll del = a[j][i] * inv(a[i][i]) % mod;
      for (int k = i; k <= M; ++k) {
        a[j][k] -= a[i][k] * del;
        a[j][k] = (a[j][k] % mod + mod) % mod;
      }
      assert(a[j][i] == 0);
    }
  }
  for (int i = M - 1; i >= 0; --i) {
    a[i][M] = (a[i][M] * inv(a[i][i])) % mod;
    a[i][i] = 1;
    for (int j = i - 1; j >= 0; --j) {
      a[j][M] -= a[j][i] * a[i][M];
      a[j][i] = 0;
      a[j][M] = (a[j][M] % mod + mod) % mod;
    }
  }
  cout << a[0][M] << endl;
}