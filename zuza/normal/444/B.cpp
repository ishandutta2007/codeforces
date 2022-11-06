#include <cassert>
#include <cstring>

#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

typedef long long llint;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

int main(void)
{
  int n, d; scanf("%d %d", &n, &d);
  llint x; scanf("%lld", &x);

  auto getNextX = [&]() {
    x = (x * 37LL + 10007) % 1000000007;
    return x;
  };

  const int MAXN = 1e5 + 123;
  static int a[MAXN]; // perm
  static int b[MAXN]; // ones

  auto initAB = [&]() {
    for(int i = 0; i < n; i = i + 1){
      a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
  }; initAB();

  vector<int> b_ones;
  REP(i, n) if (b[i] == 1) b_ones.push_back(i);

  static int a_v2i[MAXN];
  REP(i, n) a_v2i[ a[i] ] = i;

  const int BUBEN = 180;

  REP(si, n) {
    int ans = 0;

    for (int t = n; t > 0 && t > n-BUBEN; --t) {
      int pos = si - a_v2i[t];
      if (pos >= 0 && b[pos] == 1) { ans = t; break; }
    }

    if (ans == 0) {
      for (int op : b_ones) {
        if (si-op < 0) break;
        ans = max(ans, a[si-op]);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}