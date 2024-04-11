#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define pb push_back
#define mp make_pair
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())
#define TASKNAME "std"

typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int main() {
  #ifdef DEBUG
  freopen(TASKNAME ".in", "r", stdin);
  freopen(TASKNAME ".out", "w", stdout);
  #endif
  
  int n, k;
  ll b;
  while (scanf("%d%d%I64d", &n, &k, &b) >= 1) {
    vll as(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d", &as[i]);
      
    int ans = n - 1;
    multiset<ll, greater<ll> > rs; ll rsum = 0;
    for (int i = n - 2; i >= 0; i--) {
      if (rsum + as[i] > b)
        ans = min(ans, i);

      rs.insert(as[i]); rsum += as[i];
      if (sz(rs) >= k) {
        rsum -= *--rs.end();
        rs.erase(--rs.end());
      }
    }
    printf("%d\n", ans + 1);
  }
  return 0;
}