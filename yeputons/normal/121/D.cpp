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

int n; ll k;
vector<pair<ll, ll> > segs;
vll segsr;
vll nums;

bool can(int ans) {
  ll minl = 9e18;
  for (int i = 0; i < n; i++)
    minl = min(minl, segs[i].second - segs[i].first + 1);

  vector<ll> rsums(sz(nums) - ans + 1, k + 1);
  {
    int p = n - 1;
    ll rsum = 0, rcnt = 0;
    ll ox = -1;
    for (int i = sz(nums) - ans; i >= 0; i--) {
      ll x = nums[i];

      // Recalc rsum
      if (ox >= 0) {
        if (rcnt)
          if ((ox - x) > k / rcnt + 3) break;
        rsum += (ox - x) * rcnt;
      }
      if (rsum > k) break;

      while (p >= 0 && segs[p].first >= x) {
        rsum += segs[p].first - x;
        if (rsum > k) break;
        rcnt++;
        p--;
      }
      ox = x;

      if (rsum > k) break;
      rsums[i] = rsum;
    }
  }

  vector<ll> lsums(sz(nums) - ans + 1, k + 1);
  {
    int pl = 0;
    ll lsum = 0, lcnt = 0;
    ll oxl = -1;
    for (int i = 0; i + ans <= sz(nums); i++) {
      ll xl = nums[i + ans - 1];

      if (oxl >= 0) {
        if (lcnt)
          if ((xl - oxl) > k / lcnt + 3) break;
        lsum += (xl - oxl) * lcnt;
      }
      if (lsum > k) break;

      while (pl < n && segsr[pl] < xl) {
        lsum += xl - segsr[pl];
        if (lsum > k) break;
        lcnt++;
        pl++;
      }
      oxl = xl;

      if (lsum > k) break;
      lsums[i] = lsum;
    }
  }

  for (int i = sz(nums) - ans; i >= 0; i--) {
    ll x = nums[i], xl = nums[i + ans - 1];
    if (xl - x + 1 > minl) continue;
    ll csum = rsums[i] + lsums[i];
    if (csum <= k) 
      return true;
  }
  return false;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  nums.clear();
  for (int l = 1; l <= 18; l++) {
    for (int m = 0; m < (1 << l); m++) {
      ll x = 0;
      for (int i = 0; i < l; i++)
        x = x * 10 + ((m & (1 << i)) ? 7 : 4);
      nums.pb(x);
    }
  }
  sort(nums.begin(), nums.end());

  while (scanf("%d%I64d", &n, &k) >= 2) {
    segs.resize(n);
    segsr.resize(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d%I64d", &segs[i].first, &segs[i].second), segsr[i] = segs[i].second;
    sort(segs.begin(), segs.end());
    sort(segsr.begin(), segsr.end());

    int L = 0, R = sz(nums) + 1;
    while (L + 1 < R) {
      eprintf("%d\n", R - L);
      int M = (L + R) / 2;
      if (can(M)) L = M;
      else R = M;
    }
    printf("%d\n", L);
  }
  return 0;
}