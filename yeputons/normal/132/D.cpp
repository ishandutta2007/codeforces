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

const int MAXL = 1e6 + 10;
char s[MAXL + 1];

const int INF = 1e9;

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%s", s) >= 1) {
    int n = strlen(s);
    reverse(s, s + n);
    s[n] = '0';
    s[n + 1] = 0;

    vvi d(n + 2, vi(2, INF));
    vvi fr(n + 2, vi(2, -1));

    d[0][0] = 0;
    for (int i = 0; i <= n; i++)
    for (int c = 0; c < 2; c++)
    for (int cur = -1; cur <= 1; cur++) {
      int nv = (-c + cur) & 1;
      if (nv != s[i] - '0') continue;

      int nc = (cur == -1) || (c && cur == 0);
      if (d[i + 1][nc] > d[i][c] + !!cur) {
        d[i + 1][nc] = d[i][c] + !!cur;
        fr[i + 1][nc] = cur;
      }
    }
    printf("%d\n", d[n + 1][0]);

    int x = 0;

    int pos = n + 1, c = 0;
    while (pos > 0) {
      int cur = fr[pos][c];
      if (cur) {
        printf("%c2^%d\n", "-+"[cur == 1], pos - 1);
        x += cur * (1 << (pos - 1));
      }

      // s[i] - '0' == -pc + cur
      // pc == cur - (s[i] - '0')
      int pc = (cur - (s[pos - 1] - '0')) & 1;
      pos--;
      c = pc;
    }

    #ifdef DEBUG
    int nx = 0;
    for (int i = 0; i < n; i++)
      nx += (s[i] - '0') * (1 << i);
    assert(x == nx);
    #endif
    assert(!c);
  }
  return 0;
}