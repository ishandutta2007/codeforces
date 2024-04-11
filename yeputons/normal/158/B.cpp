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

  int n;
  while (scanf("%d", &n) >= 1) {
    vi c(5);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      assert(1 <= x && x <= 4);
      c[x]++;
    }

    int ans = 0;
    ans += c[4]; c[4] = 0;
    {
      int tmp = min(c[1], c[3]);
      c[1] -= tmp; c[3] -= tmp;
      ans += tmp;
    }
    ans += c[3]; c[3] = 0;

    {
      int tmp = (c[1] + 1) / 2 + c[2];
      ans += (tmp + 1) / 2;
    }
    printf("%d\n", ans);
  }
  return 0;
}