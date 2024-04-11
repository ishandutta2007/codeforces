#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, a, b;
  while (scanf("%d%d%d", &n, &a, &b) >= 1) {
    vector<pii> vals(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &vals[i].first), vals[i].second = i;

    vi res(n, -1);
    // s1 * b + s2 * a --> max

    if (a > b) {
      sort(vals.begin(), vals.end());
      res = vi(n, 0);
      for (int i = n - 1; i >= n - b; i--)
        res[vals[i].second] = 1;
    } else if (a < b) {
      for (int i = 0; i < n; i++)
        vals[i].second = -vals[i].second;
      sort(vals.begin(), vals.end());

      res = vi(n, 1);
      for (int i = n - 1; i >= n - a; i--)
        res[-vals[i].second] = 0;
    } else {
      res = vi(n, 0);
      for (int i = n - 1; i >= n - b; i--)
        res[i] = 1;
    }

    for (int i = 0; i < n; i++)
      printf("%d%c", res[i] + 1, "\n "[i + 1 < n]);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}