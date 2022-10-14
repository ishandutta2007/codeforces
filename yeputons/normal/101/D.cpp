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

vector<vector<pii> > es;

struct Ret {
  double avgt, sumt;
  int scnt;

  Ret() : avgt(0), sumt(0), scnt(0) {}
  Ret(double _avgt, double _sumt, int _scnt) : avgt(_avgt), sumt(_sumt), scnt(_scnt) {}
};
bool mycmp(const pair<Ret, double> &a, const pair<Ret, double> &b) {
//  return a.first.scnt * a.second < b.first.scnt * b.second;
  return
    b.first.scnt * a.first.sumt
  < a.first.scnt * b.first.sumt;
}

Ret go(int v, int par = -1) {
  vector<pair<Ret, double> > chi;

  for (int i = 0; i < sz(es[v]); i++) {
    int b = es[v][i].second;
    double w = es[v][i].first;
    if (b == par) continue;

    Ret cres = go(b, v);
    cres.avgt += w * cres.scnt;
    cres.sumt += w * 2;
    chi.pb(mp(cres, w));
  }
  sort(chi.begin(), chi.end(), mycmp);

  double avgt = 0, sumt = 0;
  int scnt = 1;
  for (int i = 0; i < sz(chi); i++) {
    Ret cres = chi[i].first;
    avgt += cres.avgt + sumt * cres.scnt;
    sumt += cres.sumt;
    scnt += cres.scnt;
  }
//  eprintf("go(%d)=%.2lf %.2lf %d\n", v, avgt, sumt, scnt);
  return Ret(avgt, sumt, scnt);
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    es = vector<vector<pii> >(n);
    for (int i = 0; i < n - 1; i++) {
      int a, b, w;
      scanf("%d%d%d", &a, &b, &w), a--, b--;
      es[a].pb(mp(w, b));
      es[b].pb(mp(w, a));
    }
/*    for (int i = 0; i < n; i++) {
      sort(es[i].begin(), es[i].end());
    }*/

    printf("%.18lf\n", go(0).avgt / (n - 1));

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}