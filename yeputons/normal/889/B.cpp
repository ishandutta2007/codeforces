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

  int k;
  while (scanf("%d", &k) == 1) {
    vector<string> ss(k);
    for (auto &s : ss) {
      static char buf[int(1e5) + 100];
      scanf("%s", buf);
      s = buf;
    }
    eprintf("\n==========\n");
    const int n = 26;
    vi pr(n, -1), ne(n, -1);
    vb was(n, true);
    for (const auto &s : ss) {
      for (int i = 0; i + 1 < sz(s); i++) {
        int x = s[i] - 'a', y = s[i + 1] - 'a';
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        eprintf("%d-->%d\n", x, y);
        if (ne[x] >= 0 && ne[x] != y) {
          printf("NO\n");
          goto end;
        }
        ne[x] = y;
        if (pr[y] >= 0 && pr[y] != x) {
          printf("NO\n");
          goto end;
        }
        pr[y] = x;
      }
      for (char c : s) {
        was[c - 'a'] = false;
      }
    }
    eprintf("==\n");
    {
      vector<string> ans;
      for (int st = 0; st < sz(was); st++)
        if (!was[st]) {
          eprintf("st=%d\n", st);
          string cur = "";
          for (int i = st; i >= 0; i = ne[i]) {
            eprintf("-->%d\n", i);
            if (was[i]) {
              printf("NO\n");
              goto end;
            }
            was[i] = true;
            cur += 'a' + i;
          }
          string cur2 = "";
          for (int i = pr[st]; i >= 0; i = pr[i]) {
            eprintf("<--%d\n", i);
            if (was[i]) {
              printf("NO\n");
              goto end;
            }
            was[i] = true;
            cur2 += 'a' + i;
          }
          reverse(cur2.begin(), cur2.end());
          eprintf("ans=%s|%s\n", cur2.c_str(), cur.c_str());
          ans.push_back(cur2 + cur);
        }
      sort(ans.begin(), ans.end());
      string res = "";
      for (const string &s : ans) res += s;
      printf("%s\n", res.c_str());
    }
    end:;
  }

  return 0;
}