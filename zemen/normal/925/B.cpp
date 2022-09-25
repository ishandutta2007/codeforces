#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int round_up(int a, int b) {
  return (a + b - 1) / b;
}

void solve(const vector<pair<int, int>>& a, int x1, int x2, bool swapped) {
  int n = (int) a.size();
  for (int i = 0; i < n; ++i) {
    int k1 = round_up(x1, a[i].first);
    int j = i + k1;
    if (j < n) {
      int k2 = round_up(x2, a[j].first);
      int to = j + k2;
      if (to <= n) {
        cout << "Yes\n";
        vector<int> v1, v2;
        for (int x = i; x < j; ++x) {
          v1.push_back(a[x].second);
        }
        for (int x = j; x < to; ++x) {
          v2.push_back(a[x].second);
        }
        if (swapped) {
          swap(v1, v2);
        }
        cout << v1.size() << ' ' << v2.size() << '\n';
        for (int x : v1) {
          cout << x + 1 << ' ';
        }
        cout << '\n';
        for (int x : v2) {
          cout << x + 1 << ' ';
        }
        cout << '\n';
        exit(0);
      }
    }
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("b.in", "r", stdin));
#endif
  int n, x1, x2;
  cin >> n >> x1 >> x2;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a.begin(), a.end());
  solve(a, x1, x2, false);
  solve(a, x2, x1, true);
  cout << "No\n";
}