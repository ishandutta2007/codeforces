#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

struct BoolArray {
  vector<int> revision;
  int cur_revision;

  BoolArray() : cur_revision(1) {
  }

  BoolArray(int n) : revision(n), cur_revision(1) {
  }

  void clear() {
    ++cur_revision;
  }

  bool operator[](int id) const {
    return revision[id] == cur_revision;
  }

  void set(int id, bool value = true) {
    revision[id] = value ? cur_revision : -1;
  }
};

struct Line {
  int a, b1, b2;
};
ostream& operator<<(ostream& out, const Line& l) {
  return out << l.a << ' ' << l.b1 << ' ' << l.b2;
}

const int maxn = 2005;
vector<int> g[maxn];
vector<Line> v[2];
BoolArray used;
vector<int> mt;
vector<char> matched;
set<pair<int, int>> pts;

bool intersects(Line x, Line y) {
  bool has = x.a >= y.b1 && x.a <= y.b2 &&
      y.a >= x.b1 && y.a <= x.b2;
  return has && !pts.count({x.a, y.a});
}

bool kuhn(int u) {
  used.set(u);
  for (int v : g[u]) {
    if (mt[v] == u) {
      continue;
    }
    if (mt[v] == -1 || (!used[mt[v]] && kuhn(mt[v]))) {
      mt[v] = u;
      return true;
    }
  }
  return false;
}

void append(vector<Line>& v, Line l) {
  if (!v.empty() && v.back().a == l.a && v.back().b2 == l.b1) {
    v.back().b2 = l.b2;
  } else {
    v.push_back(l);
  }
}

signed main() {
#ifdef LOCAL
  assert(freopen("f.in", "r", stdin));
#endif
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  map<int, vector<int>> by[2];
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    pts.emplace(x[i], y[i]);
    by[0][x[i]].push_back(y[i]);
    by[1][y[i]].push_back(x[i]);
  }
  for (int id : {0, 1}) {
    for (auto& p : by[id]) {
      sort(p.second.begin(), p.second.end());
      for (int i = 0; i < (int) p.second.size() - 1; ++i) {
        v[id].push_back(Line{p.first, p.second[i], p.second[i + 1]});
      }
    }
  }
  for (int i = 0; i < (int) v[0].size(); ++i) {
    for (int j = 0; j < (int) v[1].size(); ++j) {
      if (intersects(v[0][i], v[1][j])) {
        g[i].push_back(j);
      }
    }
  }
  used = BoolArray((int) v[0].size());
  mt.resize((int) v[1].size(), -1);
  matched.resize(v[0].size(), false);
  for (int i = 0; i < (int) v[0].size(); ++i) {
    used.clear();
    if (kuhn(i)) {
      matched[i] = true;
    }
  }
  used.clear();
  for (int i = 0; i < (int) v[0].size(); ++i) {
    if (!matched[i] && !used[i]) {
      kuhn(i);
    }
  }

  vector<char> usedv((int) v[1].size());
  vector<Line> res[2];
  for (int i = 0; i < n; ++i) {
    res[0].push_back(Line{x[i], y[i], y[i]});
    res[1].push_back(Line{y[i], x[i], x[i]});
  }

  for (int i = 0; i < (int) v[0].size(); ++i) {
    if (used[i]) {
      res[0].push_back(v[0][i]);
      for (auto v : g[i]) {
        usedv[v] = true;
      }
    }
  }
  for (int i = 0; i < (int) v[1].size(); ++i) {
    if (!usedv[i]) {
      res[1].push_back(v[1][i]);
    }
  }
  for (int id : {0, 1}) {
    sort(res[id].begin(), res[id].end(), [](const Line& a, const Line& b) {
      if (a.a != b.a) {
        return a.a < b.a;
      }
      if (a.b1 != b.b1) {
        return a.b1 < b.b1;
      }
      return a.b2 < b.b2;
    });
    vector<Line> res2;
    for (auto x : res[id]) {
      append(res2, x);
    }
    res[id] = res2;
  }
  for (int id : {1, 0}) {
    cout << (int) res[id].size() << '\n';
    for (auto x : res[id]) {
      if (id == 1) {
        cout << x.b1 << ' ' << x.a << ' ' << x.b2 << ' ' << x.a << '\n';
      } else {
        cout << x.a << ' ' << x.b1 << ' ' << x.a << ' ' << x.b2 << '\n';
      }
    }
  }
}