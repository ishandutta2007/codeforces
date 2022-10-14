#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define pb push_back
#define mp make_pair

typedef long long ll;

typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
pii divide(int a, int b) {
  assert(a >= 1 && b >= 1);
  int d = gcd(a, b);
  return mp(a / d, b / d);
}

template<typename T> class fenv_tree {
  vector<T> tr;

  int f(int x) { return x - (x & (x - 1)); }

  public:
  fenv_tree(int n) { tr = vector<T>(n + 1); }
  void add(int x, const T &v) {
    x++;
    for (; x < tr.size(); x += f(x))
      tr[x] += v;
  }
  T get(int x) {
    x++;
    T val;
    for (; x > 0; x -= f(x))
      val += tr[x];
    return val;
  }
};

const int MAXN = 1e5;
int rev[MAXN + 1];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (int i = 0; i <= MAXN; i++) {
    int x = i, y = 0;
    for (; x ; x /= 10) y = y * 10 + x % 10;
    rev[i] = y;
  }
  assert(rev[12345] == 54321);
  assert(rev[1200] == 21);

  int mx, my, w;
  while (scanf("%d%d%d", &mx, &my, &w) >= 1) {
    map<pii, vi> cnts;
    for (int b = 1; b <= my; b++) {
      pii cur = divide(rev[b], b);
      cnts[cur].pb(b);
    }

    ll ans = 1e18;
    int ax = -1, ay = -1;
    fenv_tree<ll> tr(my + 1);

    for (int a = 1; a <= mx; a++) {
      pii cur = divide(a, rev[a]);
      for (int i = 0; i < cnts[cur].size(); i++)
        tr.add(cnts[cur][i], 1);

      if (tr.get(my) >= w) {
        int L = 0, R = my;
        while (L + 1 < R) {
          int M = (L + R) / 2;
          if (tr.get(M) >= w) R = M;
          else L = M;
        }
        if ((ll)a * R < ans) {
          ans = (ll)a * R;
          ax = a;
          ay = R;
        }
      }
    }

    if (ax < 0) printf("-1\n");
    else
      printf("%d %d\n", ax, ay);

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}