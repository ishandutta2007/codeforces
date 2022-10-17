#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  x = 0;
  char ch = getchar();
  while (!isdigit(ch)) {
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = getchar();
  }
}
const int N = 1e6 + 5;
int n;
char s[N];
vector<int> v[N];
int pa[N];
int find(int x) {
  while (pa[x] && pa[pa[x]]) {
    x = pa[x] = pa[pa[x]];
  }
  return pa[x] ? pa[x] : x;
}
int main() {
  read(n);
  scanf("%s", s + 1);
  int lst[2] = {0, 0};
  for (int i = 1; i <= n; ++i) {
    int len = i;
    if (s[i] == '?') {
      len -= min(lst[0], lst[1]);
    } else if (s[i] == '0') {
      len -= lst[1];
      lst[0] = i;
    } else {
      len -= lst[0];
      lst[1] = i;
    }
    v[len].push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    int ans = 0;
    for (int cur = 0; cur + i <= n; ) {
      cur = find(cur + i);
      if (cur > n) {
        break;
      }
      ++ans;
    } 
    for (auto x : v[i]) {
      pa[x] = x + 1;
    }
    printf("%d%c", ans, " \n"[i == n]);
  }
  return 0;
}