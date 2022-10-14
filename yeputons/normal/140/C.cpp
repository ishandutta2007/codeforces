#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

struct Ans { int a, b, c; Ans() {} Ans(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {} };

bool check(const map<int, int> &cnts, int maxc) {
  int res = 0;
  for (map<int, int>::const_iterator it = cnts.begin(); it != cnts.end(); it++)
    res += min(maxc, it->second);
  return maxc * 3 <= res;
}
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    map<int, int> cnts;
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      cnts[x]++;
    }
    int L = 0, R = n + 1;
    while (L + 1 < R) {
      int M = (L + R) / 2;
      if (check(cnts, M)) L = M;
      else R = M;
    }
    int ans = L;

    vi as;
    for (map<int, int>::iterator it = cnts.begin(); it != cnts.end(); it++)
      for (int i = 0; i < it->second && i < ans; i++)
        as.pb(it->first);

    vvi res(ans, vi(3, -1));
    int x = 0, y = 0;
    for (int i = 0; i < sz(as) && x < 3; i++) {
      res[y][x] = as[i];
      if (++y >= ans) { x++; y = 0; }
    }

    printf("%d\n", sz(res));
    for (int i = 0; i < sz(res); i++) {
      assert(unique(res[i].begin(), res[i].end()) == res[i].end());
      printf("%d %d %d\n", res[i][2], res[i][1], res[i][0]);
    }
  }
  return 0;
}