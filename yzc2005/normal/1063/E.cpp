#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, a[N];
bool vis[N];
char s[N][N];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    fill(s[i] + 1, s[i] + n + 1, '.');
    s[i][n + 1] = '\n';
  }
  int ptr = 1, pos = 0;
  bool has_vis = false;
  for (int i = 1; i <= n; ++i) {
    if (vis[i]) continue;
    vector<int> cyc = {i};
    for (int j = a[i]; j != i; j = a[j])
      cyc.emplace_back(j), vis[j] = true;
    if (cyc.size() == 1u) continue;
    if (!has_vis) rotate(cyc.begin(), cyc.begin() + 1, cyc.end());
    int pre_ptr = ptr;
    for (int i = 0; i < int(cyc.size()) - 1; ++i) {
      int x = cyc[i], y = cyc[i + 1];
      if (x < y) {
        s[ptr][x] = '/';
        s[ptr++][y] = '/';
      } else {
        s[ptr][x] = '\\';
        s[ptr++][y] = '\\';
      }
    } 
    if (!has_vis) { 
      has_vis = true; 
      pos = cyc.back(); 
      continue; 
    }
    int x = cyc.back(), y = cyc[0];
    if (x < pos) {
      s[ptr][x] = '/';
      s[ptr++][pos] = '/';
    } else {
      s[ptr][x] = '\\';
      s[ptr++][pos] = '\\';
    }
    s[pre_ptr][pos] = s[pre_ptr][y] = '/';
  }
  printf("%d\n", n - has_vis);
  for (int i = 1; i <= n; ++i) printf("%s\n", s[i] + 1);
  return 0;
}