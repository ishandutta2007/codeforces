#include <bits/stdc++.h>
const int N = 1005;
int t, n, m;
char g[N][N];
void print(std::vector<int> p) {
  puts("YES");
  for (int i = 0; i < p.size() - 1; ++i) printf("%d ", p[i] + 1);
  printf("%d\n", p.back() + 1);
}
int main() {
  for (scanf("%d", &t); t; --t) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%s", g[i]);
    bool flag = 0;
    for (int i = 0; i < n && !flag; ++i)
      for (int j = 0; j < n && !flag; ++j)
        if (i != j && g[i][j] == g[j][i]) {
          std::vector<int> ans;
          int u = i, v = j;
          for (int t = 0; t <= m; ++t) ans.push_back(u), std::swap(u, v); 
          print(ans), flag = 1;
        }
    if (!flag) {
      if (m & 1) {
        std::vector<int> ans;
        int u = 0, v = 1;
        for (int t = 0; t <= m; ++t) ans.push_back(u), std::swap(u, v); 
        print(ans);
      } else {
        m /= 2;
        if (n == 2) {
          puts("NO");
          continue;
        }
        bool check = 0;
        for (int i = 0; i < n && !check; ++i) {
          for (char c = 'a'; c <= 'b' && !check; ++c) {
            std::vector<int> in, out;
            for (int j = 0; j < n; ++j) if (i != j)
              g[i][j] == c ? out.push_back(j) : in.push_back(j);
            if (!in.empty() && !out.empty()) {
              std::vector<int> ans;
              for (int u = i, v = in.back(), i = 0; i <= m; ++i, std::swap(u, v)) ans.push_back(u);
              std::reverse(ans.begin(), ans.end());
              for (int u = i, v = out.back(), i = 0; i < m; ++i, std::swap(u, v)) ans.push_back(v);
              print(ans), check = 1; break;
            }
          }
        }
      }
    }
  }
  return 0;
}