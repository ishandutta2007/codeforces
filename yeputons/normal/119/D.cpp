#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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
class segm_tree {
  vi tr;
  int off;

  int getGeq(int v, int maxv) {
    if (tr[v] < maxv) return INF;
    while (v < off) {
      v *= 2;
      if (tr[v] < maxv) v++;
      assert(tr[v] >= maxv);
    }
    return v - off;
  }

  public:
  segm_tree(const vi &src) {
    off = 1; while (off < sz(src)) off *= 2;
    tr = vi(off * 2, -INF);
    for (int i = 0; i < sz(src); i++)
      tr[off + i] = src[i];
    for (int i = off - 1; i >= 1; i--)
      tr[i] = max(tr[2 * i], tr[2 * i + 1]);
  }

  int getGeq(int l, int r, int maxv) {
    l = max(0, l);
    r = min(r, off - 1);

    l += off, r += off;

    int res = INF;
    while (l <= r) {
      if (l & 1) res = min(res, getGeq(l++, maxv));
      if (!(r & 1)) res = min(res, getGeq(r--, maxv));
      l >>= 1;
      r >>= 1;
    }
    return res >= INF ? -1 : res;
  }
};

string rev(const string &s) {
  int l = s.length();
  string res(l, ' ');
  for (int i = 0; i < l; i++)
    res[l - 1 - i] = s[i];
  return res;
}

void calcz(const string &s, vi &z) {
  int l = s.length();
  z = vi(l, 0);

  int r = 0, ri = 0;
  for (int i = 1; i < l; i++) {
    int k = 0;
    if (r >= i) k = min(r - i + 1, z[i - ri]);
    #ifdef DEBUG
    for (int i2 = 0; i2 < k; i2++)
      assert(s[i2] == s[i + i2]);
    #endif

    while (i + k < l && s[k] == s[i + k])
      k++;

    z[i] = k;
    if (i + k > r) {
      r = i + k - 1;
      ri = i;
    }
  }
}

void clean(char *s) {
  int l = strlen(s);
  while (l && (s[l - 1] == '\n' || s[l - 1] == '\r'))
    s[--l] = 0;
}

const int MAXL = 1e6 + 10;
char a[MAXL + 1], b[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (;;) {
    a[0] = b[0] = 0;
    fgets(a, sizeof a, stdin); clean(a);
    fgets(b, sizeof b, stdin); clean(b);
    if (!strlen(a) || !strlen(b)) break;

    int n = strlen(a);
    if (n != strlen(b)) {
      printf("-1 -1\n");
      continue;
    }

    vi z1, z2, z3;

    string tmps = a + string(1, '$') + rev(b);
    calcz(tmps, z1);

    tmps = rev(a) + string(1, '$') + b;
    calcz(tmps, z2);

    vi nz2 = z2;
    for (int i = 0; i < sz(nz2); i++)
      nz2[i] += i;

    tmps = b + string(1, '$') + a;
    calcz(tmps, z3);

    segm_tree tr(nz2);

    // c a rev(b)
    // a b rev(c)
    for (int i = n - 2; i >= 0; i--) {
      // check for c
      if (z1[n + 1] < i + 1) continue;

      // need:
      // 1)z2[n - i + j] + j >= n
      //   (nz2[n - i + j] - n + i - j) + j >= n
      //   nz2[n - i + j] - n + i >= n
      //   nz2[n - i + j] >= 2 * n - i
      // 2)z3[n + 1 + i + 1] >= j - i - 1
      //   j <= z3[n + i + 2] + i + 1
      /*for (int j = i + 1; j < n; j++) {
        if (nz2[n - i + j] < 2 * n - i) continue;
        if (j > z3[n + i + 2] + i + 1) continue;
        printf("%d %d\n", i, j);
        goto end;
      }*/
      int minj = i + 1;
      int maxj = min(n - 1, z3[n + i + 2] + i + 1);
      int ans = tr.getGeq(n - i + minj, n - i + maxj, 2 * n - i);
      if (ans >= 0) {
        ans -= n - i;
        printf("%d %d\n", i, ans);
        goto end;
      }
    }
    printf("-1 -1\n");
    end:;
  }
  return 0;
}