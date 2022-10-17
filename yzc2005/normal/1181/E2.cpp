#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
using pr = pair<int, int>;
using prr = pair<pr, int>;
int n;
prr p[N][4];
bool solve(set<prr> s[4]) {
  int m = s[0].size();
  if (m == 1) {
    return true;
  }
  int mx[4];
  set<prr>::iterator it[4];
  for (int i = 0; i < 4; ++i) {
    it[i] = s[i].begin();
    mx[i] = -2e9;
  }
  for (int i = 1; i <= m / 2; ++i) {
    for (int j = 0; j < 4; ++j) {
      mx[j] = max(mx[j], it[j]++ -> first.second);
      if (mx[j] <= it[j] -> first.first) {
        set<prr> t[4];
        auto it = s[j].begin();
        for (int k = 1; k <= i; ++k) {
          int id = it++ -> second;
          for (int l = 0; l < 4; ++l) {
            t[l].insert(p[id][l]);
            s[l].erase(p[id][l]);
          }
        }
        return solve(s) && solve(t);
      }
    }
  }
  return false;
}
int main() {
  scanf("%d", &n);
  set<prr> s[4];
  for (int i = 1; i <= n; ++i) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    p[i][0] = {{a, c}, i};
    p[i][1] = {{-c, -a}, i};
    p[i][2] = {{b, d}, i};
    p[i][3] = {{-d, -b}, i};
    for (int j = 0; j < 4; ++j) {
      s[j].insert(p[i][j]);
    }
  }
  bool ok = solve(s);
  if (ok) {
    puts("YES");
  } else {
    puts("NO");
  }
  return 0;
}