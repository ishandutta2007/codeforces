#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

using Mask = bitset<120>;
int g[120][120];
map<vector<int>, int> perm_to_id;
vector<int> pows[120];

void pre(int k) {
  vector<int> p(k);
  iota(p.begin(), p.end(), 0);
  vector<vector<int>> perms;
  do {
    perm_to_id[p] = perms.size();
    perms.push_back(p);
  } while (next_permutation(p.begin(), p.end()));

  for (int i = 0; i < (int) perms.size(); ++i) {
    for (int j = 0; j < (int) perms.size(); ++j) {
      vector<int> to(k);
      for (int e = 0; e < k; ++e) {
        to[e] = perms[j][perms[i][e]];
      }
      g[i][j] = perm_to_id.at(to);
    }
  }
  for (int i = 0; i < (int) perms.size(); ++i) {
    pows[i].push_back(0);
    while (true) {
      int j = g[pows[i].back()][i];
      if (j == 0) {
        break;
      } else {
        pows[i].push_back(j);
      }
    }
  }
}

struct E {
  Mask mask;
  int len;
  vector<int> base;
};

void combine(E& res, int x) {
  if (res.mask[x]) {
    return;
  }
  res.base.push_back(x);

  res.mask.reset();
  vector<int> q{0};
  for (int ii = 0; ii < (int) q.size(); ++ii) {
    int x = q[ii];
    for (int b : res.base) {
      int to = g[x][b];
      if (!res.mask[to]) {
        res.mask[to] = 1;
        q.push_back(to);
      }
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;
  pre(k);
  vector<E> masks;
  ll res = 0;
  for (int i = 0; i < n; ++i) {
    vector<int> p(k);
    for (int j = 0; j < k; ++j) {
      cin >> p[j];
      --p[j];
    }
    int x = perm_to_id.at(p);
    vector<E> nmasks;

    auto append = [&nmasks](E p) {
      if (!nmasks.empty() && nmasks.back().mask == p.mask) {
        nmasks.back().len += p.len;
      } else {
        nmasks.push_back(p);
      }
    };

    for (auto p : masks) {
      combine(p, x);
      append(p);
    }
    Mask m;
    for (auto y : pows[x]) {
      m[y] = 1;
    }
    append(E{m, 1, {x}});
    masks = nmasks;
    for (auto p : masks) {
      res += p.len * p.mask.count();
    }
  }
  cout << res << '\n';
}