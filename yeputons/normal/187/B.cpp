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

const int INF = 1e9;

const int MAXN = 60;
const int MAXM = 60;

int as[MAXM][MAXN][MAXN];
int as2[MAXN][MAXN];
int dyn[MAXN][MAXN + 1][MAXN];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, m, r;
  while (scanf("%d%d%d", &n, &m, &r) >= 3) {
    for (int i = 0; i < m; i++) {
      for (int a = 0; a < n; a++)
      for (int b = 0; b < n; b++)
        scanf("%d", &as[i][a][b]);
 
      for (int a = 0; a < n; a++)
      for (int b = 0; b < n; b++)
      for (int c = 0; c < n; c++)
        as[i][b][c] = min(as[i][b][c], as[i][b][a] + as[i][a][c]);
    }

    memset(as2, 0x3F, sizeof as2);
    for (int a = 0; a < n; a++)
    for (int b = 0; b < n; b++)
    for (int t = 0; t < m; t++)
      as2[a][b] = min(as2[a][b], as[t][a][b]);

    memset(dyn, 0x3F, sizeof dyn);
    for (int en = 0; en < n; en++) {
      #define cd dyn[en]
      for (int i = 0; i < n; i++)
        cd[0][i] = min(cd[0][i], as2[i][en]);

      for (int maxl = 1; maxl <= n; maxl++) {
        for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
          cd[maxl][a] = min(cd[maxl][a], as2[a][b] + cd[maxl - 1][b]);
      }
      #undef cd
    }

    for (int i = 0; i < r; i++) {
      int a, b, k;
      scanf("%d%d%d", &a, &b, &k), a--, b--;
      k = min(k, n);
      printf("%d\n", dyn[b][k][a]);
    }
  }
  return 0;
}