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

  int n;
  while (scanf("%d", &n) >= 1) {
    for (int len = n; len >= 1; len--) {
      if (len * (len - 1) / 2 <= n) {
        printf("%d\n", len);
        vvi res(len);
        int id = 0;
        for (int a = 0; a + 1 < len; a++)
          for (int b = a + 1; b < len; b++) {
            res[a].pb(id);
            res[b].pb(id);
            id++;
          }

        for (int i = 0; i < len; i++) {
          for (int i2 = 0; i2 < sz(res[i]); i2++)
            printf("%d%c", res[i][i2] + 1, "\n "[i2 + 1 < sz(res[i])]);
        }
        break;
      }
    }
  }
  return 0;
}