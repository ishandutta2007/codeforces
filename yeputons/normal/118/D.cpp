#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cmath>
#include <cctype>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>

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

const int MOD = 1e8;
void add(int &a, int b) {
   a += b;
   if (a >= MOD) a -= MOD;
}

int d[101][101][11][11];

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif
  
  int n1, n2, k1, k2;
  while (scanf("%d%d%d%d", &n1, &n2, &k1, &k2) >= 1) {
    k1++, k2++;
    memset(d, 0, sizeof d);
    for (int a = 0; a < k1; a++)
    for (int b = 0; b < k2; b++)
      d[0][0][a][b] = 1;

    for (int i = 0; i <= n1; i++)
    for (int j = 0; j <= n2; j++) if (i || j) {
      for (int a = 0; a < k1; a++)
      for (int b = 0; b < k2; b++) {
        int &cur = d[i][j][a][b];
        if (i && a + 1 < k1)
          add(cur, d[i - 1][j][a + 1][0]);
        if (j && b + 1 < k2)
          add(cur, d[i][j - 1][0][b + 1]);
      }
    }

    printf("%d\n", d[n1][n2][0][0]);
  
    #ifndef DEBUG
    break;
    #endif
  }
  return 0;
}