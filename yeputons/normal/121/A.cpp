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

  vll nums;
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

  int l, r;
  while (scanf("%d%d", &l, &r) >= 1) {
    ll res = 0;
    for (int i = 1; i < sz(nums); i++) {
      ll cl = max(ll(l), nums[i - 1] + 1);
      ll cr = min(ll(r), nums[i]);
      if (cl <= cr) {
//        eprintf("%I64d..%I64d %I64d\n", cl, cr, nums[i]);
        res += (cr - cl + 1) * nums[i];
      }
    }
    printf("%I64d\n", res);
  }
  return 0;
}