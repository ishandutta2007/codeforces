#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ld, ll> pdl;
#define F first
#define S second
const ll mod = 1000000007;
const int N = 1000006;
const ld eps = 1e-9;
const pdl _INF = make_pair(-1, -1);

pdl dp[N][5];
pdl val[N];
ld log_v[N];

bool eq(pdl p1, pdl p2) {
  if (abs(p1.F - p2.F) <= eps) {
    return p1.F == p2.F;
  }
  return false;
}

pdl operator+(const pdl &p1, const pdl &p2) {
  return make_pair(p1.F + p2.F, p1.S * p2.S % mod);
}

void update(pdl &v1, pdl v2) {
  if (v1 == _INF) {
    v1 = v2;
    return;
  }
  if (v2 == _INF) return;
  if (eq(v1, v2)) return;
  v1 = max(v1, v2);
}

void build() {
  for (int i = 1; i <= 7; ++i) {
    log_v[i] = log(i);
    val[i] = make_pair(log_v[i], i);
  }
  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 5; ++j) {
      dp[i][j] = _INF;
    }
  }
  dp[0][1] = make_pair(0, 1);
  // dp[i][j] --> max sum = i, last is j
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= 4; ++j) {
      int from = i - j;
      if (from < 0) continue;
      for (int k = j; k >= 1; --k) {
        if (dp[from][k] == _INF) continue;
        update(dp[i][j], dp[from][k] + val[j]);
      }
    }
  }
  for (int i = 1; i < N; ++i) {
    for (int j = 1; j <= 4; ++j) {
      int from = i - j;
      if (from < 0) continue;
      int cnt = 0;
      int mask = 0;
      for (int k = j; k >= 1; --k) {
        if (dp[from][k] == _INF) continue;
        // update(dp[i][j], dp[from][k] + val[j]);
        if (eq(dp[i][j], dp[from][k] + val[j])) {
          ++cnt;
          // mask |= ;
        }
      }
    }
  }
}

int p[N];
bool vis[N];

int solve_3(vector<int> &v) {
  // all 3
  ll cnt[4] = {0, 0, 0, 0};
  ll ans1 = 0;
  for (int i : v) {
    ans1 += (i - 1) / 3;
    cnt[i % 3]++;
  }
  ll _ = min(cnt[2], cnt[1]);
  ans1 += min(cnt[2], cnt[1]);
  cnt[2] -= _;
  cnt[1] -= _;
  if (cnt[1] > 0) {
    assert(cnt[1] % 3 == 0);
    ans1 += cnt[1] / 3 * 2;
  }
  else if (cnt[2] > 0) {
    assert(cnt[2] % 3 == 0);
    ans1 += cnt[2];
  }
  return ans1;
}

vector<int> pos[N];

int remove_22(vector<int> v) {
  int ret = 0x3f3f3f3f;
  if (pos[2].size() >= 2) {
    v[pos[2][0]] -= 2;
    v[pos[2][1]] -= 2;
    ret = min(ret, solve_3(v));
    v[pos[2][0]] += 2;
    v[pos[2][1]] += 2;
  }
  if (pos[2].size() >= 1) {
    v[pos[2][0]] -= 2;
    for (int i = 3; i <= 11; ++i) {
      if (pos[i].size()) {
        v[pos[i][0]] -= 2;
        ret = min(ret, solve_3(v) + 1);
        v[pos[i][0]] += 2;
      }
    }
    if (pos[1].size() >= 2) {
      v[pos[1][0]] -= 1;
      v[pos[1][1]] -= 1;
      ret = min(ret, solve_3(v) + 1);
      v[pos[1][0]] += 1;
      v[pos[1][1]] += 1;
    }
    v[pos[2][0]] += 2;
  }
  if (pos[2].size() >= 0) {
    if (pos[1].size() >= 4) {
      v[pos[1][0]] -= 1;
      v[pos[1][1]] -= 1;
      v[pos[1][2]] -= 1;
      v[pos[1][3]] -= 1;
      ret = min(ret, solve_3(v) + 2);
      v[pos[1][0]] += 1;
      v[pos[1][1]] += 1;
      v[pos[1][2]] += 1;
      v[pos[1][3]] += 1;
    }
    if (pos[1].size() >= 3) {
      v[pos[1][0]] -= 1;
      v[pos[1][1]] -= 1;
      v[pos[1][2]] -= 1;
      for (int i = 3; i <= 11; ++i) {
        if (pos[i].size()) {
          v[pos[i][0]] -= 1;
          ret = min(ret, solve_3(v) + 3);
          v[pos[i][0]] += 1;
        }
      }
      v[pos[1][0]] += 1;
      v[pos[1][1]] += 1;
      v[pos[1][2]] += 1;
    }
    if (pos[1].size() >= 2) {
      v[pos[1][0]] -= 1;
      v[pos[1][1]] -= 1;
      for (int i = 3; i <= 11; ++i) {
        if (pos[i].size()) {
          v[pos[i][0]] -= 2;
          ret = min(ret, solve_3(v) + 2);
          v[pos[i][0]] += 2;
        }
      }
      v[pos[1][0]] += 1;
      v[pos[1][1]] += 1;
    }
    if (pos[1].size() >= 0) {
      for (int i = 3; i <= 11; ++i) {
        if (pos[i].size()) {
          for (int j = i + 1; j <= 11; ++j) {
            if (pos[j].size()) {
              v[pos[i][0]] -= 2;
              v[pos[j][0]] -= 2;
              ret = min(ret, solve_3(v) + 2);
              v[pos[i][0]] += 2;
              v[pos[j][0]] += 2;
            }
          }
        }
      }
      for (int i = 3; i <= 11; ++i) {
        if (pos[i].size() >= 2) {
          v[pos[i][0]] -= 2;
          v[pos[i][1]] -= 2;
          ret = min(ret, solve_3(v) + 2);
          v[pos[i][0]] += 2;
          v[pos[i][1]] += 2;
        }
      }
    }
  }
  // cerr << "ret22 = " << ret << endl;
  return ret;
}

