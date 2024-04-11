#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

void add(int &a, int b, int p) {
  a = (a + b) % p;
}
int mul(int a, int b, int p) {
  return a * b % p;
}
int getid(char c) {
  if (c >= '0' && c <= '9') return c - '0';
  assert(c >= 'A' && c <= 'F');
  return c - 'A' + 10;
}

const int MAXD = 16;
const int MAXN = 1e4;
const int MSZ = 4;
const ll MMSK = (1 << MSZ) - 1;

struct Req {
  int d;
  ll msk, mval, c;
  bool bad;
};

ll ids[MAXD + 1][MAXN];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  vi ps;
  for (int i = 2; i <= 100; i++) {
    bool g = true;
    for (int i2 = 2; i2 * i2 <= i; i2++)
      if (i % i2 == 0) g = false;
    if (!g) continue;
    ps.pb(i);
  }

  for (int d = 2; d <= MAXD; d++) {
    for (int i = 0; i < MAXN; i++) {
      vi ds;
      int x = i;
      for (; x; x /= d) ds.pb(x % d);

      ll &msk = ids[d][i] = 0;
      for (int i2 = 0; i2 < sz(ds); i2++)
        msk |= (ll)ds[i2] << (MSZ * i2);
    }
  }

  int n, m;
  while (scanf("%d", &n) >= 1) {
    vll as(n);
    vvll asp(n);
    for (int i = 0; i < n; i++) {
      scanf("%I64d", &as[i]);
      for (int i2 = 0; i2 < sz(ps); i2++)
        asp[i].pb(as[i] % ps[i2]);
    }

    scanf("%d", &m);
    vector<set<ll> > msks(MAXD + 1);
    vector<Req> rqs(m);
    for (int i = 0; i < m; i++) {
      int &d = rqs[i].d;
      char s[31];
      scanf("%d%s%I64d", &d, s, &rqs[i].c);

      int i2 = 0;
      int pos = strlen(s) - 1;
      bool &bad = rqs[i].bad = false;
      while (pos >= 14) {
        if (s[i2] != '?' && s[i2] != '0') {
          bad = true;
          break;
        }
        i2++;
        pos--;
      }
      if (bad)
        continue;

      ll &msk = rqs[i].msk, &mval = rqs[i].mval;
      for (i2 = 0; s[i2]; i2++, pos--)
        if (s[i2] != '?') {
          msk |= MMSK << (MSZ * pos);
          mval |= (ll)getid(s[i2]) << (MSZ * pos);
        }
      msks[d].insert(msk);
    }
    eprintf("read\n");

    vector<map<ll, map<ll, vi> > > pcs(MAXD + 1);
    for (int d = 2; d <= MAXD; d++) {
      eprintf("d=%d %d\n", d, sz(msks[d]));
      for (set<ll>::iterator it = msks[d].begin(); it != msks[d].end(); it++) {
         ll msk = *it;

         map<ll, vi> &cnts = pcs[d][msk];
         for (int i = 0; i < n; i++) {
           vi &ccnt = cnts[ids[d][i] & msk];
           if (ccnt.empty())
             ccnt = vi(sz(ps), 1);

           for (int i2 = 0; i2 < sz(ccnt); i2++)
             ccnt[i2] = mul(ccnt[i2], asp[i][i2], ps[i2]);
         }
      }
    }

    eprintf("go\n");
    for (int i = 0; i < m; i++) {
      vi cps(sz(ps));
      for (int i2 = 0; i2 < sz(ps); i2++)
        cps[i2] = rqs[i].c % ps[i2];

      vi nps(sz(ps), 1);
      if (!rqs[i].bad) {
        map<ll, vi> &cnts = pcs[rqs[i].d][rqs[i].msk];
        const vi &res = cnts[rqs[i].mval];
        if (!res.empty()) nps = res;
      }

      for (int i2 = 0; i2 < sz(ps); i2++)
        add(cps[i2], nps[i2], ps[i2]);
      int ans = -1;
      for (int i2 = 0; i2 < sz(ps); i2++)
        if (!cps[i2]) { ans = ps[i2]; break; }
      printf("%d\n", ans);
    }
    eprintf("end\n");
  }
  return 0;
}