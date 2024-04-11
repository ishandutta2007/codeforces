#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N], s1[N], t1, s2[N], t2;
vector<int> ans1[N], ans2[N];
bool tag[N];
inline void down(int &x, const int y) {x > y ? x = y : 0;}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  set<int> cand; int mp[2] = {n, n};
  for (int i = n; i; --i) {
    if (i < n && a[i] != a[i + 1]) {
      bool t = a[i] > a[i + 1];
      if (mp[t ^ 1] < n) ans1[i] = {i, mp[t ^ 1], mp[t ^ 1] + 1};
      mp[t] = i;
    }
    while (t1 && a[s1[t1]] > a[i]) {
      if (tag[s1[t1]]) cand.emplace(s1[t1]);
      tag[s1[t1--]] = true;
    }
    while (t2 && a[s2[t2]] < a[i]) {
      if (tag[s2[t2]]) cand.emplace(s2[t2]);
      tag[s2[t2--]] = true;
    }
    int _t1 = t1, _t2 = t2, l, r;
    for (l = 1, r = t1, t1 = 0; l <= r; ) {
      int mid = l + r >> 1;
      if (a[s1[mid]] != a[i]) t1 = mid, l = mid + 1;
      else r = mid - 1; 
    }
    for (l = 1, r = t2, t2 = 0; l <= r; ) {
      int mid = l + r >> 1;
      if (a[s2[mid]] != a[i]) t2 = mid, l = mid + 1;
      else r = mid - 1;
    }
    if (t1 && t2) {
      int pos = max(s1[t1], s2[t2]);
      auto nxt = cand.upper_bound(pos);
      if (nxt != cand.end()) {
        int p1, p2, l, r, rr = *nxt;
        for (l = 1, r = t1; l <= r; ) {
          int mid = l + r >> 1;
          if (s1[mid] < rr) p1 = s1[mid], r = mid - 1;
          else l = mid + 1;
        }
        for (l = 1, r = t2; l <= r; ) {
          int mid = l + r >> 1;
          if (s2[mid] < rr) p2 = s2[mid], r = mid - 1;
          else l = mid + 1;
        }
        if (p1 > p2) swap(p1, p2);
        ans2[i] = {i, p1, p2, rr};
      }
    }
    s1[t1 = _t1 + 1] = i, s2[t2 = _t2 + 1] = i;
  }
  for (int i = n; i; --i) {
    if (!ans1[i + 1].empty() && (ans1[i].empty() || ans1[i + 1].back() < ans1[i].back())) ans1[i] = ans1[i + 1];
    if (!ans2[i + 1].empty() && (ans2[i].empty() || ans2[i + 1].back() < ans2[i].back())) ans2[i] = ans2[i + 1];
  }
  for (int t = 0, l, r; t < q; ++t) {
    scanf("%d%d", &l, &r);
    if (!ans2[l].empty() && ans2[l].back() <= r) {
      puts("4");
      for (auto x : ans2[l]) printf("%d ", x);
      puts("");
    } else if (!ans1[l].empty() && ans1[l].back() <= r) {
      puts("3");
      for (auto x : ans1[l]) printf("%d ", x);
      puts("");
    } else puts("0"), puts("");
  } 
  return 0;
}