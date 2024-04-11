#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int eprintf(const char *format, ...) {
  #ifdef DEBUG
  va_list args;
  va_start(args, format);
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
typedef vector<pii> vpii;

typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
  #ifdef DEBUG
  freopen("task.in", "r", stdin);
  freopen("task.out", "w", stdout);
  #endif

  int p1, p2, p3, t2, t3;
  int n;
  while (scanf("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t2, &t3) >= 6) {
    vpii segs(n);
    for (int i = 0; i < n; i++) scanf("%d%d", &segs[i].first, &segs[i].second);
//    sort(segs.begin(), segs.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += (segs[i].second - segs[i].first) * p1;
      if (i) {
        int l = segs[i].first - segs[i - 1].second;
        ans += min(l, t2) * p1; l -= t2;
        if (l > 0) {
          ans += min(l, t3) * p2; l -= t3;
          if (l > 0) {
            ans += l * p3;
            l = 0;
          }
        }
      }
    }
    
    printf("%d\n", ans);
    #ifndef DEBUG
    break;
    #endif
  } 
  return 0;
}