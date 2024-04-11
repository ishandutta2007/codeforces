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

const int MAXN = 1e5;
const int BLEN = 300;
const int BCNT = (MAXN + BLEN - 1) / BLEN;
const int MAXV = 1e4;

int lucky[10000];
int lcnt;
bool larr[MAXV + 1];

class Block {
  int cnts[MAXV + 1];
  int data[BLEN];
  int off;

  public:
  Block() { memset(cnts, 0, sizeof cnts); }
  Block(int len) {
    memset(cnts, 0, sizeof cnts);
    memset(data, 0, sizeof data);
    cnts[0] = len;
    off = 0;
  }

  void add(int x) { off += x; }
  void add(int x, int v) {
    cnts[data[x]]--;
    data[x] += v;
    cnts[data[x]]++;
  }
  int get(int i) { return data[i] + off; }
  inline int count(int x) {
    x -= off;
    if (x < 0 || x > MAXV) return 0;
    return cnts[x];
  }
  int getLucky() {
    int res = 0;
    for (int i = 0; i < lcnt; i++)
      res += count(lucky[i]);
    return res;
  }
};
int bcnt;
Block bs[BCNT];
int boff[BCNT];
int blen[BCNT];

void add(int l, int r, int x) {
  for (int i = 0; i < bcnt; i++) {
    if (l <= boff[i] && boff[i] + blen[i] - 1 <= r) {
      bs[i].add(x);
      continue;
    }
    for (int i2 = max(l, boff[i]); i2 <= min(boff[i] + blen[i] - 1, r); i2++)
      bs[i].add(i2 - boff[i], x);
  }
}
int count(int l, int r) {
  int res = 0;
  for (int i = 0; i < bcnt; i++) {
    if (l <= boff[i] && boff[i] + blen[i] - 1 <= r) {
      res += bs[i].getLucky();
      continue;
    }
    for (int i2 = max(l, boff[i]); i2 <= min(boff[i] + blen[i] - 1, r); i2++) {
      int val = bs[i].get(i2 - boff[i]);
      if (larr[val])
        res++;
    }
  }
  return res;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  lcnt = 0;
  for (int l = 1; l <= 4; l++) {
    for (int m = 0; m < (1 << l); m++) {
      ll x = 0;
      for (int i = 0; i < l; i++)
        x = x * 10 + ((m & (1 << i)) ? 7 : 4);
      lucky[lcnt++] = x;
    }
  }
  sort(lucky, lucky + lcnt);

  memset(larr, 0, sizeof larr);
  for (int i = 0; i < lcnt; i++)
    larr[lucky[i]] = true;

  int n, m;
  while (scanf("%d%d", &n, &m) >= 1) {
    vi as(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);

    bcnt = 0;
    for (int pos = 0; pos < n; pos += BLEN) {
      int l = min(n - pos, BLEN);
      bs[bcnt] = Block(l);
      boff[bcnt] = pos;
      blen[bcnt] = l;
      for (int i = 0; i < l; i++)
        bs[bcnt].add(i, as[pos + i]);
      bcnt++;
    }

    for (int i = 0; i < m; i++) {
      char op[16];
      int l, r, x;
      scanf("%s%d%d", op, &l, &r), l--, r--;
      if (!strcmp(op, "count")) {
        printf("%d\n", count(l, r));
      } else if (!strcmp(op, "add")) {
        scanf("%d", &x);
        add(l, r, x);
      }
    }
  }
  return 0;
}