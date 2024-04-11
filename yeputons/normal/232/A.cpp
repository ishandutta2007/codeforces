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

int calc3(int x) { return x * (x - 1) * (x - 2) / 6; }
int calc2(int x) { return x * (x - 1) / 2; }

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    int bcomp = 0;
    while (calc3(bcomp + 1) <= n)
      bcomp++;

    int cver = bcomp;
    int ccnt = calc3(bcomp);
    vi c2s;
    while (ccnt < n) {
      int c2 = 0;
      while (ccnt + calc2(c2 + 1) <= n)
        c2++;
      cver++;
      ccnt += calc2(c2);
      c2s.pb(c2);
    }
    assert(ccnt == n);
    assert(cver <= 95);

    vvb g(cver, vb(cver, false));
    for (int i = 0; i < bcomp; i++)
    for (int j = 0; j < bcomp; j++)
      if (i != j)
        g[i][j] = true;
    for (int i = 0; i < sz(c2s); i++)
      for (int j = 0; j < c2s[i]; j++) {
        g[bcomp + i][j] =
        g[j][bcomp + i] = true;
      }

    for (int i = 0; i < cver; i++)
      assert(!g[i][i]);
    for (int i = 0; i < cver; i++)
    for (int j = 0; j < cver; j++)
      assert(g[i][j] == g[j][i]);

/*    #ifdef DEBUG
    if (n % 1000 == 0)
      eprintf("%d\n", n);
    int tmp = 0;
    for (int i = 0; i < cver; i++)
    for (int j = i + 1; j < cver; j++) if (g[i][j])
    for (int k = j + 1; k < cver; k++) if (g[i][k] && g[j][k])
      tmp++;
    assert(tmp == n);
    #endif*/
    printf("%d\n", cver);
    for (int i = 0; i < cver; i++) {
      for (int j = 0; j < cver; j++)
        printf("%d", !!g[i][j]);
      printf("\n");
    }
  }
  return 0;
}