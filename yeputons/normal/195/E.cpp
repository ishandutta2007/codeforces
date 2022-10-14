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

class Dsu {
  vi par, ss, val;
  int get(int x) { return par[x] == x ? x : par[x] = get(par[x]); }

  public:
  Dsu(int n = 0) : par(n), ss(n, 1), val(n) {
    for (int i = 0; i < n; i++)
      par[i] = val[i] = i;
  }
  int getVal(int x) { return val[get(x)]; }
  int getSize(int x) { return ss[get(x)]; }
  void mergeTo(int a, int b) {
    a = get(a); b = get(b);
    int nv = val[b];
    if (a == b) return;

    if (ss[a] > ss[b]) swap(a, b);
    par[a] = b;
    ss[b] += ss[a];
    val[b] = nv;
  }
};

const int MOD = 1e9 + 7;
void madd(int &a, int b) { a += b; while (a >= MOD) a -= MOD; }
int mplus(int a, int b) { madd(a, b); return a; }

int n;
vvi chi;
Dsu dsu;
vi pot;

void dfsAddPot(int v, int x) {
  madd(pot[v], x);
  for (int i = 0; i < sz(chi[v]); i++)
    dfsAddPot(chi[v][i], x);
}
void addE(int a, int b, int w) {
  int npar = b, nchi = a;

  int addToBpot = mplus(w, MOD - mplus(pot[b], MOD - pot[a]));
  if (dsu.getSize(a) < dsu.getSize(b)) swap(a, b), addToBpot = mplus(MOD - addToBpot, 0);
  dfsAddPot(b, addToBpot);

  dsu.mergeTo(nchi, npar);
  chi[npar].pb(nchi);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    chi = vvi(n);
    dsu = Dsu(n);

    pot = vi(n, 0);
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int k;
      scanf("%d", &k);
      for (int i2 = 0; i2 < k; i2++) {
        int v, x;
        scanf("%d%d", &v, &x), v--;
        while (x < 0) x += MOD;
        while (x >= MOD) x -= MOD;

        assert(0 <= v && v < i);
        int root = dsu.getVal(v);

        int nw = mplus(mplus(pot[root], MOD - pot[v]), x);
        madd(ans, nw);
        addE(root, i, nw);
        assert(mplus(pot[i], MOD - pot[root]) == nw);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}