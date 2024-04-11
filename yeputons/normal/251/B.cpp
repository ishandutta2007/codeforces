#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#ifdef DEBUG
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

vi op(vi as, vi bs) {
  vi res(sz(as));
  for (int i = 0; i < sz(as); i++)
    res[i] = as[bs[i]];
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi as(n), bs(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]), as[i]--;
    for (int i = 0; i < n; i++)
      scanf("%d", &bs[i]), bs[i]--;

    vi start(n);
    for (int i = 0; i < n; i++) start[i] = i;
    vi ras(n);
    for (int i = 0; i < n; i++)
      ras[as[i]] = i;

    int mod = 0;
    {
      vi cur = start;
      while (mod < 500) {
        mod++;
        cur = op(cur, as);
        if (cur == start) break;
      }
    }
    int p = 500;
    if (p >= 500) {
      vi cur = start;
      p = 0;
      while (cur != bs && p < 500) {
        p++;
        cur = op(cur, as);
      }
    }
    if (p >= 500) {
      vi cur = start;
      p = 0;
      while (cur != bs && p > -500) {
        p--;
        cur = op(cur, ras);
      }
    }
    if (p <= -500 || p == 0 || p >= 500) printf("NO\n");
    else if (mod >= 500) {
      if ((p & 1) != (k & 1) || abs(p) > k)
        printf("NO\n");
      else
        printf("YES\n");
    } else {
      assert(mod > 1);
      assert(abs(p) < mod);
      if (p < 0) p += mod;

      if (mod == 2) {
        printf(k == 1 ? "YES\n" : "NO\n");
      } else {
        bool g = false;
        if (p <= k && p % 2 == k % 2) g = true;
        if (mod - p <= k && (mod - p) % 2 == k % 2) g = true;
        printf(g ? "YES\n" : "NO\n");
      }
    }
  }
  return 0;
}