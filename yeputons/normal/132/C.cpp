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

char ops[200];
const int MAXN = 100;
const int MAXK = 50;

int d[MAXN + 1][2 * MAXN + 1][2][MAXK + 1];
const int dx[] = { -1, 1 };

int main() {
  #ifdef DEBUG
  freopen("std.in", "r", stdin);
  freopen("std.out", "w", stdout);
  #endif

  int k;
  while (scanf("%s%d", ops, &k) >= 1) {
    int n = strlen(ops);
    memset(d, -1, sizeof d);

    int st = n;
    int maxc = 2 * n + 1;
    for (int i = 0; i < maxc; i++)
      d[n][i][0][0] = d[n][i][1][0] = abs(st - i);

    for (int i = n - 1; i >= 0; i--)
    for (int pos = 0; pos < maxc; pos++)
    for (int dir = 0; dir < 2; dir++)
    for (int rem = k; rem >= 0; rem--) {
      int &cur = d[i][pos][dir][rem];

      for (int ch = 0; ch <= rem; ch++) {
        int nop = (ops[i] == 'T') ^ (ch & 1);
        if (!nop) {
          cur = max(cur, d[i + 1][pos + dx[dir]][dir][rem - ch]);
        } else {
          cur = max(cur, d[i + 1][pos][!dir][rem - ch]);
        }
      }
    }
    printf("%d\n", d[0][st][0][k]);
  }
  return 0;
}