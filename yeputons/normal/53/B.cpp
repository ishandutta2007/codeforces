#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdarg>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) {}
#endif

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (n); i++)
#define EPS 1e-9

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;

int rup(double x) {
  int y = (int)x - 5;
  while ((double)y < x - EPS) y++;
  return y;
}
int rdn(double x) {
  int y = (int)x + 5;
  while ((double)y > x + EPS) y--;
  return y;
}

void relax(pii &ans, const pii cans) {
  ll s1 = (ll)ans.first * ans.second;
  ll s2 = (ll)cans.first * cans.second;
  if (s1 > s2) return;
  if (s1 < s2) { ans = cans; return; }
  if (ans.first < cans.first)
    ans = cans;
}

int n;
int main() {
  #ifdef DEBUG
  freopen("stdin.txt", "r", stdin);
  freopen("stdout.txt", "w", stdout);
  #endif

/*  assert(rup(0.99999999999999999) == 1);
  assert(rup(0.1) == 1);
  assert(rup(0.9) == 1);
  assert(rdn(0.99999999999999999) == 1);
  assert(rdn(0.1) == 0);
  assert(rdn(0.9) == 0);*/

  int mh, mw;
  while (scanf("%d%d", &mh, &mw) >= 1) {
    pii ans(0, 0);
    for (int step = 0; step < 2; step++) {
      for (int h = 1; h <= mh; h <<= 1) {
        int lw = rup((double)h / 1.25);
        int rw = rdn((double)h / 0.8);
        rw = min(rw, mw);
        if (lw > rw) continue;

        pii cans = mp(h, rw);
        if (step) swap(cans.first, cans.second);
        relax(ans, cans);
      }
      swap(mw, mh);
    }
    printf("%d %d\n", ans.first, ans.second);
    
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}