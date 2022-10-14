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
typedef pair<double, double> pdd;

const int MAXL = 1e6;

pdd operator*(const pdd &a, int b) { return mp(a.first * b, a.second * b); }
pdd operator+(const pdd &a, const pdd &b) { return mp(a.first + b.first, a.second + b.second); }

int divide(int a, int b) {
  if (b < 0) { a = -a; b = -b; }
  if (a < 0) return 0;
  // x >= a / b
  int c = a / b;
  if (c * b < a) c++;
  return c;
}

bool check(const vvi &m, int x, vi &vals) {
  vals = vi(8);
  vals[7] = 1;
  vals[6] = x;
  for (int y = 5; y >= 0; y--) {
    int cv = 0;
    for (int x = y + 1; x < sz(m[y]); x++)
      cv -= m[y][x] * vals[x];
    assert(m[y][y]);
    if (cv % m[y][y]) return false;
    vals[y] = cv / m[y][y];
  }
  for (int i = 0; i <= 7; i++)
    if (vals[i] < 0) return false;
  return true;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int hs[4][4];
  while (scanf("%d", &hs[0][1]) >= 1) {
    int ids[4][4];
    memset(ids, -1, sizeof ids);

    vvi m(7, vi(8, 0));
    int cid = 0;

    for (int a = 0; a < 4; a++)
    for (int b = a + 1; b < 4; b++) {
      if (a != 0 || b != 1)
        scanf("%d", &hs[a][b]);
      ids[a][b] = cid;
      m[cid][7] = -hs[a][b];
      cid++;
    }

    for (int msk = 1; msk < 8; msk++) {
      int ss[4] = { 0 };
      for (int i = 0; i < 3; i++) ss[i + 1] = !!(msk & (1 << i));

      for (int a = 0; a < 4; a++)
      for (int b = a + 1; b < 4; b++) if (ss[a] != ss[b]) {
        m[ids[a][b]][msk - 1] = 1;
      }
    }
/*    for (int y = 0; y < 7; y++)
    for (int x = 0; x < 8; x++)
      eprintf("%2d%c", m[y][x], "\n "[x < 7]);
    eprintf("\n");*/
    for (int y = 0; y < 7; y++) {
      for (int y2 = y; y2 < 7; y2++) if (m[y2][y]) {
        if (y != y2)
          m[y].swap(m[y2]);
        break;
      }
      if (!m[y][y]) continue;
      for (int y2 = y + 1; y2 < 7; y2++) if (m[y2][y]) {
        assert(-m[y2][y] % m[y][y] == 0);
        int k = -m[y2][y] / m[y][y];
        for (int x = 0; x < sz(m[y2]); x++)
          m[y2][x] += k * m[y][x];
      }
    }
/*    for (int y = 0; y < 7; y++)
    for (int x = 0; x < 8; x++)
      eprintf("%2d%c", m[y][x], "\n "[x < 7]);*/

    vector<pdd> ks(8);
    ks[6] = mp(1, 0);
    ks[7] = mp(0, 1);

    for (int y = 5; y >= 0; y--) {
      pdd cur(0, 0);
      for (int x = y + 1; x < sz(m[y]); x++)
        cur = cur + (ks[x] * -m[y][x]);

      int ck = m[y][y];
      ks[y] = mp(cur.first / ck, cur.second / ck);
    }

    double minx = 0;
    for (int i = 0; i < 7; i++) {
      assert(fabs(ks[i].first) > 1e-8);
      if (ks[i].first > 0) {
        minx = max(minx, -ks[i].second / ks[i].first);
      }
    }

    eprintf("minx=%.2lf\n", minx);
    int x = max(0, (int)minx - 100);
    for (int i = 0; i < 200; i++, x++) {
      vi vals;
      if (check(m, x, vals)) {
        string s[4] = { "" };

        for (int m = 1; m < 8; m++) {
          int cnt = vals[m - 1];
          for (int i = 0; i < cnt; i++) {
            s[0] += "a";
            for (int i2 = 0; i2 < 3; i2++)
              s[i2 + 1] += string(1, 'a' + !!(m & (1 << i2)));
          }
        }
        printf("%d\n", s[0].length());
        for (int i = 0; i < 4; i++)
          printf("%s\n", s[i].c_str());
        goto end;
      } else
        eprintf("skip\n");
    }
    printf("-1\n");
    end:;
  }
  return 0;
}