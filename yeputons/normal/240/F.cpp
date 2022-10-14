#include <cstdio>
#include <ctime>
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

class segm_tree {
  static const int MAXOFF = 1 << 17;
  static const int MAXSZ = 2 * MAXOFF;
  static const int SIGMA = 26;

  struct TTr {
    int val, toset;
  } tr[MAXSZ][SIGMA];
  int off;

  inline void norm(int i, int len) {
    for (int i2 = 0; i2 < SIGMA; i2++) {
      if (tr[i][i2].toset < 0) continue;
      if (i < off) {
        tr[2 * i][i2].toset =
        tr[2 * i + 1][i2].toset = tr[i][i2].toset;
      }
      tr[i][i2].val = len * tr[i][i2].toset;
      tr[i][i2].toset = -1;
    }
  }

  int lr, rr;
  int vid, vr;
  void _set(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    if (lr <= lt && rt <= rr) {
      for (int i2 = 0; i2 < SIGMA; i2++)
        tr[v][i2].toset = (i2 == vid) ? vr : 0;
      return;
    }
    norm(v, rt - lt + 1);
    int mt = (lt + rt) / 2;
    _set(2 * v, lt, mt);
    _set(2 * v + 1, mt + 1, rt);
    norm(2 * v, mt - lt + 1);
    norm(2 * v + 1, rt - mt);
    for (int i2 = 0; i2 < SIGMA; i2++)
      tr[v][i2].val = tr[2 * v][i2].val + tr[2 * v + 1][i2].val;
  }

  int *toout;
  void _get(int v, int lt, int rt) {
    if (rt < lr || rr < lt) return;
    norm(v, rt - lt + 1);
    if (lr <= lt && rt <= rr) {
      for (int i2 = 0; i2 < SIGMA; i2++)
        toout[i2] += tr[v][i2].val;
      return;
    }
    int mt = (lt + rt) / 2;
    _get(2 * v, lt, mt);
    _get(2 * v + 1, mt + 1, rt);
  }

  public:
  segm_tree(int n = 0, char *as = 0) {
    off = 1; while (off < n) off <<= 1;
    for (int i = 0; i < 2 * off; i++) {
      for (int i2 = 0; i2 < SIGMA; i2++) {
        tr[i][i2].val = 0;
        tr[i][i2].toset = -1;
      }
    }
    for (int i = 0; i < n; i++)
      tr[off + i][as[i] - 'a'].val = 1;
    for (int i = off - 1; i >= 1; i--)
    for (int i2 = 0; i2 < SIGMA; i2++)
      tr[i][i2].val = tr[2 * i][i2].val + tr[2 * i + 1][i2].val;
  }
  void set(int l, int r, int val) {
    assert(0 <= l && l <= r && r < off);
    assert(0 <= val && val < 26);
    lr = l; rr = r; vid = val; vr = 1;
    _set(1, 0, off - 1);
  }
  void get(int l, int r, int *out) {
    assert(0 <= l && l <= r && r < off);
    lr = l; rr = r;
    toout = out;
    memset(toout, 0, sizeof(int) * SIGMA);
    _get(1, 0, off - 1);
  }
};

const int MAXL = 1e5 + 1e3;
segm_tree tr;
char s[MAXL + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #else
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  #endif

  int n, m;
  while (scanf("%d%d%s", &n, &m, s) >= 1) {
    n = strlen(s);
    tr = segm_tree(n, s);

    while (m --> 0) {
      int l, r;
      scanf("%d%d", &l, &r), l--, r--;

      int cnts[26];
      tr.get(l, r, cnts);

      int odd = -1, ocnt = 0;
      for (int i = 0; i < 26; i++)
        if (cnts[i] & 1) odd = i, ocnt++;
      if (ocnt > 1) continue;

      if (odd >= 0) cnts[odd]--;

      int ptr = l;
      for (int i = 0; i < 26; i++) {
        int len = cnts[i] / 2;
        if (!len) continue;
        tr.set(ptr, ptr + len - 1, i);
        ptr += len;
      }
      if (odd >= 0) {
        tr.set(ptr, ptr, odd);
        ptr++;
      }
      for (int i = 25; i >= 0; i--) {
        int len = cnts[i] / 2;
        if (!len) continue;
        tr.set(ptr, ptr + len - 1, i);
        ptr += len;
      }
      assert(ptr == r + 1);
    }
    for (int i = 0; i < n; i++) {
      int cnts[26];
      tr.get(i, i, cnts);
      for (int i2 = 0; i2 < 26; i2++)
        if (cnts[i2])
          putc('a' + i2, stdout);
    }
    puts("");
  }
  eprintf("%d\n", clock());
  return 0;
}