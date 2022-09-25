#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

map<int, string> E, T, F;

bool update(map<int, string>& m, int val, string s) {
  if (!m.count(val)) {
    m[val] = s;
    return true;
  }
  if (m[val].size() > s.size()) {
    m[val] = s;
    return true;
  }
  if (m[val].size() == s.size() && m[val] > s) {
    m[val] = s;
    return true;
  }
  return false;
}

bool genf() {
  bool ok = false;
  for (auto p : E) {
    int val = p.first;
    string s = "(" + p.second + ")";
    ok |= update(F, val, s);
  }
  for (auto p : F) {
    string s = "!" + p.second;
    int val = 255 ^ p.first;
    ok |= update(F, val, s);
  }
  return ok;
}

bool gent() {
  bool ok = false;
  for (auto p : F) {
    string s = p.second;
    int val = p.first;
    ok |= update(T, val, s);
  }
  for (auto p1 : T) {
    for (auto p2 : F) {
      string s = p1.second + "&" + p2.second;
      int val = p1.first & p2.first;
      ok |= update(T, val, s);
    }
  }
  return ok;
}

bool gene() {
  bool ok = false;
  for (auto p : T) {
    string s = p.second;
    int val = p.first;
    ok |= update(E, val, s);
  }
  for (auto p1 : E) {
    for (auto p2 : T) {
      string s = p1.second + "|" + p2.second;
      int val = p1.first | p2.first;
      ok |= update(E, val, s);
    }
  }
  return ok;
}

signed main() {
#ifdef LOCAL
  assert(freopen("e.in", "r", stdin));
#endif
  int xx = 0, yy = 0, zz = 0;
  for (int i = 0; i < 8; ++i) {
    if (i & 1) {
      zz |= 1 << i;
    }
    if (i & 2) {
      yy |= 1 << i;
    }
    if (i & 4) {
      xx |= 1 << i;
    }
  }
  F[xx] = "x";
  F[yy] = "y";
  F[zz] = "z";
  while (genf() || gent() || gene());
  //for (int i = 0; i < 255; ++i) {
    //cerr << E[i] << '\n';
  //}
  int tn;
  cin >> tn;
  for (int i = 0; i < tn; ++i) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int x = stoi(s, nullptr, 2);
    cout << E[x] << '\n';
  }
}