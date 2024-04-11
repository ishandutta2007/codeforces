#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

const int MOD = 1e9;
void madd(int &a, int b) { if ((a += b) >= MOD) a -= MOD; }
int mmul(int a, int b) { return ll(a) * b % MOD; }

const int MAXN = 2e5 + 1000;
int ks[MAXN];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  ks[0] = ks[1] = 1;
  for (int i = 2; i < MAXN; i++) {
    ks[i] = ks[i - 1];
    madd(ks[i], ks[i - 2]);
  }

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    while (m --> 0) {
      int t;
      scanf("%d", &t);
      if (t == 1) {
        int x, v;
        scanf("%d%d", &x, &v), x--;
        as[x] = v;
      } else if (t == 2) {
        int l, r;
        scanf("%d%d", &l, &r), l--, r--;

        int val = 0;
        for (int i = l; i <= r; i++)
          madd(val, mmul(as[i], ks[i - l]));
        printf("%d\n", val);
      } else if (t == 3) {
        int l, r, d;
        scanf("%d%d%d", &l, &r, &d), l--, r--;
        for (int i = l; i <= r; i++)
          madd(as[i], d);
      }
    }
  }
  return 0;
}