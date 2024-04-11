#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <string>
#include <vector>

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

int ans, n;
vi cur;
char ops[1024][1024];

bool search(int cop) {
  if (cur[sz(cur) - 1] == n) return true;
  if (cop >= ans) return false;

  for (int a = -1; a < sz(cur); a++) {
    for (int b = 0; b < sz(cur); b++) {
      for (int k = 1; k <= 8; k *= 2) {
        int nv = (a >= 0 ? cur[a] : 0) + cur[b] * k;
        if (nv > n) continue;
        cur.pb(nv);
        if (search(cop + 1)) {
          if (a < 0)
            snprintf(ops[cop], sizeof ops[cop], "lea e%cx, [%d*e%cx]", 'a' + cop + 1, k, 'a' + b);
          else
            snprintf(ops[cop], sizeof ops[cop], "lea e%cx, [e%cx + %d*e%cx]", 'a' + cop + 1, 'a' + a, k, 'a' + b);
          return true;
        }
        cur.resize(sz(cur) - 1);
      }
    }
  }
  return false;
}

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  while (scanf("%d", &n) >= 1) {
    eprintf("%d\n", n);
    cur = vi(1, 1);
    for (ans = 0;; ans++)
      if (search(0)) {
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++)
          printf("%s\n", ops[i]);
        break;
      }

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}