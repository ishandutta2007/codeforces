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

const int MAXN = 15;
const int MAXL = 10;

const int MAXK = 500000;
int ts[MAXK];
int nes[MAXK + 1][MAXN];

int n;
int maxa = n * (n - 1) / 2;
int calc(int k) {
  for (int i = 0; i < n; i++)
    nes[k][i] = k;

  for (int i = k - 1; i >= 0; i--) {
    memcpy(nes[i], nes[i + 1], sizeof nes[i]);
    nes[i][ts[i]] = i;
  }

  vvi dyn(1 << n, vi(maxa + 1, k));
  dyn[0][0] = 0;
  for (int msk = 0; msk < (1 << n); msk++)
  for (int cans = 0; cans <= maxa; cans++) if (dyn[msk][cans] < k) {
    int cpos = dyn[msk][cans];

    int nans = cans;
    for (int ne = n - 1; ne >= 0; ne--) if (!(msk & (1 << ne))) {
      int nmsk = msk | (1 << ne);
      dyn[nmsk][nans] = min(dyn[nmsk][nans], nes[cpos][ne]);
    } else
      nans++;
  }
  int rmsk = (1 << n) - 1;
  for (int i = 0; i <= maxa; i++)
    if (dyn[rmsk][i] < k) return i;
  return maxa + 1;
}

char buf[MAXL + 1];
char src[MAXN][MAXL + 1];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    for (int i = 0; i < n; i++)
      scanf("%s", src[i]);
    maxa = n * (n - 1) / 2;

    int m;
    scanf("%d", &m);

    pii ans(maxa + 1, -1);
    for (int id = 0; id < m; id++) {
      int k;
      scanf("%d", &k);
      int rk = 0;
      for (int i = 0; i < k; i++) {
        scanf("%s", buf);
        int sid = -1;
        for (int i2 = 0; i2 < n; i2++)
          if (!strcmp(buf, src[i2])) sid = i2;
        if (sid >= 0) {
          ts[rk++] = sid;
        }
      }

      int cur = calc(rk);
      ans = min(ans, mp(cur, id));
    }
    if (ans.second < 0) printf("Brand new problem!\n");
    else {
      printf("%d\n", ans.second + 1);
      int out = maxa - ans.first + 1;
      printf("[:");
      for (int i = 0; i < out; i++)
        printf("|");
      printf(":]\n");
    }
  }
  return 0;
}