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

int cinv(const vi &ord) {
  int ans = 0;
  forn (i, sz(ord))
  forn (j, i)
    ans += ord[i] < ord[j];
  return ans;
}

ll ans, acnt;
void go(vi &ord, int k) {
  if (!k) {
    acnt++;
    ans += cinv(ord);
    return;
  }
  for (int i = 0; i < sz(ord); i++)
  for (int j = i; j < sz(ord); j++) {
    reverse(ord.begin() + i, ord.begin() + j + 1);
    go(ord, k - 1);
    reverse(ord.begin() + i, ord.begin() + j + 1);
  }
}

int main() {
  #ifdef DEBUG
  freopen(TASKNAME".in","r",stdin);
  freopen(TASKNAME".out","w",stdout);
  #endif

  int n, k;
  while (scanf("%d%d", &n, &k) == 2) {
    vi ord(n);
    forn (i, n) scanf("%d", &ord[i]);

    ans = 0; acnt = 0;
    go(ord, k);
    printf("%.18lf\n", (double)ans / acnt);
  }  

  return 0;
}