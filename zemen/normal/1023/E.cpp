#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int n, qs;

bool ask(int x1, int y1, int x2, int y2) {
  //assert(++qs <= 4 * n);
  assert(x2 - x1 + y2 - y1 >= n - 1);
  cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1 << endl;
  string tmp;
  cin >> tmp;
  return tmp == "YES";
}

bool ask(pair<int, int> a, pair<int, int> b) {
  return ask(a.first, a.second, b.first, b.second);
}

signed main() {
  int n;
  cin >> n;
  pair<int, int> S(0, 0);
  pair<int, int> T(n - 1, n - 1);
  vector<pair<int, int>> a{S}, b{T};
  pair<int, int> t = S;
  for (int i = 0; i < n - 1; ++i) {
    t.first++;
    if (!ask(t, T)) {
      ++t.second;
      --t.first;
    }
    a.push_back(t);
  }
  t = pair<int, int>(n - 1, n - 1);
  for (int i = 0; i < n - 1; ++i) {
    t.second--;
    if (!ask(S, t)) {
      ++t.second;
      --t.first;
    }
    b.push_back(t);
  }
  assert(a.back() == b.back());
  b.pop_back();
  reverse(b.begin(), b.end());
  a.insert(a.end(), b.begin(), b.end());
  cout << "! ";
  for (int i = 0; i < 2 * n - 2; ++i) {
    if (a[i].first == a[i + 1].first) {
      cout << "R";
    } else {
      cout << "D";
    }
  }
  cout << endl;
}