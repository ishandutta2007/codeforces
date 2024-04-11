#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

void check(bool expr) {
  if (!expr) {
    cout << "NO\n";
    exit(0);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("d.in", "r", stdin));
#endif
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<vector<int>> pos(q);
  set<int> bad;
  set<int> z;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    if (a[i] >= 0) {
      pos[a[i]].push_back(i);
      bad.insert(i);
    } else {
      z.insert(i);
    }
  }
  bool need_last = false;
  for (int i = q - 1; i >= 0; --i) {
    if (pos[i].empty()) {
      if (i == q - 1) {
        need_last = true;
      }
      continue;
    }
    for (auto x : pos[i]) {
      bad.erase(x);
    }
    int l = pos[i].front();
    int r = pos[i].back();
    if (l < r) {
      auto it = bad.upper_bound(l);
      check(it == bad.end() || *it >= r);
    }
    while (true) {
      auto it = z.lower_bound(l);
      if (it != z.end() && *it <= r) {
        if (need_last) {
          a[*it] = q - 1;
          need_last = false;
        } else {
          a[*it] = i;
        }
        z.erase(it);
      } else {
        break;
      }
    }
  }
  if (need_last) {
    check(!z.empty());
    a[*z.begin()] = q - 1;
    z.erase(z.begin());
  }
  for (int i = 0; i < n - 1; ++i) {
    if (a[i] != -1 && a[i + 1] == -1) {
      a[i + 1] = a[i];
    }
  }
  for (int i = n - 1; i > 0; --i) {
    if (a[i] != -1 && a[i - 1] == -1) {
      a[i - 1] = a[i];
    }
  }
  cout << "YES\n";
  for (int x : a) {
    cout << x+1 << ' ';
  }
  cout << '\n';
}