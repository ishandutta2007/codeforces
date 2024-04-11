#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T, n;
char s[N], t[N];
vector<int> ans;
int main() {
  for (scanf("%d", &T); T; --T) {
    scanf("%d%s%s", &n, s + 1, t + 1);
    ans.clear();
    for (int i = 1; i <= n; ++i) s[i] -= '0', t[i] -= '0';
    for (int i = n; i; --i) {
      if (s[i] == t[i]) continue;
      else {
        if (s[1] == t[i]) s[1] ^= 1, ans.push_back(1);
        ans.push_back(i), reverse(s + 1, s + i + 1);
        for (int j = 1; j <= i; ++j) s[j] ^= 1;
      }
    }
    printf("%d ", ans.size());
    for (auto v : ans) printf("%d ", v);
    puts("");
  }
  return 0;
}