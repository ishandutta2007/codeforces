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

int count_nums(const vll &a, int l, int r) {
  int res = 0;
  for (int i = 0; i < sz(a); i++)
    if (l <= a[i] && a[i] <= r) res++;
  return res;
}

vi get_perm(int n, int k) {
//  eprintf("n=%d, k=%d\n", n, k);
  vi res(n, -1);
  vb was(n, false);

  for (int i = 0; i < n; i++) {
    int ccnt = 1;
    for (int i2 = 1; i2 < n - i; i2++)
      ccnt *= i2;

    for (int val = 0;; val++) {
      if (val >= n) throw 0;
      if (!was[val]) {
        if (k < ccnt) {
          res[i] = val;
          was[val] = true;
//          eprintf("%dth: %d\n", i, val);
          break;
        } else
          k -= ccnt;
      }
    }
  }
  return res;
}

const int MAXN = 15;

vll nums;
inline bool lucky(ll x) {
  return binary_search(nums.begin(), nums.end(), x);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  nums.clear();
  for (int l = 1; l <= 10; l++) {
    for (int m = 0; m < (1 << l); m++) {
      ll x = 0;
      for (int i = 0; i < l; i++)
        x = x * 10 + ((m & (1 << i)) ? 7 : 4);
      nums.pb(x);
    }
  }
  nums.pb(0);
  sort(nums.begin(), nums.end());

  int n1, k;
  while (scanf("%d%d", &n1, &k) >= 2) {
    k--;
    int n = min(MAXN, n1);

    int res = 0;
    int st = n1 - n + 1;
    res += count_nums(nums, 1, st - 1);

    try {
      vi perm = get_perm(n, k);
      for (int i = 0; i < n; i++) {
        int cpos = st + i;
        int cval = perm[i] + st;
        if (lucky(cpos) && lucky(cval))
          res++;
      }
      printf("%d\n", res);
    } catch (...) {
      printf("-1\n");
    }
  }
  return 0;
}