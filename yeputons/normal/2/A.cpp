#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

#define INF 2000000000
#define mp make_pair
#define pb push_back

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef pair<int, int> pii;
typedef vector<pii> vpii;

typedef double dbl;

typedef long long ll;
typedef vector<ll> vll;

typedef vector<bool> vb;
typedef vector<string> vs;

char namebuf[33];
int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int n;
  while (scanf("%d", &n) >= 1) {
    vector<pair<string, int> > acts(n);
    map<string, int> players;
    map<string, int>::iterator it;

    for (int i = 0; i < n; i++) {
      int x; scanf(" %s %d", namebuf, &x);
      acts[i] = mp(namebuf, x);

      it = players.find(namebuf);
      if (it != players.end()) {
        x += it->second;
        players.erase(it);
      }
      players.insert(mp(namebuf, x));
    }
    int m = -1;
    for (it = players.begin(); it != players.end(); it++)
      m = max(m, it->second);

    set<string> gplayers;
    for (it = players.begin(); it != players.end(); it++)
      if (it->second >= m) gplayers.insert(it->first);

    string ans = "";
    players = map<string, int>();
    for (int i = 0; i < n; i++)
      if (gplayers.find(acts[i].first) != gplayers.end()) {
        int x = acts[i].second;
        it = players.find(acts[i].first);
        if (it != players.end()) {
          x += it->second;
          players.erase(it);
        }
        if (x >= m) {
          ans = acts[i].first;
          break;
        }
        players.insert(mp(acts[i].first, x));
      }
    printf("%s\n", ans.c_str());

    #ifndef DEBUG
    break;
    #endif
  }

  return 0;
}