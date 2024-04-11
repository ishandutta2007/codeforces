#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int w, h;
  while (scanf("%d%d", &h, &w) >= 1) {
    int ans = 1;
    if (w == 1 || h == 1) {
      ans = max(ans, w * h);
    } else if (w == 2 || h == 2) {
      int x = max(w, h);
      int cnt = x / 4, rem = x % 4;
      int cans = cnt * 4 + min(rem, 2) * 2;
      ans = max(ans, cans);
    } else {
      ans = max(ans, (w * h + 1) / 2);
    }
    printf("%d\n", ans);
  }
  return 0;
}