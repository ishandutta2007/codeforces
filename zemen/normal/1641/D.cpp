#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

const int N = 100100;
int a_old[N][5];
int a[N][5];
vector<int> by_num[N * 5];
unique_ptr<bitset<N>> large[N * 5];
const int L = 100;

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> nums;
  nums.reserve(n * m);
  vector<pair<int, int>> by_w(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> a_old[i][j];
      nums.push_back(a_old[i][j]);
    }
    cin >> by_w[i].first;
    by_w[i].second = i;
  }
  sort(by_w.begin(), by_w.end());
  for (int i = 0; i < n; ++i) {
    int id = by_w[i].second;
    for (int j = 0; j < m; ++j) {
      a[i][j] = a_old[id][j];
    }
  }

  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      a[i][j] = lower_bound(nums.begin(), nums.end(), a[i][j]) - nums.begin();
      by_num[a[i][j]].push_back(i);
    }
  }
  for (int i = 0; i < (int) nums.size(); ++i) {
    if ((int) by_num[i].size() >= L) {
      large[i] = make_unique<bitset<N>>();
      for (int j : by_num[i]) {
        large[i]->set(j);
      }
      *large[i] = ~(*large[i]);
    }
  }

  const int inf = 2e9 + 100;
  int best = inf;
  bitset<N> mask;
  int bound = n;
  for (int i = 0; i < bound; ++i) {
    vector<int> bad;
    bool use_mask = false;
    for (int j = 0; j < m; ++j) {
      int num = a[i][j];
      if (large[num]) {
        if (use_mask) {
          mask &= *large[num];
        } else {
          use_mask = true;
          mask = *large[num];
        }
      } else {
        vector<int> bad2;
        swap(bad2, bad);
        bad.reserve(bad2.size() + by_num[num].size());
        set_union(bad2.begin(), bad2.end(), by_num[num].begin(), by_num[num].end(), back_inserter(bad));
      }
    }

    int j = 0;
    auto p = bad.begin();
    if (use_mask) {
      j = mask._Find_first();
      while (j < bound) {
        while (p != bad.end() && *p < j) {
          ++p;
        }
        if (p == bad.end() || *p > j) {
          break;
        }
        j = mask._Find_next(j);
      }
    } else {
      while (j < bound) {
        while (p != bad.end() && *p < j) {
          ++p;
        }
        if (p == bad.end() || *p > j) {
          break;
        }
        ++j;
      }
    }
    if (j < bound) {
      best = min(best, by_w[i].first + by_w[j].first);
      bound = j;
    }
  }
  if (best == inf) {
    best = -1;
  }
  cout << best << '\n';
}