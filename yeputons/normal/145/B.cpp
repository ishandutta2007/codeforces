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

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int a1, a2, a3, a4;
  while (scanf("%d%d%d%d", &a1, &a2, &a3, &a4) >= 1) { 
    bool g = false;

    int cnt = a3 + a4 + 1;
    if (a3 - 1 == a4 || a3 == a4) {
      int rem[2] = { a1 - (cnt + 1) / 2, a2 - cnt / 2 };
      if (rem[0] >= 0 && rem[1] >= 0) {
        for (int i = 0; i < cnt; i++) {
          int crem = 0;
          if ((i & 1) == 0) {
            crem = rem[i & 1];
            rem[i & 1] = 0;
          } else {
            if (i + 2 >= cnt) crem = rem[i & 1];
          }
          for (int i2 = 0; i2 <= crem; i2++)
            printf("%c", "47"[i & 1]);
        }
        printf("\n");
        g = true;
      }
    }
    if (!g && (a4 - 1 == a3 || a3 == a4)) {
      int rem[2] = { a2 - (cnt + 1) / 2, a1 - cnt / 2 };
      if (rem[0] >= 0 && rem[1] >= 0) {
        for (int i = 0; i < cnt; i++) {
          int crem = 0;
          if ((i & 1) == 1) {
            crem = rem[i & 1];
            rem[i & 1] = 0;
          } else {
            if (i + 2 >= cnt) crem = rem[i & 1];
          }

          for (int i2 = 0; i2 <= crem; i2++)
            printf("%c", "74"[i & 1]);
        }
        printf("\n");
        g = true;
      }
    } 
    if (!g)
      printf("-1\n");
  }
  return 0;
}