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

int n;
vi as;
class BSys {
  static const int K = 600;
  vll ss;

  public:
  BSys() {}
  BSys(const vi &vals, int vlen) : ss(vlen / K) {
    ll csum = 0;
    int ccnt = 0;
    int clen = 0;

    for (int i = 0; i < vlen; i++) {
      csum += vals[i];
      ccnt++;
      if (ccnt >= K) {
        ss[clen++] = csum;
        ccnt = 0;
      }
    }
  }
  ll get(int st, int len) {
    ll res = 0;
    int cpos = st / len;
    while ((cpos + 1) % K && st >= 0) {
      res += as[st];
      st -= len;
      cpos--;
    }
    if (st >= 0)
      res += ss[cpos / K];
    return res;
  }
};

const int MINRQ = 400;
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    as = vi(n);
    for (int i = 0; i < n; i++)
      scanf("%d", &as[i]);
    reverse(as.begin(), as.end());

    vector<vector<BSys> > cache(MINRQ);
    vi tmp(n);
    for (int k = 1; k < MINRQ; k++) {
      cache[k] = vector<BSys>(k);
      for (int st = 0; st < k; st++) {
        int len = 0;
        for (int i = st; i < n; i += k)
          tmp[len++] = as[i];
        cache[k][st] = BSys(tmp, len);
      }
    }
    eprintf("GO\n");

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int st, len;
      scanf("%d%d", &st, &len), st--;
      st = n - 1 - st;

      ll res = 0;
      if (len >= MINRQ) {
        for (int i = st; i >= 0; i -= len)
          res += as[i];
      } else {
        res = cache[len][st % len].get(st, len);
      }
      printf("%I64d\n", res);
    }
  }
  return 0;
}