#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int eoff = 0;
int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
  for (int i = 0; i < eoff; i++) fprintf(stderr, " ");
  int ret = vfprintf(stderr, format, args);
  va_end(args);
  return ret;
  #else
  return 0;
  #endif
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))
#define sqr(a, b) ((a) * (a))
#define INF 2000000000
#define pb push_back
#define mp make_pair

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef double dbl;
typedef vector<dbl> vdbl;

typedef long long ll;
typedef vector<ll> vll;

typedef pair<int, int> pii;

typedef vector<bool> vb;
typedef vector<string> vs;

#define MAXC 5000

int dyn[MAXC][MAXC];
int fr[MAXC][MAXC];
vi ans;
vector<pii> pts;
vvi starts;

int getAns(int l, int r) {
  if (l > r) return 0;

  int ssz = ans.size();
  for (int i = 0; i < starts[l].size(); i++)
    if (pts[starts[l][i]].second == r) {
      ans.pb(starts[l][i]);
      break;
    }

  eoff += 2;
  if (fr[l][r] > 0) {
    int mid = pts[fr[l][r]].second;
    getAns(l, mid);
    getAns(mid, r);
  } else {
    getAns(l + 1, r);
  }
  assert(ans.size() - ssz == dyn[l][r]);
  eoff -= 2;
  return dyn[l][r];
}

int main() {
  #ifdef DEBUG
  freopen("stdin", "r", stdin);
  freopen("stdout", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pii> evs;
    for (int i = 0; i < n; i++) {
      int c, r;
      scanf("%d%d", &c, &r);
      evs.pb(mp(c - r, i + 1));
      evs.pb(mp(c + r, -i - 1));
    }
    sort(evs.begin(), evs.end());

    map<int, int> ncs;
    for (int i = 0; i < evs.size(); i++) {
      if (ncs.find(evs[i].first) == ncs.end()) {
        ncs.insert(mp(evs[i].first, ncs.size()));
      }
      evs[i].first = ncs[evs[i].first];
    }

    pts = vector<pii>(n + 1);
    for (int i = 0; i < evs.size(); i++) {
      if (evs[i].second > 0) pts[evs[i].second].first = evs[i].first;
      else pts[-evs[i].second].second = evs[i].first;
    }

    starts = vvi(ncs.size());
    for (int i = 1; i <= n; i++) {
      int l = pts[i].first, r = pts[i].second;

      int pos = starts[l].size();
      for (int i2 = 0; i2 < starts[l].size(); i2++) {
        if (pts[starts[l][i2]].second > r) {
          pos = i2;
          break;
        }
      }
      starts[l].pb(i);
      for (int i2 = starts[l].size() - 1; i2 > pos; i2--)
        swap(starts[l][i2], starts[l][i2 - 1]);
    }

/*    for (int i = 1; i <= n; i++)
      eprintf("%d %d\n", pts[i].first, pts[i].second);
    for (int i = 0; i < ncs.size(); i++) {
      eprintf("starts[%d]: ", i);
      for (int i2 = 0; i2 < starts[i].size(); i2++) eprintf(" %d", starts[i][i2]);
      eprintf("\n");
    }*/

    memset(dyn, 0, sizeof dyn);
    memset(fr, 0, sizeof fr);

    vi fBad(ncs.size(), 0);

    for (int l = 0; l < ncs.size(); l++)
      for (int st = 0; st + l < ncs.size(); st++) {
        dyn[st][st + l] = dyn[st + 1][st + l];

        while (fBad[st] < starts[st].size() && pts[starts[st][fBad[st]]].second <= st + l) fBad[st]++;
        if (!fBad[st]) continue;

        int add = 0;
        if (pts[starts[st][fBad[st] - 1]].second == st + l) {
          add++;
          fBad[st]--;
          dyn[st][st + l]++;
        }

        for (; fBad[st]; fBad[st]--) {
          int nval = add;
          int mid = pts[starts[st][fBad[st] - 1]].second;
          int cfr = starts[st][fBad[st] - 1];

          assert(st != mid && mid != st + l);
          nval += dyn[st][mid] + dyn[mid][st + l];

          if (nval > dyn[st][st + l]) {
            dyn[st][st + l] = nval;
            fr[st][st + l] = cfr;
          }
        }
      }

    ans = vi();
    printf("%d\n", getAns(0, ncs.size() - 1));
    for (int i = 0; i < ans.size(); i++)
      printf("%d%c", ans[i], "\n "[i + 1 < ans.size()]);

    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}