#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

ll cs[101][101];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  memset(cs, 0, sizeof cs);
  for (int n = 1; n <= 40; n++) { 
    cs[n][0] = cs[n][n] = 1;
    for (int k = 1; k < n; k++)
      cs[n][k] = cs[n - 1][k - 1] + cs[n - 1][k];
  }
  
  int n, m, t;
  while (scanf("%d%d%d", &n, &m, &t) >= 1) {
    ll ans = 0;
    for (int c1 = 4; c1 < t; c1++)
      ans += cs[n][c1] * cs[m][t - c1];
    printf("%I64d\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}