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

struct Team {
  string name;
  int score;
  int ballWon, ballLost;

  Team(const char *_name) : name(_name), score(0), ballWon(0), ballLost(0) {}
  bool operator<(const Team &t2) const {
    if (score != t2.score) return score > t2.score;
    if (ballWon - ballLost != t2.ballWon - t2.ballLost) return ballWon - ballLost > t2.ballWon - t2.ballLost;
    if (ballWon != t2.ballWon) return ballWon > t2.ballWon;
    return name < t2.name;
  }
};

void addStat(Team &a, Team &b, int ga, int gb) {
  if (ga > gb) a.score += 3;
  else if (ga == gb) a.score += 1, b.score += 1;
  else b.score += 3;

  a.ballWon += ga;
  a.ballLost += gb;
  b.ballWon += gb;
  b.ballLost += ga;
}

const char *ME = "BERLAND";

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  for (;;) {
    vector<Team> ts;
    map<string, int> names;
    names[ME] = 0;
    ts.pb(Team(ME));

    vvb was(4, vb(4, false));

    bool g = true;
    for (int i = 0; i < 5; i++) {
      char a[21];
      char b[21];
      int ga, gb;
      if (scanf(" %s %s %d:%d", a, b, &ga, &gb) != 4) { g = false; break; }

      if (!names.count(a)) { names[a] = sz(ts); ts.pb(a); }
      if (!names.count(b)) { names[b] = sz(ts); ts.pb(b); }

      addStat(ts[names[a]], ts[names[b]], ga, gb);
      was[names[a]][names[b]] = was[names[b]][names[a]] = true;
    }
    if (!g) break;

    assert(sz(ts) == 4);

    int a = 0;
    pii cans(-1e9, 1e9);
    int cv1 = 2e9, cv2 = 2e9;

    for (int b = a + 1; b < 4; b++) if (!was[a][b]) {
      for (int ga = 0; ga < 100; ga++)
      for (int gb = 0; gb < ga; gb++) {
        vector<Team> nts = ts;
        addStat(nts[a], nts[b], ga, gb);
        sort(nts.begin(), nts.end());

        bool g = false;
        for (int i = 0; i < 2; i++)
          if (nts[i].name == ME)
            g = true;
        if (g) {
          int v1 = ga - gb, v2 = gb;
          if (v1 < cv1 || (v1 == cv1 && v2 < cv2)) {
            cv1 = v1;
            cv2 = v2;
            cans = mp(ga, gb);
          }

        }
      }
    }
    if (cv1 < 1000) printf("%d:%d\n", cans.first, cans.second);
    else printf("IMPOSSIBLE\n");
  }
  return 0;
}