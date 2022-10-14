#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cstdarg>
#include <cassert>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef vector<ll> vll;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

typedef long double ld;
#define EPS 1e-9

ll getCount(ll l, ll r) {
  if (l > r) return 0;
  return r - l + 1;
}

ld getProb(ll l, ll r) {
  ll off = 1;
  ll cnt = 0;
  for (int len = 1; off <= r && off >= 0; len++, off *= 10) {
    cnt += getCount(max(l, off), min(r, 2 * off - 1));
  }
  return (ld)cnt / (r - l + 1);
}

int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vll l(n), r(n);
    for (int i = 0; i < n; i++)
      scanf("%I64d%I64d", &l[i], &r[i]);
    int k; scanf("%d", &k);

    vector<vector<ld> > d(n + 1, vector<ld>(n + 1, 0));
    d[0][0] = 1;
    for (int i = 0; i < n; i++) {
      for (int c = 0; c < n; c++) {
        ld prob = getProb(l[i], r[i]);
        eprintf("prob=%.10lf\n", (double)prob);
        d[i + 1][c] += d[i][c] * (1 - prob);
        d[i + 1][c + 1] += d[i][c] * prob;
      }
    }
    ld ans = 0;
    for (int i = 0; i <= n; i++) if (i * 100.0 / n >= k - EPS) {
      ans += d[n][i];
    }
    printf("%.30lf\n", (double)ans);
    
    #ifndef DEBUG
    #warning No multitest!!!
    break;
    #endif
  }
  return 0;
}