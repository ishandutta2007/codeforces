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

char buf[1024];
int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int n, p1, p2;
  while (scanf("%d%d%d", &n, &p1, &p2) >= 1) {
    p1--, p2--;
    scanf("%s", buf);
    scanf("%s", buf);
    int d = !strcmp(buf, "head") ? -1 : 1;
    scanf("%s", buf);

    if (p2 + d < 0 || p2 + d >= n) d = -d;

    try {
      for (int i = 0; buf[i]; i++) {
        eprintf("i=%d, p1=%d, p2=%d\n", i, p1, p2);
        if (buf[i] == '0') { // Moving
          pii cact(abs(p1 - p2), 0);
          if (p1 > 0) cact = max(cact, mp(abs(p1 - 1 - p2), -1));
          if (p1 + 1 < n) cact = max(cact, mp(abs(p1 + 1 - p2), +1));
          p1 += cact.second;

          if (p1 == p2) throw i;

          p2 += d;
          if (p2 + d < 0 || p2 + d >= n) d = -d;
          if (p1 == p2) throw i;
        } else {
          p2 += d;
          if (p2 + d < 0 || p2 + d >= n) d = -d;

          p1 = p2 - d;
          if (p1 < 0 || p1 >= n) {
            p1 = n - 1 - p2;
          }
        }
      }

      printf("Stowaway\n");
    } catch (int x) {
      printf("Controller %d\n", x + 1);
    }
    eprintf("\n");

    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}