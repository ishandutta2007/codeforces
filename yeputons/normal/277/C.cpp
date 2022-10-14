#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
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

vector<pii> evs;
int sumlen(int maxx = 2e9) {
  int res = 0, bal = 0;
  int px = 0;
  for (int i = 0; i < sz(evs); i++) {
    if (bal) {
      int cl = px, cr = min(maxx, evs[i].first - 1);
      if (cl <= cr)
        res += cr - cl + 1;
    }
    px = evs[i].first;
    bal += evs[i].second;
  }
  assert(bal == 0);
  return res;
}
int calc(int h, int w, const map<int, vector<pii> > &hors) {
  int res = 0;
  if ((h - 1 - sz(hors)) % 2) res ^= w;

  for (map<int, vector<pii> >::const_iterator it = hors.begin(); it != hors.end(); it++) {
    evs = it->second;
    sort(evs.begin(), evs.end());

    int len = sumlen();
    assert(0 <= len && len <= w);
    res ^= w - len;
  }
  return res;
}

int resy, resx1, resx2;
bool findTurn(int h, int w, map<int, vector<pii> > hors, int mask) {
  if (h - 1 - sz(hors) > 0) {
    int cury = 1;
    while (hors.find(cury) != hors.end()) cury++;
    hors[cury] = vector<pii>();
    assert(cury < h);
  }

  for (map<int, vector<pii> >::const_iterator it = hors.begin(); it != hors.end(); it++) {
    evs = it->second;
    sort(evs.begin(), evs.end());

    int len = sumlen();
    assert(0 <= len && len <= w);
    int cnim = w - len;
    int nval = mask ^ cnim;
    if (nval < cnim) {
      int tocut = cnim - nval;

      int L = 0, R = w;
      assert(R - sumlen(R - 1) >= tocut);
      while (L + 1 < R) {
        int M = (L + R) / 2;
        if (M + 1 - sumlen(M) <= tocut) L = M;
        else R = M;
      }
      assert(L + 1 - sumlen(L) == tocut);
      resy = it->first;
      resx1 = 0;
      resx2 = L + 1;
      return true;
    }
  }
  return false;
}

int main() {
  #ifdef DEBUG
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  #endif

  int w, h, k;
  while (scanf("%d%d%d", &w, &h, &k) >= 1) {
    map<int, vector<pii> > hors, vers;
    for (int i = 0; i < k; i++) {
      int x1, y1, x2, y2;
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      if (x1 > x2) swap(x1, x2);
      if (y1 > y2) swap(y1, y2);

      if (y1 == y2) {
        hors[y1].pb(mp(x1, 1));
        hors[y1].pb(mp(x2, -1));
      } else {
        assert(x1 == x2);
        vers[x1].pb(mp(y1, 1));
        vers[x1].pb(mp(y2, -1));
      }
    }

    int cgame = 0;
    cgame ^= calc(h, w, hors);
    cgame ^= calc(w, h, vers);
    if (cgame == 0) printf("SECOND\n");
    else {
      printf("FIRST\n");
      resy = resx1 = resx2 = -1;
      if (findTurn(h, w, hors, cgame)) {
        printf("%d %d %d %d\n", resx1, resy, resx2, resy);
      } else if (findTurn(w, h, vers, cgame)) {
        printf("%d %d %d %d\n", resy, resx1, resy, resx2);
      } else {
        assert(false);
      }
    }
  }
  return 0;
}