#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 150000 + 10;
int a[MAXN], n;

set<PII> ret;

void add(int x, int y) {
  if (x > y) swap(x, y);
  ret.insert(PII(x, y));
}

void solve(int s) {
  if (s < 1 || s > n) return;
  int odd(0), even(0);
  for (int i = 1; i < n; ++i) {
    if (i & 1) {
      odd += a[i] < a[i + 1];
    } else {
      even += a[i] > a[i + 1];
    }
  }
  for (int i = 1; i <= n; ++i) if (i != s) {
    int x = s, y = i;
    set<int> cg;
    cg.insert(x); cg.insert(x - 1); cg.insert(x + 1);
    cg.insert(y); cg.insert(y - 1); cg.insert(y + 1);
    for (auto &v : cg) if (v >= 1 && v < n) {
      if (v & 1) odd -= a[v] < a[v + 1];
      else even -= a[v] > a[v + 1];
    }
    swap(a[x], a[y]);
    for (auto &v : cg) if (v >= 1 && v < n) {
      if (v & 1) odd += a[v] < a[v + 1];
      else even += a[v] > a[v + 1];
    }
    if (odd + even == n - 1) add(x, y);
    for (auto &v : cg) if (v >= 1 && v < n) {
      if (v & 1) odd -= a[v] < a[v + 1];
      else even -= a[v] > a[v + 1];
    }
    swap(a[x], a[y]);
    for (auto &v : cg) if (v >= 1 && v < n) {
      if (v & 1) odd += a[v] < a[v + 1];
      else even += a[v] > a[v + 1];
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  vector<int> x;
  for (int i = 1; i < n; ++i) {
    if (i & 1) {
      if (a[i] >= a[i + 1]) x.push_back(i);
    } else {
      if (a[i] <= a[i + 1]) x.push_back(i);
    }
  }
  if (x.size() >= 5) puts("0");
  else {
    for (auto &i : x) {
      solve(i);
      solve(i + 1);
      solve(i - 1);
    }
    printf("%d\n", (int)ret.size());
  }
  return 0;
}