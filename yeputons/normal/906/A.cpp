#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <iostream>

#define pb push_back
#define mp make_pair
#define TASKNAME ""

#ifdef DEBUG
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("[" #x "] Time = %.3lfs\n",clock()*1.0/CLOCKS_PER_SEC)

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

#define sz(x) ((int)(x).size())
#define forn(i, n) for (int i = 0; i < (n); i++)

using namespace std;

typedef long double ld;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;

const int inf = 1e9;
const double eps = 1e-9;
const int INF = inf;
const double EPS = eps;

#ifdef DEBUG
struct __timestamper {
  ~__timestamper(){
    TIMESTAMP(end);
  }
} __Timestamper;
#else
struct __timestamper {};
#endif

/*Template end*/

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n;
  while (scanf("%d", &n) == 1) {
    eprintf("=====\n");
    vb can(26, true);
    bool know = false;
    int ans = 0;
    for (int sid = 0; sid < n; sid++) {
      char op;
      static char s[int(1e5) + 10];
      assert(scanf(" %c%s", &op, s) == 2);

      if (op == '.') {
        for (int i = 0; s[i]; i++)
          can[s[i] - 'a'] = false;
      } else if (op == '!') {
        if (know) ans++;
        vb contains(26, false);
        for (int i = 0; s[i]; i++)
          contains[s[i] - 'a'] = true;
        forn (i, 26)
          can[i] = can[i] && contains[i];
      } else if (op == '?') {
        if (sid + 1 < n) {
          // didn't guess
          if (know) ans++;
          can[s[0] - 'a'] = false;
        } else {
          // guessed
          know = true;
          fill(can.begin(), can.end(), false);
          can[s[0] - 'a'] = true;
        }
      }
      if (count(can.begin(), can.end(), true) == 1) {
        eprintf("know after %d\n", sid);
        know = true;
      }
    }
    assert(know);
    assert(count(can.begin(), can.end(), true) == 1);
    printf("%d\n", ans);
  }

  return 0;
}