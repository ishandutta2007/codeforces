#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<pair<int, int>> ans;
int n, a[N], p[N];
stack<int> s1, s2;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  } 
  int cur = n + 1;
  for (int i = n; i; --i) {
    if (a[i]) {
      if (a[i] == 1) {
        ans.push_back({p[i] = --cur, i});
        s1.push(i);
      } else if (a[i] == 2) {
        if (s1.empty()) {
          puts("-1");
          exit(0);
        } else {
          ans.push_back({p[i] = p[s1.top()], i});
          s1.pop();
          s2.push(i);
        }
      } else if (a[i] == 3) {
        if (!s2.empty()) {
          p[i] = --cur;
          ans.push_back({p[i], i});
          ans.push_back({p[i], s2.top()});
          s2.pop();
          s2.push(i);
        } else if (!s1.empty()) {
          ans.push_back({p[i] = --cur, i});
          ans.push_back({p[i], s1.top()});
          s1.pop();
          s2.push(i);
        } else {
          puts("-1");
          exit(0);
        }
      }
    }
  }
  printf("%d\n", ans.size());
  for (auto p : ans) {
    printf("%d %d\n", p.first, p.second);
  }
  return 0;
}