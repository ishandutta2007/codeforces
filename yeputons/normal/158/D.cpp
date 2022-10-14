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

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vi as(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      scanf("%d", &as[i]);
      ans += as[i];
    }

    for (int cnt = 3; cnt <= n; cnt++) if (n % cnt == 0) {
      int len = n / cnt;
      vi cs(len);
      int cpos = 0;
      for (int i = 0; i < n; i++) {
        cs[cpos] += as[i];
        if (++cpos >= len) cpos = 0;
      }

      for (int i = 0; i < len; i++)
        ans = max(ans, cs[i]);
    }
    printf("%d\n", ans);
  }
  return 0;
}