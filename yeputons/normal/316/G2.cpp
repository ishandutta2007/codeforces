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

const int MAXL = 2002;
const int MAXN = 12;

char s[MAXL + 1];
char ps[MAXN][MAXL + 1];
int pls[MAXN];
int lcs[MAXN], rcs[MAXN];

int lcps[MAXN][MAXL + 1][MAXL + 1];

int slcp[MAXL + 1][MAXL + 1];

bool sufcmp(int a, int b) {
  int off = slcp[a][b];
  a += off; b += off;
  return s[a] < s[b];
}

int ptrs[MAXN][MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int n;
  while (scanf("%s%d", s, &n) >= 1) {
    int l = strlen(s);
    for (int i = 0; i < n; i++) {
      scanf("%s%d%d", ps[i], &lcs[i], &rcs[i]);
      pls[i] = strlen(ps[i]);

      int m = pls[i];
      for (int a = 0; a <= l; a++)
        lcps[i][a][m] = 0;
      for (int b = 0; b <= m; b++)
        lcps[i][l][b] = 0;

      for (int a = l - 1; a >= 0; a--)
        for (int b = m - 1; b >= 0; b--) {
          if (s[a] == ps[i][b])
            lcps[i][a][b] = lcps[i][a + 1][b + 1] + 1;
          else
            lcps[i][a][b] = 0;
        }
      for (int a = 0; a <= l; a++)
        sort(lcps[i][a], lcps[i][a] + m + 1);
    }

    memset(slcp, 0, sizeof slcp);
    for (int a = l - 1; a >= 0; a--)
    for (int b = l - 1; b >= 0; b--)
      if (s[a] == s[b])
        slcp[a][b] = slcp[a + 1][b + 1] + 1;

    memset(ptrs, 0, sizeof ptrs);

    int ans = 0;
    for (int len = 1; len <= l; len++) {
      static vi all;
      all.clear();
      for (int st = 0; st + len <= l; st++) {
        bool g = true;
        for (int i = 0; i < n; i++) {
          int m = pls[i];
          while (ptrs[i][st] <= m && lcps[i][st][ptrs[i][st]] < len)
            ptrs[i][st]++;
//          assert(ptrs[i][st] == lower_bound(lcps[i][st], lcps[i][st] + m + 1, len) - lcps[i][st]);
          int mycnt = m + 1 - ptrs[i][st];
          g = g && lcs[i] <= mycnt && mycnt <= rcs[i];
        }
        if (g)
          all.pb(st);
      }
      sort(all.begin(), all.end(), sufcmp);

      for (int i = 0; i < sz(all); i++)
        if (i == 0 || slcp[all[i - 1]][all[i]] < len)
          ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}