int remove_4(vector<int> v) {
  int ret = 0x3f3f3f3f;
  // directly 4
  if (pos[4].size()) {
    v[pos[4][0]] -= 4;
    ret = min(ret, solve_3(v));
    v[pos[4][0]] += 4;
  }
  // cerr << "Ret 4 = " << ret << endl;
  for (int i = 5; i <= 11; ++i) {
    if (pos[i].size() > 0) {
      v[pos[i][0]] -= 4;
      ret = min(ret, solve_3(v) + 1);
      v[pos[i][0]] += 4;
    }
  }
  // cerr << "Ret 4 = " << ret << endl;
  if (pos[1].size() > 0 && pos[3].size() > 0) {
    v[pos[1][0]] -= 1;
    v[pos[3][0]] -= 3;
    ret = min(ret, solve_3(v) + 1);
    v[pos[1][0]] += 1;
    v[pos[3][0]] += 3;
  }
  if (pos[1].size() > 0) {
    for (int i = 4; i <= 11; ++i) {
      if (pos[i].size()) {
        v[pos[1][0]] -= 1;
        v[pos[i][0]] -= 3;
        ret = min(ret, solve_3(v) + 2);
        v[pos[1][0]] += 1;
        v[pos[i][0]] += 3;
      }
    }
  }
  // cerr << "Ret 4 = " << ret << endl;
  return ret;
}

void go() {
  int n; cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i];
    pos[i].clear();
    vis[i] = false;
  }
  for (int i = 0; i <= 15; ++i) {
    pos[i].clear();
  }
  vector<int> v;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    int _ = p[i];
    int sz = 1;
    while (_ != i) {
      vis[_] = true;
      _ = p[_];
      ++sz;
    }
    vis[i] = true;
    v.push_back(sz);
  }
  ll ans = 1;
  int nn = n;
  if (nn % 3 == 1) {
    ans = 4;
    nn -= 4;
  }
  else if (nn % 3 == 2) {
    ans = 2;
    nn -= 2;
  }
  while (nn != 0) {
    ans *= 3;
    nn -= 3;
    ans %= mod;
  }
  cout << ans << ' ';
  if (n % 3 == 0) {
    cout << solve_3(v) << '\n';
  }
  else if (n % 3 == 2) {
    bool has_2 = false;
    for (int i : v) {
      if (i == 2) {
        has_2 = true;
        break;
      }
    }
    if (has_2) {
      int c2 = 0;
      vector<int> vv;
      for (int i : v) {
        if (i == 2 && c2 == 0) {
          c2 = 1;
        }
        else {
          vv.push_back(i);
        }
      }
      cout << solve_3(vv) << '\n';
    }
    else {
      for (int i = 0; i < (int)v.size(); ++i) {
        int _ = v[i];
        if (_ <= 7) {
          pos[_].push_back(i);
        }
        else {
          pos[_ % 3 + 9].push_back(i);
        }
      }
      int ret = 0x3f3f3f3f;
      if (pos[1].size() >= 2) {
        v[pos[1][0]] -= 1;
        v[pos[1][1]] -= 1;
        ret = min(ret, solve_3(v) + 1);
        v[pos[1][0]] += 1;
        v[pos[1][1]] += 1;
      }
      for (int i = 3; i <= 11; ++i) {
        if (pos[i].size()) {
          v[pos[i][0]] -= 2;
          ret = min(ret, solve_3(v) + 1);
          v[pos[i][0]] += 2;
        }
      }
      cout << ret << '\n';
    }
  }
  else if (n % 3 == 1) {
    // cout << "NN" << '\n';
    for (int i = 0; i < (int)v.size(); ++i) {
      int _ = v[i];
      if (_ <= 4) {
        pos[_].push_back(i);
      }
      else {
        pos[_ % 3 + 6].push_back(i);
      }
    }
    cout << min(remove_22(v), remove_4(v)) << '\n';
  }
}

int main () {
  // build();
  ios::sync_with_stdio(0); cin.tie(0);
  int T; cin >> T;
  while (T--) {
    go();
  }
}