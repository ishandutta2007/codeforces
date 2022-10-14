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

const int INF = 1e9;
class segm_tree {
  vector<pii> tr;
  int off;

  public:
  segm_tree(int *arr = 0, int n = 0) {
    off = 1; while (off < n) off <<= 1;
    tr = vector<pii>(2 * off, mp(INF, INF));
    for (int i = 0; i < n; i++)
      tr[off + i] = mp(arr[i], i);
    for (int i = off - 1; i >= 1; i--)
      tr[i] = min(tr[2 * i], tr[2 * i + 1]);
  }
  pii get(int l, int r) {
    pii res(INF, INF);
    l += off; r += off;
    while (l <= r) {
      if (l & 1) res = min(res, tr[l++]);
      if (!(r & 1)) res = min(res, tr[r--]);
      l >>= 1; r >>= 1;
    }
    return res;
  }
};
class fenv_tree {
  vi tr;
  static int f(int x) { return x ^ (x & (x - 1)); }
  public:
  fenv_tree(int n) : tr(n + 1, 0) {}
  void add(int x, int v) {
    for (x++; x < sz(tr); x += f(x)) tr[x] += v;
  }
  int get(int x) {
    int res = 0;
    for (x++; x > 0; x -= f(x)) res += tr[x];
    return res;
  }
};

const int MAXC = 1e5 + 1e2;
const int MAXN = 2e5 + 1e3;
int data[MAXN + 1];
int dlen;

int oid[MAXN];
int sarr[MAXN];
int lcp[MAXN];

segm_tree tr;

void suf_array() {
  static int cid[MAXC];
  memset(cid, 0, sizeof cid);

  for (int i = 0; i < dlen; i++)
    cid[data[i]] = 1;
  {
    int ccnt = 0;
    for (int i = 0; i < MAXC; i++) if (cid[i])
      cid[i] = ccnt++;
  }

  for (int i = 0; i < dlen; i++)
    oid[i] = cid[data[i]];

  for (int clen = 1; clen < dlen; clen <<= 1) {
    static struct LEl {
      int v1, v2;
      int ne2, ne1;
    } els[MAXN];
    static int firs2[MAXN + 1];
    static int firs1[MAXN + 1];

    for (int i = 0; i < dlen; i++) {
      els[i].v1 = oid[i];
      els[i].v2 = i + clen < dlen ? (oid[i + clen] + 1) : 0;
      els[i].ne1 = els[i].ne2 = -1;
    }
    memset(firs2, -1, sizeof firs2);
    for (int i = 0; i < dlen; i++) {
      els[i].ne2 = firs2[els[i].v2];
      firs2[els[i].v2] = i;
    }

    memset(firs1, -1, sizeof firs1);
    for (int x = dlen; x >= 0; x--)
      for (int i = firs2[x]; i >= 0; i = els[i].ne2) {
        assert(els[i].v2 == x);
        els[i].ne1 = firs1[els[i].v1];
        firs1[els[i].v1] = i;
      }
    int ccnt = -1;
    int pr1 = -1, pr2 = -1;
    for (int x = 0; x <= dlen; x++)
      for (int i = firs1[x]; i >= 0; i = els[i].ne1) {
        if (pr1 != els[i].v1 || pr2 != els[i].v2) ccnt++;
        assert(pr1 <= els[i].v1);
        if (pr1 == els[i].v1) assert(pr2 <= els[i].v2);

        oid[i] = ccnt;
        pr1 = els[i].v1;
        pr2 = els[i].v2;
      }
  }
  memset(sarr, -1, sizeof sarr);
  for (int i = 0; i < dlen; i++) sarr[oid[i]] = i;
  for (int i = 0; i < dlen; i++)
    assert(sarr[i] >= 0);

  memset(lcp, -1, sizeof lcp);
  int clen = 0;
  for (int i = 0; i < dlen; i++, clen = max(0, clen - 1)) {
    if (oid[i] + 1 >= dlen) continue;
    int b = sarr[oid[i] + 1];
    assert(i != b);

    #ifdef DEBUG
    assert(i + clen <= dlen);
    assert(b + clen <= dlen);
    for (int i2 = 0; i2 < clen; i2++)
      assert(data[i + i2] == data[b + i2]);
    #endif
    while (data[i + clen] == data[b + clen]) clen++;
    lcp[oid[i]] = clen;
  }
  tr = segm_tree(lcp, dlen);
}

char s[MAXN + 1];

int col[MAXN];
int k;

struct Req {
  int l, r;
  int val;

  bool operator<(const Req &r2) const { return l > r2.l; }
};

vector<Req> rqs;

void go(int l, int r, int plen) {
  if (l + k - 1 > r) return;
  assert(l < r);

  pii nlen = tr.get(l, r - 1);
  if (nlen.first == plen) {
    go(l, nlen.second, plen);
    go(nlen.second + 1, r, plen);
    return;
  }
  Req cr;
  cr.l = l;
  cr.r = r;
  cr.val = nlen.first - plen;
  rqs.pb(cr);
  go(l, r, nlen.first);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d%d", &n, &k) >= 1) {
    dlen = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      for (int i2 = 0; s[i2]; i2++)
        data[dlen++] = s[i2] - 'a' + n;
      data[dlen++] = i;

      if (k == 1) {
        ll l = strlen(s);
        printf("%I64d%c", l * (l + 1) / 2, "\n "[i + 1 < n]);
      }
    }

    if (k == 1)
      continue;

    suf_array();
    memset(col, -1, sizeof col);
    {
      int cid = 0;
      for (int i = 0; i < dlen; i++) if (data[i] >= n)
        col[oid[i]] = cid;
      else
        cid++;
    }
    rqs.clear();
    go(0, dlen - 1, 0);

    sort(rqs.begin(), rqs.end());

    vi neSame(dlen, -1);
    {
      vi last(n, -1);
      for (int i = dlen - 1; i >= 0; i--) if (col[i] >= 0) {
        neSame[i] = last[col[i]];
        last[col[i]] = i;
      }
    }

    fenv_tree tr(dlen);
    int ptr = dlen;
    vi toadd(dlen + 1, 0);

    for (int i = 0; i < sz(rqs); i++) {
      while (ptr > rqs[i].l) {
        ptr--;
        if (col[ptr] < 0) continue;
        if (neSame[ptr] >= 0) tr.add(neSame[ptr], -1);
        tr.add(ptr, 1);
      }
      if (tr.get(rqs[i].r) >= k) {
        toadd[rqs[i].l] += rqs[i].val;
        toadd[rqs[i].r + 1] -= rqs[i].val;
      }
    }

    vector<ll> cans(n, 0);
    ll cst = 0;
    for (int i = 0; i < dlen; i++) {
      cst += toadd[i];
      if (col[i] >= 0)
        cans[col[i]] += cst;
    }
    for (int i = 0; i < n; i++)
      printf("%I64d%c", cans[i], "\n "[i + 1 < n]);
  }
  return 0;
}