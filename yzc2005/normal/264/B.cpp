#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, M = 333;
int n, mx[N];
struct bit {
  int mx[N];
  void modify(int p, int v) {
    while (p < N) {
      mx[p] = max(mx[p], v);
      p += p & -p;
    }
  }
  int query(int p) {
    int res = 0;
    while (p) {
      res = max(res, mx[p]);
      p -= p & -p;
    }
    return res;
  } 
} b[M];
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    int x = a;
    int cur = 0;
    for (int j = 2; j < M; ++j) {
      if (x % j == 0) {
        cur = max(cur, b[j].query(a - 1));
        while (x % j == 0) {
          x /= j;
        }
      }
    }
    if (x > 1) {
      for (int j = x; j < a; j += x) {
        cur = max(cur, mx[j]);
      }
    }
    ++cur;
    x = a;
    for (int j = 2; j < M; ++j) {
      if (x % j == 0) {
        b[j].modify(a, cur);
        while (x % j == 0) {
          x /= j;
        }
      }
    }
    mx[a] = max(mx[a], cur);
  }
  int ans = *std::max_element(mx + 1, mx + N);
  for (int i = 1; i < M; ++i) {
    ans = max(ans, b[i].query(N - 1));
  }
  printf("%d\n", ans);
  return 0;
}