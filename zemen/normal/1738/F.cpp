#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int ask(int u) {
  cout << "? " << u + 1 << endl;
  int v;
  cin >> v;
  assert(v > 0);
  --v;
  return v;
}

void answer(vector<int> col) {
  cout << '!';
  for (auto c : col) {
    cout << ' ' << c + 1;
  }
  cout << endl;
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> d(n);
  for (int i = 0; i < n; ++i) {
    cin >> d[i].first;
    d[i].second = i;
  }
  sort(d.rbegin(), d.rend());
  vector<int> col(n, -1);
  int cc = 0;
  for (auto p : d) {
    int u = p.second;
    if (col[u] != -1) {
      continue;
    }
    vector<int> comp{u};
    int deg = p.first;
    for (int it = 0; it < deg; ++it) {
      int v = ask(u);
      if (col[v] != -1) {
        for (auto& x : comp) {
          col[x] = col[v];
        }
        comp.clear();
        break;
      }
      comp.push_back(v);
    }
    if (!comp.empty()) {
      for (auto& x : comp) {
        col[x] = cc;
      }
      ++cc;
    }
  }
  answer(col);
}

signed main() {
  int tn;
  cin >> tn;
  for (int ii = 0; ii < tn; ++ii) {
    solve();
  }
}