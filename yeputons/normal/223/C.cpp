#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
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

const int MOD = 1e9 + 7;
void madd(int &a, int b) { a += b; if (a >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }
int mpow(int a, int b) {
  int res = 1;
  for (; b; b >>= 1, a = mmul(a, a))
    if (b & 1) res = mmul(res, a);
  return res;
}

const int MAXN = 2010;
int INVS[MAXN + 1];
int calcC(int n, int k) {
  int ans = 1;
  for (int i = n - k + 1; i <= n; i++)
    ans = mmul(ans, i);
  for (int i = 1; i <= k; i++)
    ans = mmul(ans, INVS[i]);
  return ans;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (int i = 1; i <= MAXN; i++)
    INVS[i] = mpow(i, MOD - 2);

  int n, k;
  while (scanf("%d%d", &n, &k) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    vi ans(n, 0);
    if (k == 0) {
      ans = as;
    } else {
      k--;
      for (int diff = 0; diff < n; diff++) {
        int c = calcC(k + diff, diff);
        for (int i = 0; i + diff < n; i++)
          madd(ans[i + diff], mmul(as[i], c));
      }
    }
    for (int i = 0; i < n; i++)
      printf("%d%c", ans[i], "\n "[i + 1 < n]);
  }
  return 0;
}