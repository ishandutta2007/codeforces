#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

vector<int> p, mt, used;

int ask() {
  int id;
  cin >> id;
  used[id - 1] = true;
  return id - 1;
}

int make_move(int prev) {
  if (prev != -1 && mt[prev] != -1 && !used[mt[prev]]) {
    return mt[prev];
  }
  tuple<int, int, int> best{-1, -1, -1};
  for (int i = 0; i < (int) p.size(); ++i) {
    if (used[i]) {
      continue;
    }
    int cost = mt[i] == -1 ? p[i] : p[i] - p[mt[i]];
    decltype(best) cur{mt[i] != -1, cost, i};
    best = max(best, cur);
  }
  return get<2>(best);
}

signed main() {
  int n, m;
  cin >> n >> m;
  p.assign(2 * n, 0);
  mt.assign(2 * n, -1);
  used.assign(2 * n, 0);
  for (int i = 0; i < 2 * n; ++i) {
    cin >> p[i];
  }
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    mt[a] = b;
    mt[b] = a;
  }
  int t;
  cin >> t;
  int prev = (t == 2 ? ask() : -1);
  int rem = 2 * n - (t - 1);
  while (rem > 0) {
    int id = make_move(prev);
    used[id] = true;
    cout << id+1 << endl;
    if (--rem > 0) {
      prev = ask();
      --rem;
    }
  }
}