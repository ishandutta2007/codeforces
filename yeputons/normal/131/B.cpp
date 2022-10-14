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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n;
  while (scanf("%d", &n) >= 1) {
    vi cnt(100, 0);
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      x += 10;
      cnt[x]++;
    }

    ll ans = 0;
    for (int i = -10; i <= 0; i++) {
      int i2 = -i;
      ll c1 = cnt[i + 10], c2 = cnt[i2 + 10];

      if (i == i2)
        ans += c1 * (c1 - 1) / 2;
      else
        ans += c1 * c2;
    }
    printf("%I64d\n", ans);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}