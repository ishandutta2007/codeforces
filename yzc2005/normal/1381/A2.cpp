#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T, n, g[N];
char s[N], t[N];
vector<int> ans;
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%s%s", &n, s + 1, t + 1);
    for (int i = 1, l = 0, r = n + 1; i <= n; i += 2)
      g[i] = ++l, g[i + 1] = --r;
    ans.clear();
    for (int i = 1; i <= n; ++i) 
      s[i] -= '0', t[i] -= '0';
    for (int i = n; i; --i) {
      if ((s[g[n - i + 1]] ^ ((n - i) & 1)) == t[i]) ans.push_back(1);
      ans.push_back(i);
    }
    printf("%d ", ans.size());
    for (auto v : ans) printf("%d ", v);
    puts("");
  }
  return 0;
}