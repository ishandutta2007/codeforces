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

  static char s[110];
  const char *need = "CODEFORCES";

  while (scanf("%s", s) == 1) {
    int n = strlen(s);
    int m = strlen(need);
    int sklen = n - m;

    bool found = false;
    if (sklen >= 0) {
      for (int i = 0; i + sklen <= n; i++) {
        string cur = s;
        cur.erase(cur.begin() + i, cur.begin() + i + sklen);
        if (cur == need) {
          found = true;
          break;
        }
      }
    }
    printf("%s\n", found ? "YES" : "NO");
  }

  return 0;
}