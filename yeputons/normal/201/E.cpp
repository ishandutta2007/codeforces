#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
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

const int INF = 1e9 + 1e5;

const int MAX_CN = 50000;
vi cs[MAX_CN + 1];

int C(int n, int k) {
  if (n - k < k) return C(n, n - k);
  if (k == 0) return 1;
  if (k == 1) return n;
  if (n > MAX_CN) return INF;
  if (k >= sz(cs[n])) return INF;
  return cs[n][k];
}

int n, m;

bool check(int k) {
  int ccnt = 0;
  int creq = 0;
  for (int cdeg = 0; cdeg <= k && ccnt < n; cdeg++) {
    int nadd = min(C(k, cdeg), n - ccnt);
//    eprintf("cdeg=%d %d (%d)\n", cdeg, C(k, cdeg), nadd);
    ccnt += nadd;
    if (cdeg >= 1) {
      creq += min((ll)INF, (ll(cdeg) * nadd + k - 1) / k);
//      creq += min(nadd, C(k - 1, cdeg - 1));
    }
  }
  if (ccnt < n) return false;
  return creq <= m;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  {
    cs[0] = vi(1, 1);
    for (int n = 1; n <= MAX_CN; n++) {
      cs[n].pb(1);
      for (int k = 1; k <= n - k; k++) {
        int v1 = C(n - 1, k - 1);
        int v2 = C(n - 1, k);
        if (v1 + v2 >= INF) break;
        cs[n].pb(v1 + v2);
      }
    }
  }

  int TN;
  assert(scanf("%d", &TN) >= 1);
  while (TN --> 0) {
    scanf("%d%d", &n, &m);
    if (n == 1) printf("0\n");
    else {
      int L = 0, R = n;
      assert(check(R));
      assert(!check(L));
      while (L + 1 < R) {
        int M = (L + R) / 2;
        if (check(M)) R = M;
        else L = M;
      }
      printf("%d\n", R);
    }
  }
  return 0;
}